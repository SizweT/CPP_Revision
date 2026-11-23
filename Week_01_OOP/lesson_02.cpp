
#include <iostream>
#include <string>
using namespace std;

class Student {

private:
    string name;
    int age;
    double averageMark;

public:

    // Default constructor
    Student()
        : name("Unknown"), age(0), averageMark(0.0) {

        cout << "Default constructor called." << endl;
    }

    // Parameterised constructor
    Student(string n, int a, double mark)
        : name(n), age(a), averageMark(0.0) {

        setAverageMark(mark);

        cout << "Parameterised constructor called." << endl;
    }

    // Setters
    void setName(string n) {
        name = n;
    }

    void setAge(int a) {
        if (a >= 0) {
            age = a;
        }
    }

    bool setAverageMark(double mark) {
        if (mark >= 0 && mark <= 100) {
            averageMark = mark;
            return true;
        }

        return false;
    }

    // Getters
    string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    double getAverageMark() const {
        return averageMark;
    }

    // Display method
    void displayInformation() const {
        cout << "\nStudent Information" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Average Mark: " << averageMark << "%" << endl;
    }

    // Destructor
    ~Student() {
        cout << "Student object destroyed: "
             << name << endl;
    }
};

int main() {

    // Creating objects using different constructors
    Student student1;

    Student student2("Thabo", 21, 78.5);

    Student student3("Lerato", 22, 150);

    // Display student information
    student1.displayInformation();
    student2.displayInformation();
    student3.displayInformation();

    // Updating information
    student1.setName("Sizwe");
    student1.setAge(25);
    student1.setAverageMark(90);

    cout << "\nAfter updating student1:" << endl;

    student1.displayInformation();

    return 0;
}
