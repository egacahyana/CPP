#define WIN32_LEAN_AND_MEAN
#define NOMINMAX

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <cstring>

#ifdef _WIN32
    #include <windows.h>
#endif

#include <sql.h>
#include <sqlext.h>

#ifdef _MSC_VER
    #pragma comment(lib, "odbc32.lib")
#endif

using namespace std;

struct Mahasiswa {
    string username;
    string nama;
    string nim;
};

class Database {
private:
    SQLHENV hEnv = SQL_NULL_HENV;
    SQLHDBC hDbc = SQL_NULL_HDBC;
    string connectionString;
    bool connected = false;

    void printError(SQLSMALLINT handleType, SQLHANDLE handle, const string& context = "") {
        if (!context.empty()) cerr << "[ERROR] " << context << endl;

        SQLCHAR     sqlState[6];
        SQLCHAR     message[1024];
        SQLINTEGER  nativeError;
        SQLSMALLINT textLength;
        SQLSMALLINT recNumber = 1;
        SQLRETURN   ret;

        while ((ret = SQLGetDiagRecA(handleType, handle, recNumber,
                                     sqlState, &nativeError,
                                     message, sizeof(message), &textLength))
                == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO) {
            cerr << "  SQLSTATE    : " << sqlState << endl;
            cerr << "  NativeError : " << nativeError << endl;
            cerr << "  Message     : " << message << endl;
            recNumber++;
        }
    }

public:
    Database() {
        // =========================================================
        // KONFIGURASI KONEKSI
        // Jika koneksi gagal, coba ubah bagian ini.
        // =========================================================
        connectionString =
            "Driver={ODBC Driver 18 for SQL Server};"
            "Server=localhost;"
            "Database=DbMahasiswa;"
            "Trusted_Connection=yes;" // Menggunakan Windows Authentication
            "Encrypt=yes;"
            "TrustServerCertificate=yes;";
            
        // OPSI ALTERNATIF (Jika Windows Auth gagal):
        // Hapus komentar pada kode di bawah ini dan sesuaikan password-nya
        /*
        connectionString =
            "Driver={ODBC Driver 18 for SQL Server};"
            "Server=localhost;"
            "Database=DbMahasiswa;"
            "UID=sa;"
            "PWD=PasswordSQLServerAnda;"
            "Encrypt=yes;"
            "TrustServerCertificate=yes;";
        */
    }

    ~Database() {
        disconnect();
    }

    bool connect() {
        SQLRETURN ret = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
        if (ret != SQL_SUCCESS && ret != SQL_SUCCESS_WITH_INFO) {
            cerr << "Gagal alokasi Environment Handle.\n";
            return false;
        }

        SQLSetEnvAttr(hEnv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0);

        ret = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
        if (ret != SQL_SUCCESS && ret != SQL_SUCCESS_WITH_INFO) {
            printError(SQL_HANDLE_ENV, hEnv, "SQLAllocHandle DBC");
            return false;
        }

        SQLCHAR retConString[1024] = {0};
        SQLSMALLINT outLen = 0;

        ret = SQLDriverConnectA(
            hDbc, NULL,
            (SQLCHAR*)connectionString.c_str(), SQL_NTS,
            retConString, sizeof(retConString), &outLen,
            SQL_DRIVER_NOPROMPT
        );

        if (ret != SQL_SUCCESS && ret != SQL_SUCCESS_WITH_INFO) {
            printError(SQL_HANDLE_DBC, hDbc, "SQLDriverConnect gagal");
            connected = false;
            return false;
        }

        connected = true;
        return true;
    }

    void disconnect() {
        if (hDbc != SQL_NULL_HDBC) {
            SQLDisconnect(hDbc);
            SQLFreeHandle(SQL_HANDLE_DBC, hDbc);
            hDbc = SQL_NULL_HDBC;
        }
        if (hEnv != SQL_NULL_HENV) {
            SQLFreeHandle(SQL_HANDLE_ENV, hEnv);
            hEnv = SQL_NULL_HENV;
        }
        connected = false;
    }

    bool executeNonQuery(const string& query, const vector<string>& params) {
        SQLHSTMT hStmt = SQL_NULL_HSTMT;
        SQLRETURN ret = SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt);
        if (ret != SQL_SUCCESS && ret != SQL_SUCCESS_WITH_INFO) return false;

        ret = SQLPrepareA(hStmt, (SQLCHAR*)query.c_str(), SQL_NTS);
        if (ret != SQL_SUCCESS && ret != SQL_SUCCESS_WITH_INFO) {
            printError(SQL_HANDLE_STMT, hStmt, "SQLPrepare");
            SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
            return false;
        }

        vector<SQLLEN> paramLen(params.size(), SQL_NTS);
        for (size_t i = 0; i < params.size() && i < 32; i++) {
            SQLULEN colSize = (SQLULEN)(params[i].size() > 0 ? params[i].size() : 1);
            SQLLEN  bufSize = (SQLLEN)(params[i].size() + 1);
            ret = SQLBindParameter(hStmt, (SQLUSMALLINT)(i + 1), SQL_PARAM_INPUT,
                                   SQL_C_CHAR, SQL_VARCHAR, colSize, 0,
                                   (SQLPOINTER)params[i].c_str(), bufSize, &paramLen[i]);
            if (ret != SQL_SUCCESS && ret != SQL_SUCCESS_WITH_INFO) {
                printError(SQL_HANDLE_STMT, hStmt, "SQLBindParameter");
                SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
                return false;
            }
        }

        ret = SQLExecute(hStmt);
        bool ok = (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO || ret == SQL_NO_DATA);
        if (!ok) printError(SQL_HANDLE_STMT, hStmt, "SQLExecute");

        SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
        return ok;
    }

    bool executeSelect(const string& query, vector<Mahasiswa>& hasil) {
        SQLHSTMT hStmt = SQL_NULL_HSTMT;
        SQLRETURN ret = SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt);
        if (ret != SQL_SUCCESS && ret != SQL_SUCCESS_WITH_INFO) return false;

        ret = SQLExecDirectA(hStmt, (SQLCHAR*)query.c_str(), SQL_NTS);
        if (ret != SQL_SUCCESS && ret != SQL_SUCCESS_WITH_INFO) {
            printError(SQL_HANDLE_STMT, hStmt, "SQLExecDirect");
            SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
            return false;
        }

        SQLCHAR bufU[128] = {0}, bufN[256] = {0}, bufNi[64] = {0};
        SQLLEN lenU = 0, lenN = 0, lenNi = 0;

        SQLBindCol(hStmt, 1, SQL_C_CHAR, bufU,  sizeof(bufU),  &lenU);
        SQLBindCol(hStmt, 2, SQL_C_CHAR, bufN,  sizeof(bufN),  &lenN);
        SQLBindCol(hStmt, 3, SQL_C_CHAR, bufNi, sizeof(bufNi), &lenNi);

        SQLRETURN fetchRet;
        while ((fetchRet = SQLFetch(hStmt)) != SQL_NO_DATA) {
            if (fetchRet == SQL_SUCCESS || fetchRet == SQL_SUCCESS_WITH_INFO) {
                Mahasiswa m;
                m.username = (lenU  == SQL_NULL_DATA) ? "" : (char*)bufU;
                m.nama     = (lenN  == SQL_NULL_DATA) ? "" : (char*)bufN;
                m.nim      = (lenNi == SQL_NULL_DATA) ? "" : (char*)bufNi;
                hasil.push_back(m);
            } else {
                printError(SQL_HANDLE_STMT, hStmt, "SQLFetch");
                break;
            }
        }

        SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
        return true;
    }

    bool executeSelectParam(const string& query, const string& param, vector<Mahasiswa>& hasil) {
        SQLHSTMT hStmt = SQL_NULL_HSTMT;
        SQLRETURN ret = SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt);
        if (ret != SQL_SUCCESS && ret != SQL_SUCCESS_WITH_INFO) return false;

        ret = SQLPrepareA(hStmt, (SQLCHAR*)query.c_str(), SQL_NTS);
        if (ret != SQL_SUCCESS && ret != SQL_SUCCESS_WITH_INFO) {
            printError(SQL_HANDLE_STMT, hStmt, "SQLPrepare");
            SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
            return false;
        }

        SQLULEN colSize = (SQLULEN)(param.size() > 0 ? param.size() : 1);
        SQLLEN  bufSize = (SQLLEN)(param.size() + 1);
        SQLLEN  paramLen = SQL_NTS;

        ret = SQLBindParameter(hStmt, 1, SQL_PARAM_INPUT,
                               SQL_C_CHAR, SQL_VARCHAR, colSize, 0,
                               (SQLPOINTER)param.c_str(), bufSize, &paramLen);
        if (ret != SQL_SUCCESS && ret != SQL_SUCCESS_WITH_INFO) {
            printError(SQL_HANDLE_STMT, hStmt, "SQLBindParameter");
            SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
            return false;
        }

        ret = SQLExecute(hStmt);
        if (ret != SQL_SUCCESS && ret != SQL_SUCCESS_WITH_INFO) {
            printError(SQL_HANDLE_STMT, hStmt, "SQLExecute");
            SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
            return false;
        }

        SQLCHAR bufU[128] = {0}, bufN[256] = {0}, bufNi[64] = {0};
        SQLLEN lenU = 0, lenN = 0, lenNi = 0;
        SQLBindCol(hStmt, 1, SQL_C_CHAR, bufU,  sizeof(bufU),  &lenU);
        SQLBindCol(hStmt, 2, SQL_C_CHAR, bufN,  sizeof(bufN),  &lenN);
        SQLBindCol(hStmt, 3, SQL_C_CHAR, bufNi, sizeof(bufNi), &lenNi);

        SQLRETURN fetchRet;
        while ((fetchRet = SQLFetch(hStmt)) != SQL_NO_DATA) {
            if (fetchRet == SQL_SUCCESS || fetchRet == SQL_SUCCESS_WITH_INFO) {
                Mahasiswa m;
                m.username = (lenU  == SQL_NULL_DATA) ? "" : (char*)bufU;
                m.nama     = (lenN  == SQL_NULL_DATA) ? "" : (char*)bufN;
                m.nim      = (lenNi == SQL_NULL_DATA) ? "" : (char*)bufNi;
                hasil.push_back(m);
            } else {
                printError(SQL_HANDLE_STMT, hStmt, "SQLFetch");
                break;
            }
        }

        SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
        return true;
    }

    int selectCount(const string& query, const vector<string>& params) {
        SQLHSTMT hStmt = SQL_NULL_HSTMT;
        SQLRETURN ret = SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt);
        if (ret != SQL_SUCCESS && ret != SQL_SUCCESS_WITH_INFO) return -1;

        ret = SQLPrepareA(hStmt, (SQLCHAR*)query.c_str(), SQL_NTS);
        if (ret != SQL_SUCCESS && ret != SQL_SUCCESS_WITH_INFO) {
            printError(SQL_HANDLE_STMT, hStmt, "SQLPrepare");
            SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
            return -1;
        }

        vector<SQLLEN> paramLen(params.size(), SQL_NTS);
        for (size_t i = 0; i < params.size() && i < 32; i++) {
            SQLULEN colSize = (SQLULEN)(params[i].size() > 0 ? params[i].size() : 1);
            SQLLEN  bufSize = (SQLLEN)(params[i].size() + 1);

            ret = SQLBindParameter(hStmt, (SQLUSMALLINT)(i + 1), SQL_PARAM_INPUT,
                                   SQL_C_CHAR, SQL_VARCHAR, colSize, 0,
                                   (SQLPOINTER)params[i].c_str(), bufSize, &paramLen[i]);
            if (ret != SQL_SUCCESS && ret != SQL_SUCCESS_WITH_INFO) {
                printError(SQL_HANDLE_STMT, hStmt, "SQLBindParameter");
                SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
                return -1;
            }
        }

        ret = SQLExecute(hStmt);
        if (ret != SQL_SUCCESS && ret != SQL_SUCCESS_WITH_INFO) {
            printError(SQL_HANDLE_STMT, hStmt, "SQLExecute");
            SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
            return -1;
        }

        int    count = 0;
        SQLLEN len   = 0;
        SQLBindCol(hStmt, 1, SQL_C_LONG, &count, 0, &len);

        ret = SQLFetch(hStmt);
        if (ret != SQL_SUCCESS && ret != SQL_SUCCESS_WITH_INFO) count = 0;

        SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
        return count;
    }
};

class User {
private:
    Database& db;

    void clearscreen() {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
    }

    void timer(int detik) {
        for (int i = detik; i > 0; i--) {
            cout << "\rSilahkan tunggu: " << i << " detik... " << flush;
            this_thread::sleep_for(chrono::seconds(1));
        }
        cout << "\r" << string(40, ' ') << "\r";
    }

public:
    User(Database& database) : db(database) {}

    bool prosesLogin() {
        string username, password;
        const int MAKS_PERCOBAAN = 3;

        for (int percobaan = 1; percobaan <= MAKS_PERCOBAAN; percobaan++) {
            cout << "=== SISTEM LOGIN ===\n";
            cout << "Username: ";
            cin >> username;
            cout << "Password: ";
            cin >> password;

            // QUERY UNTUK LOGIN MENGGUNAKAN TABEL USERS
            string query = "SELECT COUNT(*) FROM dbo.Users WHERE Username = ? AND Password = ?";
            int count = db.selectCount(query, {username, password});

            if (count > 0) {
                cout << "Login berhasil!\n";
                return true;
            }

            if (count < 0) {
                cout << "Gagal mengakses database. Periksa koneksi atau nama tabel.\n";
                return false;
            }

            cout << "Username atau password salah!\n";
            if (percobaan < MAKS_PERCOBAAN) {
                cout << "Sisa percobaan: " << MAKS_PERCOBAAN - percobaan << endl;
                timer(3);
                clearscreen();
            }
        }

        cout << "Akun diblokir untuk sesi ini.\n";
        return false;
    }
};

class DataMahasiswa {
private:
    Database& db;

public:
    DataMahasiswa(Database& database) : db(database) {}

    void inputData() {
        Mahasiswa m;
        cout << "\n=== INPUT DATA MAHASISWA ===\n";
        cout << "Username mahasiswa: ";
        cin >> m.username;

        if (db.selectCount("SELECT COUNT(*) FROM Mahasiswa WHERE Username = ?", {m.username}) > 0) {
            cout << "Username sudah digunakan!\n";
            return;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Nama mahasiswa: ";
        getline(cin, m.nama);

        if (m.nama.empty()) {
            cout << "Nama tidak boleh kosong!\n";
            return;
        }

        cout << "NIM mahasiswa: ";
        getline(cin, m.nim);

        if (m.nim.empty()) {
            cout << "NIM tidak boleh kosong!\n";
            return;
        }

        if (db.selectCount("SELECT COUNT(*) FROM Mahasiswa WHERE NIM = ?", {m.nim}) > 0) {
            cout << "NIM sudah digunakan!\n";
            return;
        }

        string query = "INSERT INTO Mahasiswa (Username, Nama, NIM) VALUES (?, ?, ?)";
        if (db.executeNonQuery(query, {m.username, m.nama, m.nim})) {
            cout << "Data berhasil disimpan ke SQL Server.\n";
        } else {
            cout << "Gagal menyimpan data ke SQL Server.\n";
        }
    }

    void lihatData() {
        cout << "\n=== DATA MAHASISWA ===\n";
        vector<Mahasiswa> hasil;
        if (!db.executeSelect("SELECT Username, Nama, NIM FROM Mahasiswa", hasil)) {
            cout << "Gagal mengambil data.\n";
            return;
        }

        if (hasil.empty()) {
            cout << "Belum ada data mahasiswa.\n";
            return;
        }

        for (size_t i = 0; i < hasil.size(); i++) {
            cout << "\nData ke-" << i + 1 << endl;
            cout << "Username: " << hasil[i].username << endl;
            cout << "Nama    : " << hasil[i].nama << endl;
            cout << "NIM     : " << hasil[i].nim << endl;
        }
    }

    void sortingData() {
        if (db.selectCount("SELECT COUNT(*) FROM Mahasiswa", {}) == 0) {
            cout << "Belum ada data untuk diurutkan.\n";
            return;
        }

        int pilihan;
        cout << "\n=== SORTING USERNAME ===\n";
        cout << "1. Ascending (A-Z)\n";
        cout << "2. Descending (Z-A)\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        string query;
        if (pilihan == 1) {
            query = "SELECT Username, Nama, NIM FROM Mahasiswa ORDER BY Username ASC";
        } else if (pilihan == 2) {
            query = "SELECT Username, Nama, NIM FROM Mahasiswa ORDER BY Username DESC";
        } else {
            cout << "Pilihan tidak valid.\n";
            return;
        }

        vector<Mahasiswa> hasil;
        if (!db.executeSelect(query, hasil)) {
            cout << "Gagal melakukan sorting.\n";
            return;
        }

        cout << "\n=== DATA SETELAH SORTING ===\n";
        for (size_t i = 0; i < hasil.size(); i++) {
            cout << "\nData ke-" << i + 1 << endl;
            cout << "Username: " << hasil[i].username << endl;
            cout << "Nama    : " << hasil[i].nama << endl;
            cout << "NIM     : " << hasil[i].nim << endl;
        }
    }

    void linearSearching() {
        if (db.selectCount("SELECT COUNT(*) FROM Mahasiswa", {}) == 0) {
            cout << "Belum ada data untuk dicari.\n";
            return;
        }

        string cari;
        cout << "\n=== PENCARIAN USERNAME ===\n";
        cout << "Masukkan username yang dicari: ";
        cin >> cari;

        vector<Mahasiswa> hasil;
        string query = "SELECT Username, Nama, NIM FROM Mahasiswa WHERE Username = ?";
        if (!db.executeSelectParam(query, cari, hasil)) {
            cout << "Gagal melakukan pencarian.\n";
            return;
        }

        if (hasil.empty()) {
            cout << "Username tidak ditemukan.\n";
            return;
        }

        cout << "\nData ditemukan!\n";
        cout << "Username: " << hasil[0].username << endl;
        cout << "Nama    : " << hasil[0].nama << endl;
        cout << "NIM     : " << hasil[0].nim << endl;
    }

    void deleteData() {
        if (db.selectCount("SELECT COUNT(*) FROM Mahasiswa", {}) == 0) {
            cout << "Belum ada data untuk dihapus.\n";
            return;
        }

        string nimHapus;
        cout << "\n=== HAPUS DATA MAHASISWA ===\n";
        cout << "Masukkan NIM yang ingin dihapus: ";
        cin >> nimHapus;

        vector<Mahasiswa> hasil;
        if (!db.executeSelectParam(
                "SELECT Username, Nama, NIM FROM Mahasiswa WHERE NIM = ?",
                nimHapus, hasil)) {
            cout << "Gagal mengakses database.\n";
            return;
        }

        if (hasil.empty()) {
            cout << "NIM tidak ditemukan.\n";
            return;
        }

        cout << "\nData ditemukan:\n";
        cout << "Username: " << hasil[0].username << endl;
        cout << "Nama    : " << hasil[0].nama << endl;
        cout << "NIM     : " << hasil[0].nim << endl;

        char konfirmasi;
        cout << "\nYakin ingin menghapus? (y/n): ";
        cin >> konfirmasi;

        if (konfirmasi == 'y' || konfirmasi == 'Y') {
            string query = "DELETE FROM Mahasiswa WHERE NIM = ?";
            if (db.executeNonQuery(query, {nimHapus})) {
                cout << "Data berhasil dihapus.\n";
            } else {
                cout << "Gagal menghapus data.\n";
            }
        } else {
            cout << "Penghapusan dibatalkan.\n";
        }
    }
};

int main() {
    Database db;
    cout << "Menghubungkan ke SQL Server...\n";
    if (!db.connect()) {
        cerr << "\nGagal terhubung ke SQL Server.\n";
        return 1;
    }
    cout << "Berhasil terhubung ke SQL Server!\n\n";

    User user1(db);
    if (!user1.prosesLogin()) {
        cout << "Silakan hubungi admin.\n";
        return 0;
    }

    DataMahasiswa mahasiswa(db);
    int pilihan;

    do {
        cout << "\n=== MENU UTAMA ===\n";
        cout << "1. Input data Mahasiswa\n";
        cout << "2. Lihat data Mahasiswa\n";
        cout << "3. Hapus data Mahasiswa\n";
        cout << "4. Sorting data\n";
        cout << "5. Pencarian Username\n";
        cout << "6. Exit\n";
        cout << "Masukkan pilihan: ";

        if (!(cin >> pilihan)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input harus berupa angka!\n";
            continue;
        }

        
        switch (pilihan) {
            case 1: mahasiswa.inputData(); break;
            case 2: mahasiswa.lihatData(); break;
            case 3: mahasiswa.deleteData(); break;
            case 4: mahasiswa.sortingData(); break;
            case 5: mahasiswa.linearSearching(); break;
            case 6: cout << "Program selesai.\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 6);

    return 0;
}