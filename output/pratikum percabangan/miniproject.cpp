#include<iostream>
using namespace std;

class users{
    private:
        string nama;
        int password;
        string email;
        bool loginStatus;

    public:
        users(string inputUsername, int inputPassword, string inputEmail){
            nama = inputUsername;
            password = inputPassword;
            email = inputEmail;
            loginStatus = false;
        }
    
    void tampikanData(){
        cout << "Nama: " << nama << endl;
        cout << "Password: " << password << endl;
        cout << "Email: " << email << endl;
        cout << "Login Status: " << (loginStatus ? "Logged In" : "Not Logged In") << endl;
    }

    bool login(string inputUsername, int inputPassword){
        if (inputUsername == nama && inputPassword == password) {
            cout << "Login successful!" << endl;
            loginStatus = true;
            return true;
        } else {
            cout << "Login failed!" << endl;
            return false;
        }
    }
};

int main(){
users user1("Ega Cahyana", 123456, "ega.cahyana@example.com");
user1.tampikanData();
user1.login("Ega Cahyana", 123456);
user1.tampikanData();
return 0;
}