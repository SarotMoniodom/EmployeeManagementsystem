#pragma once
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>
#include "Employee.cpp"

using namespace std;

class EmployeeManager {
    private:

    int numberOfEmployees;
    Employee employees[1000];

    int getChoice () {
        int choice;

        cout << "\nPlease enter choice: ";
        cin >> choice;

        return choice;
    }

    int findEmployeesIndexById (int id) {
        for (int i = 0; i < numberOfEmployees; i++) {
            if (employees[i].id == id)
                return i;
        }

        return -1;
    }

    int findEmployeesIndexByName (string name) {
        for (int i = 0; i < numberOfEmployees; i++) {
            if (employees[i].name == name)
                return i;
        }

        return -1;
    }

    void displayEmployee (Employee emp) {
        cout << "\n" << endl;
        cout << "1. ID: " << emp.id << endl;
        cout << "2. Name: " << emp.name << endl;
        cout << "3. Gender: " << emp.gender << endl;
        cout << "4. Position: " << emp.position << endl;
        cout << "5. Contact Number:" << emp.contact << endl;
        cout << "6. Address: " << emp.address << endl;
        cout << "7. Job title: " << emp.jobTitle << endl;
    }

    void updateEmployee (int index) {
        int choice;

        if (index != -1) {
            displayEmployee(employees[index]);
            choice = getChoice();

            switch (choice) {
                case 1:
                    cout << "Enter new ID: ";
                    cin >> employees[index].id;

                    break;
                case 2:
                    cout << "Enter new name: ";
                    cin >> employees[index].name;

                    break;
                case 3:
                    cout << "Enter new gender: ";
                    cin >> employees[index].gender;

                    break;
                case 4:
                    cout << "Enter new position: ";
                    cin >> employees[index].position;

                    break;
                case 5:
                    cout << "Enter new contact number: ";
                    cin >> employees[index].contact;

                    break;
                case 6:
                    cout << "Enter new address: ";
                    cin >> employees[index].address;

                    break;
                case 7:
                    cout << "Enter new job title: ";
                    cin >> employees[index].jobTitle;

                    break;
            }

            cout << "Updated successfully" << endl;
        }
        else {
            cout << "Not found" << endl;
        }
    }

    void deleteEmployee (int index) {
        char ch;

        if (index != -1) {
            displayEmployee(employees[index]);

            cout << "Are you sure to delete? (y/n)";
            cin >> ch;

            if (ch == 'y') {
                for (int j = index; j < numberOfEmployees - 1; j++)
                    employees[j] = employees[j + 1];

                numberOfEmployees--;

                cout << "Deleted successfully" << endl;
            }
        }
        else {
            cout << "Not found" << endl;
        }
    }

    public:

    void addEmployee () {
        cout << "Enter ID: ";
        cin >> employees[numberOfEmployees].id;
        cout << "Enter Name: ";
        cin >> employees[numberOfEmployees].name;
        cout << "Enter gender: ";
        cin >> employees[numberOfEmployees].gender;
        cout << "Enter Position: ";
        cin >> employees[numberOfEmployees].position;
        cout << "Enter Contact Number: ";
        cin >> employees[numberOfEmployees].contact;
        cout << "Enter Address: ";
        cin >> employees[numberOfEmployees].address;
        cout << "Enter job title: ";
        cin >> employees[numberOfEmployees].jobTitle;

        numberOfEmployees++;
    }

    void viewEmployee () {
        for (int i = 0; i < numberOfEmployees; i++) {
            cout << "ID: " << employees[i].id << " | ";
            cout << " Name: " << employees[i].name << " | ";
            cout << " Gender: " << employees[i].gender << " | ";
            cout << " Position: " << employees[i].position << " | ";
            cout << "Contact Number: " << employees[i].contact << " | ";
            cout << "Address: " << employees[i].address << " | ";
            cout << "Job title: " << employees[i].jobTitle << endl;
        }
    }

    void updateEmployeeById (int id) {
        int option;
        int index = findEmployeesIndexById(id);

        updateEmployee(index);
    }

    void updateEmployeeByName (string name) {
        int index = findEmployeesIndexByName(name);

        updateEmployee(index);
    }

    void deleteEmployeeById(int id)
    {
        int option;
        int index = findEmployeesIndexById(id);

        deleteEmployee(index);
    }

    void deleteEmployeeByName(string name)
    {
        int index = findEmployeesIndexByName(name);

        deleteEmployee(index);
    }

    void searchEmployeeById (int id) {
        int index = findEmployeesIndexById(id);

        if (index != -1)
            displayEmployee(employees[index]);
        else
            cout << "Not found" << endl;
    }

    void searchEmployeeByName (string name) {
        int index = findEmployeesIndexByName(name);

        if (index != -1)
            displayEmployee(employees[index]);
        else
            cout << "Not found" << endl;
    }

    void sortEmployeesById (int sortDirection) {
        switch (sortDirection) {
            case 1:
                for (int i = 0; i < numberOfEmployees; i++) {
                    for (int j = 0; j < numberOfEmployees - i - 1; j++) {
                        if (employees[j].id > employees[j + 1].id) {
                            Employee emp;

                            emp = employees[j];
                            employees[j] = employees[j + 1];
                            employees[j + 1] = emp;
                        }
                    }
                }

                break;
            case 2:
                for (int i = 0; i < numberOfEmployees; i++) {
                    for (int j = 0; j < numberOfEmployees - i - 1; j++) {
                        if (employees[j].id < employees[j + 1].id) {
                            Employee emp;

                            emp = employees[j];
                            employees[j] = employees[j + 1];
                            employees[j + 1] = emp;
                        }
                    }
                }

                break;
        }

        cout << "Sorted successfully" << endl;
    }

    void sortEmployeesByName (int sortDirection) {
        switch (sortDirection) {
            case 1:
                for (int i = 0; i < numberOfEmployees; i++) {
                    for (int j = 0; j < numberOfEmployees - i - 1; j++) {
                        if (employees[j].name > employees[j + 1].name) {
                            Employee emp;

                            emp = employees[j];
                            employees[j] = employees[j + 1];
                            employees[j + 1] = emp;
                        }
                    }
                }

                break;
            case 2:
                for (int i = 0; i < numberOfEmployees; i++) {
                    for (int j = 0; j < numberOfEmployees - i - 1; j++) {
                        if (employees[j].name < employees[j + 1].name) {
                            Employee emp;

                            emp = employees[j];
                            employees[j] = employees[j + 1];
                            employees[j + 1] = emp;
                        }
                    }
                }

                break;
        }

        cout << "Sorted successfully" << endl;
    }

    void saveDataIntoFile ()
    {
        ofstream outFile;
        outFile.open("employees.dat", ios::out | ios::trunc | ios::binary);

        for (int i = 0; i < numberOfEmployees; i++)
        {
            Employee empt = employees[i];
            outFile.write(reinterpret_cast<char *>(&empt), sizeof(empt));
        }

        outFile.close();

        cout << "Saved successfully" << endl;
    }

    void loadDataFromFile () {
        Employee empt;
        ifstream inFile;

        numberOfEmployees = 0;

        inFile.open("employees.dat", ios::in);

        while (inFile.read(reinterpret_cast<char *>(&empt), sizeof(empt)))
            employees[numberOfEmployees++] = empt;

        inFile.close();
    }
};

