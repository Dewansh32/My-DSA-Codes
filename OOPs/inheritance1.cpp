#include <iostream>
using namespace std;

// 🐾 Base Class
class Animal {
public:
    string name;          // 🟢 accessible everywhere
protected:
    int age;              // 🟡 accessible in derived classes
private:
    string speciesType;   // 🔴 accessible only inside Animal

public:
    Animal(string n, int a, string s) {
        name = n;
        age = a;
        speciesType = s;
    }

    void showInfo() {
        cout << "Name: " << name << ", Age: " << age 
             << ", Species: " << speciesType << endl;
    }
};

// 🐟 Derived Class 1 — PUBLIC Inheritance
class Fish_Public : public Animal {
public:
    string waterType;

    Fish_Public(string n, int a, string s, string w) : Animal(n, a, s) {
        waterType = w;
    }

    void details() {
        cout << "\n🟢 Public Inheritance Example:\n";
        cout << "Name: " << name << endl;   // ✅ allowed (public in base)
        cout << "Age: " << age << endl;     // ✅ allowed (protected in base)
        // cout << speciesType; ❌ Not allowed (private in base)
        cout << "Water Type: " << waterType << endl;
    }
};

// 🐠 Derived Class 2 — PROTECTED Inheritance
class Fish_Protected : protected Animal {
public:
    Fish_Protected(string n, int a, string s) : Animal(n, a, s) {}

    void testAccess() {
        cout << "\n🟡 Protected Inheritance Example:\n";
        cout << "Name: " << name << endl;   // ✅ accessible (becomes protected)
        cout << "Age: " << age << endl;     // ✅ accessible
    }
};

// 🦈 Derived Class 3 — PRIVATE Inheritance
class Fish_Private : private Animal {
public:
    Fish_Private(string n, int a, string s) : Animal(n, a, s) {}

    void testAccess() {
        cout << "\n🔴 Private Inheritance Example:\n";
        cout << "Name: " << name << endl;   // ✅ accessible (becomes private)
        cout << "Age: " << age << endl;     // ✅ accessible
    }
};

int main() {
    // -----------------------
    // 🔹 Public Inheritance
    // -----------------------
    Fish_Public fp("Nemo", 2, "Fish", "Salt");
    fp.details();
    cout << fp.name << " is public accessible in main.\n";  // ✅ works

    // -----------------------
    // 🔹 Protected Inheritance
    // -----------------------
    Fish_Protected fpr("Goldie", 1, "Fish");
    fpr.testAccess();
    // fpr.name; ❌ Error: name is protected now

    // -----------------------
    // 🔹 Private Inheritance
    // -----------------------
    Fish_Private fpri("Sharky", 5, "Shark");
    fpri.testAccess();
    // fpri.name; ❌ Error: name is private now

    return 0;
}
