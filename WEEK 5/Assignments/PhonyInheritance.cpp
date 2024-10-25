#include<iostream>
using namespace std;

class Contact {
    private:
        int phone_number;
        string email;
    public:
        Contact(int phone_number_, string email_) : phone_number(phone_number_), 
                                                      email(email_){}
        void displayContact(){
            cout << "Phone: " << phone_number << endl;
            cout << "Email: " << email << endl;
        }
};

class Employee : private Contact {
    private:
        int emp_id;
        string emp_name;
    public:
        Employee(int emp_id_, string emp_name_, int phone_number_, string email_) 
                        : emp_id(emp_id_), emp_name(emp_name_), Contact(phone_number_, email_){}    // LINE-1
  		
        using Contact::displayContact;
        // LINE-2
        void display(){
            cout << "ID: " << emp_id << endl;
            cout << "Name: " << emp_name << endl;
        }
};
int main() {
    int id, phone;
    string name, email;
    // cin >> id >> name;
    // cin >> phone >> email;

    Employee e(101, "Bob", 12345, "mail");
    e.display();
    e.displayContact();
    return 0;
}