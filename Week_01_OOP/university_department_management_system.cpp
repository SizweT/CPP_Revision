#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Requirements
//Your programme must demonstrate:
//1. Function overloading: create two display() methods with different parameter lists.
//2. Static members: count the number of University objects created.
//3. The this pointer: use it in at least one setter.
//4. Passing objects: pass a Lecturer object by const reference.
//5. Returning objects: write a function that creates and returns a Lecturer.
//6. Composition or aggregation: demonstrate a Department having lecturers.
//Bonus: Explain why you chose composition or aggregation for the Department–Lecturer relationship.

class Lecturer {
    private:
        string name;
        int employeeID;
        double salary;
    public:
        // Default constructor
        Lecturer() : name("Unknown"), employeeID(0), salary(0.0) {}
        // Parameterized constructor
        Lecturer(const string& n, int id, double sal) : name(n), employeeID(id), salary(sal) {}
        // getter methods
        string getName() const {
            return name;
        }
        int getEmployeeID() const {
            return employeeID;
        }
        double getSalary() const {
            return salary;
        }
        // method to display lecturer details using overloading
        void displayInformation() const {
            cout << "Lecturer Name: " << name << endl;
            cout << "Employee ID: " << employeeID << endl;
            cout << "Salary: R" << salary << endl;
        }
        void displayInformation(string title) const {
            cout << title << endl;          
            cout << "Lecturer Name: " << name << endl;
            cout << "Employee ID: " << employeeID << endl;
            cout << "Salary: R" << salary << endl;
        }

};
// A function that takes a Lecturer object by const reference and displays its information
void displayLecturer(const Lecturer& lecturer) {

    lecturer.displayInformation();
}
// A function that creates and returns a Lecturer object
Lecturer createLecturer(string name, int id, double salary) {
    return Lecturer(name, id, salary);
}

class Department {
private:
    string departmentName;

    // Non-owning pointers to independently existing lecturers
    vector<const Lecturer*> lecturers;

public:
    // Parameterized constructor
    Department(const string& name)
        : departmentName(name) {}

    // Add an existing lecturer to the department
    void addLecturer(const Lecturer& lecturer) {
        lecturers.push_back(&lecturer);
    }

    void displayDepartment() const {
        cout << "Department Name: " << departmentName << endl;
        cout << "Lecturers in this department:" << endl;

        for (const Lecturer* lecturer : lecturers) {
            lecturer->displayInformation();
            cout << endl;
        }
    }
};

class University {
    private:
        string universityName;
        static int universityCount; // Static member to count universities
    public:
        // Parameterized constructor
        University(string name) : universityName(name) {
            // Increment the university count when a new university is created
            // Note: In a real implementation, you would need to manage this count properly.
            universityCount++;
            
        }
        // Setter for university name
        void setUniversityName(const string& name) {
            this->universityName = name;
        }
        // Static method to get the count of universities
        static int getUniversityCount() {
            return universityCount;
        }
        // method to display university details
        void displayUniversity() const {
            cout << "University Name: " << universityName << endl;
            cout << "Total Universities Created: " << getUniversityCount() << endl;
        }
};

//count the number of universities created
int University::universityCount = 0;

int main() {

    Lecturer lecturer1 = createLecturer("Dr. Smith", 101, 75000.0);

    Lecturer lecturer2 = createLecturer("Prof. Johnson", 102, 80000.0);

    Department department("Computer Science");

    department.addLecturer(lecturer1);
    department.addLecturer(lecturer2); 

    department.displayDepartment(); 

    return 0;
}