#include <iostream>
using namespace std;

// Base class
class Person {
public:
    string name;
    int age;

    // Constructor
    Person(string n, int a) {
        name = n;
        age = a;
    }
};

// Derived class
class Student : public Person {
public:
    string studentID;

    // Constructor using initializer list to call base class constructor
    Student(string n, int a, string sID) : Person(n, a) {
        studentID = sID;
    }

    // Method to display student info
    void displayStudentInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Student ID: " << studentID << endl;
    }
};

int main() {
    // Create a Student object
    Student student("Alice", 20, "S12345");

    // Display all details
    student.displayStudentInfo();

    return 0;
}
