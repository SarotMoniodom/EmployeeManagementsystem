#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

using namespace std;

class UserAccount {
    public:

    string username;
    string password;
    
    //constructors
    UserAccount() {
        this->username = "Unknown";
        this->password = "Unknown";
    };

    UserAccount(string username, string password) {
        this->setUsername(username);
        this->setPassword(password);
    };

    //setter & getter
    string getUsername() const {
        return username;
    }

    void setUsername(const string username) {
        if (!username.empty())
            this->username = username;
        else
            cout << "Invalid username" << endl;
    }

    string getPassword() const {
        return password;
    }

    void setPassword(const string password){
        if (!password.empty())
            this->password = password;
        else
            cout << "Invalid password" << endl;
    }
};