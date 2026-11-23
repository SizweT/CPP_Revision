#include <iostream>
#include <string>
using namespace std;

//creating a class named "student"
class Student {
public:
    //Attributes of the class
    string name;
    int age;
    double averageMarks;

    //method to display student details
    void displayInformation() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Average Marks: " << averageMarks << endl;
    }

};

int main() {
    //creating an object of the class student
    Student student1;
    Student student2;

    //assigning values to the attributes
    student1.name = "Thabo";
    student1.age = 21;
    student1.averageMarks = 78.5;

    //assigning values to the attributes
    student2.name = "Lerato";
    student2.age = 22;
    student2.averageMarks = 85.0;


    //calling the method to display student details
    student1.displayInformation();

    cout << endl; // Adding a line break for better readability

    student2.displayInformation();

    return 0;
}