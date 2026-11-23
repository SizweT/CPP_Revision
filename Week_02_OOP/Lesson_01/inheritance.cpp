#include <iostream>
#include <string>
using namespace std;

class Employee{
    protected:
        string name;
        int employeeID;
        double salary;

    public:
        Employee(const string &n, int id, double s): name(n), employeeID(id), salary(s) {}

        void displayEmployee() const {
            cout << "Employee Name: " << name << endl;
            cout << "Employee ID: " << employeeID << endl;
            cout << "Salary: R" << salary << endl;
        }

};

class Lecturer : public Employee {
    private:
        string subject;

    public:
        Lecturer(const string &n, int id, double s, const string &sub) : Employee(n, id, s), subject(sub) {}

        void displayLecturer() const {
            displayEmployee();
            cout << "Subject : " << subject << endl;
            cout <<"\n------------------------------------------------\n";
        }
};

class Administrator : public Employee {
    private:
        string department;
    public:
        Administrator(const string &n, int id, double s, const string &dept) : Employee(n, id, s), department(dept) {}
        void displayAdministrator() const {
            displayEmployee();
            cout << "Department: " << department << endl;
            cout <<"\n------------------------------------------------\n";
        }
};

int main() {
    Lecturer lecturer("Dr. Smith", 12345, 75000.00, "Computer Science");
    Administrator administrator("Mr. Johnson", 67890, 80000.00, "Human Resources");
    lecturer.displayLecturer();
    administrator.displayAdministrator();
    return 0;
}   
