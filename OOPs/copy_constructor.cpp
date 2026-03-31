#include <iostream>
#include <string>
using namespace std;

class Car {
public:
    string brand;
    int speed;
    int *mileage;

    // 🧱 Normal constructor
    Car(string b, int s) {
        brand = b;
        speed = s;
        mileage = new int;
        *mileage = 12;
    }

    // 🧬 Copy constructor
    // Car(const Car &obj) {
    //     cout << "Copy constructor called!\n";
    //     brand = obj.brand;
    //     speed = obj.speed;
    //     mileage = obj.mileage;
    // }

    void show() {
        cout << "Brand: " << brand << ", Speed: " << speed << " km/h" <<", mileage: "<<*mileage<<endl;
    }
};

int main() {
    Car c1("BMW", 200);   // normal constructor called
    Car c2 = c1;          // copy constructor called (creates a copy of c1)
    
    cout << "Car 1 -> ";
    c1.show();
    cout << "Car 2 -> ";
    c2.show();

    *c2.mileage = 10;

    cout<<*c1.mileage<<endl;

    return 0;
}
