#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include "EmployeeManager.cpp" 
#include "Login.cpp"

using namespace std;

class Application {
    private:

    EmployeeManager empManager;

    int getChoice ()
    {
        int choice;

        cout << "\nPlease enter choice: ";
        cin >> choice;

        return choice;
    }

    void pressKeyToContinue () {
        cout << "Press Enter to continue..." << endl;
        cin.get();
        getchar();
    }

    void displayMenu () {
        int choice;

        do {
            cout << " _________________________________" << endl;
            cout << " THE EMPLOYEES MANAGEMENT SYSTEM " << endl;
            cout << " _________________________________\n" << endl;
            cout << "\t\t\tMenu\n" << endl;
            cout << "\t\t1. Add Employees\n" << endl;
            cout << "\t\t2. View Employees\n" << endl;
            cout << "\t\t3. Update Emloyees\n" << endl;
            cout << "\t\t4. Delete Emloyees\n" << endl;
            cout << "\t\t5. Search Emloyees\n" << endl;
            cout << "\t\t6. Sort Emloyees\n" << endl;
            cout << "\t\t7. Save Emloyees\n" << endl;
            cout << "\t\t0. Exit" << endl;

            choice = getChoice();

            switch (choice) {
                case 1:
                    cout << "Add Employee" << endl;
                    empManager.addEmployee();

                    break;
                case 2:
                    cout << "View Employees" << endl;
                    empManager.viewEmployee();

                    break;
                case 3:
                    cout << "1. Update by ID" << endl;
                    cout << "2. Update by Name" << endl;

                    choice = getChoice();

                    switch (choice) {
                        case 1:
                            int id;

                            cout << "Enter ID: ";
                            cin >> id;

                            empManager.updateEmployeeById(id);

                            break;
                        case 2:
                            string name;

                            cout << "Enter name: ";
                            cin >> name;

                            empManager.updateEmployeeByName(name);

                            break;
                    }

                    break;
                case 4:
                    cout << "1. Delete by ID" << endl;
                    cout << "2. Delete by Name" << endl;

                    choice = getChoice();

                    switch (choice) {
                        case 1:
                            int id;

                            cout << "Enter ID: ";
                            cin >> id;

                            empManager.deleteEmployeeById(id);

                            break;
                        case 2:
                            string name;

                            cout << "Enter name: ";
                            cin >> name;

                            empManager.deleteEmployeeByName(name);

                            break;
                    }

                    break;
                case 5:
                    cout << "1. Search by ID" << endl;
                    cout << "2. Search by Name" << endl;

                    choice = getChoice();

                    switch (choice) {
                        case 1:
                            int id;

                            cout << "Enter ID: ";
                            cin >> id;

                            empManager.searchEmployeeById(id);

                            break;
                        case 2:
                            string name;

                            cout << "Enter name: ";
                            cin >> name;

                            empManager.searchEmployeeByName(name);

                            break;
                    }

                    break;
                case 6:
                    cout << "1. Sort by ID" << endl;
                    cout << "2. Sort by Name" << endl;

                    choice = getChoice();

                    switch (choice) {
                        case 1:
                            cout << "1. Ascending" << endl;
                            cout << "2. Descending" << endl;

                            choice = getChoice();

                            empManager.sortEmployeesById(choice);

                            break;
                        case 2:
                            cout << "1. Ascending" << endl;
                            cout << "2. Descending" << endl;

                            choice = getChoice();

                            empManager.sortEmployeesByName(choice);

                            break;
                    }

                    break;
                case 7:
                    cout << "Save Emloyees " << endl;
                    empManager.saveDataIntoFile();
                    break;
                case 0:
                    break;
                default:
                    cout << "Invalid" << endl;
                    break;
            }

            pressKeyToContinue();
        } while (choice != 0);
    }

    public:

    void run() {
        int choice;
        bool flag = false;
        Login login;

        do {
            cout << "____________________________________________________" << endl;
            cout << "Employees Management System" << endl;
            cout << "____________________________________________________\n" << endl;
            cout << "1. Log In\n" << endl;
            cout << "2. Registration\n" << endl;
            cout << "0. Exit\n" << endl;
            cout << "____________________________________________________\n" << endl;
            cout << "Please input your choice here: ";
            cin >> choice;

            cout << "____________________________________________________\n" << endl;

            switch (choice) {
                case 1:
                    flag = login.userLogin();
                    break;
                case 2:
                    login.userRegister();
                    break;
                case 0:
                    break;
                default:
                    cout << "Invalid" << endl;
                    break;
            }

            if (flag)
                break;
        } while (choice != 0);

        if (!flag)
            return;

        empManager.loadDataFromFile();
        displayMenu();
    }
};
