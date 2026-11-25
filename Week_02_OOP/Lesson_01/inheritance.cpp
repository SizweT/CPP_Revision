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

        virtual void displayRole() const {
            cout <<"I am an employee." << endl;
        }

        virtual ~Employee() = default; // Virtual destructor for proper cleanup of derived classes

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
        void displayRole() const override {
            cout << "I am a lecturer." << endl;
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
        void displayRole() const override {
            cout << "I am an administrator." << endl;
        }
};

class Researcher : public Employee {
    private:
        string researchArea;
    public:
        Researcher(const string &n, int id, double s, const string &area) : Employee(n,id,s), researchArea(area) {}
        void displayRole() const override {
            cout << "I am a researcher." << endl;
        }
};

int main() {
    Lecturer lecturer("Dr. Smith", 12345, 75000.00, "Computer Science");
    Administrator administrator("Mr. Johnson", 67890, 80000.00, "Human Resources");
    Researcher researcher("Dr. Brown", 54321, 90000.00, "Artificial Intelligence");
    
    Employee* employees[] = {&lecturer, &administrator, &researcher};
    
    for (Employee* employee : employees) {
        employee->displayRole();
        cout << "\n------------------------------------------------\n";
    }
    
    return 0;
}   
