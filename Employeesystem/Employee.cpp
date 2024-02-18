#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string> 

using namespace std;


class Employee {
    public:
        int id;
        string name;
        string gender;
        string position;
        string contact;
        string address;
        string jobTitle;
    
    //constructors
    Employee() {
        this->id = 0;
        this->name = "Unknown";
        this->gender = "Unknown";
        this->position = "Unknown";
        this->contact = "Unknown";
        this->address = "Unknown";
        this->jobTitle = "Unknown";
  };

    Employee(int id, string name, string gender, string position, string contact, string address, string jobTitle) {
        this->setId(id);
        this->setName(name);
        this->setGender(gender);
        this->setPosition(position);
        this->setContact(contact);
        this->setAddress(address);
        this->setJobTitle(jobTitle);
        
 };
    //setter & getter
    int getId() const {
        return id;
    }

    void setId(const int id) {
        if (id >= 0)
            this->id = id;
        else
            cout << "Invalid number" << endl;
    }

    string getName() const {
        return name;
    }

    void setName(const string name) {
        if (!name.empty())
            this->name = name;
        else
            cout << "Invalid name" << endl;
    }
    
    string getGender() const {
        return gender;
    }
    
    void setGender(const string gender) {
        if (!gender.empty())
            this->gender = gender;
        else
            cout << "Invalid gender" << endl;
    }

    string getPosition() const {
        return position;
    }
    
    void setPosition(const string position) {
        if (!position.empty())
            this->position = position;
        else
            cout << "Invalid position" << endl;
    }

    string getContact() const {
        return contact;
    }
    
    void setContact(const string contact) {
        if (!contact.empty())
            this->contact = contact;
        else
            cout << "Invalid contact" << endl;
    }

    string getAddress() const {
        return address;
    }
    
    void setAddress(const string address) {
        if (!address.empty())
            this->address = address;
        else
            cout << "Invalid address" << endl;
    }

    string getJobTitle() const {
        return jobTitle;
    }
    
    void setJobTitle(const string jobTitle) {
        if (!jobTitle.empty())
            this->jobTitle = jobTitle;
        else
            cout << "Invalid job title" << endl;
    }
};