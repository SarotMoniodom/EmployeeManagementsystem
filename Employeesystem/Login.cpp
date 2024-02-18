#pragma once
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include "UserAccount.cpp"

using namespace std;

class Login {
    private:

    string username;
    string password;
    UserAccount users[1000];
    UserAccount user;

    public:

    bool userLogin () {
        cout << " X=======================================X " << endl;
        cout << "\n\n";
        cout << " X=======================================X " << endl;
        cout << " |              1. Log In                | " << endl;
        cout << " X=======================================X " << endl;
        cout << "Please Enter the username: ";
        cin >> username;
        cout << "Please Enter the password: ";
        cin >> password;

        bool userFound = false;
        int c = 0;
        ifstream inFile;

        inFile.open("users.dat", ios::in);

        while (inFile.read(reinterpret_cast<char *>(&user), sizeof(user)))
            users[c++] = user;

        inFile.close();

        for (int i = 0; i < c; i++) {
            if (users[i].username == username && users[i].password == password) {
                cout << "Welcome to Employee Management System, " << username << endl;
                userFound = true;

                break;
            }
        }

        if (!userFound) {
            cout << " |             USER NOT FOUND            | " << endl; 
            cout << " X=======================================X " << endl;
        }

        return userFound;
    }

    void userRegister () {
        cout << " X=======================================X " << endl;
        cout << "\n\n" ;
        cout << " X=======================================X " << endl;
        cout << " |             2. REGISTER               | " << endl;
        cout << " X=======================================X " << endl;
        cout << "Enter the username: ";
        cin >> user.username;
        cout << "Enter the password: ";
        cin >> user.password;

        if (user.username.length() <= 7 || user.password.length() <= 7) {
            cout << " |  4-digit PIN MUST BE 4 CHARACTERS OR  | " << endl; 
            cout << " | USERNAME AND PASSWORD MUST BE AT LEAST| " << endl; 
            cout << " | 7 CHARACTERS LONG. PLEASE TRY AGAIN.. | " << endl; 
            cout << " X=======================================X\n\n " << endl;
            return;
        }

        ofstream outFile;
        outFile.open("users.dat", ios::out | ios::app | ios::binary);
        outFile.write(reinterpret_cast<char *>(&user), sizeof(user));
        outFile.close();

        cout << " |            USER HAS CREATED           | " << endl;
        cout << " X=======================================X " << endl;
    }
};