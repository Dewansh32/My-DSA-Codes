#include<iostream>
using namespace std;

class student{
    string name;
    float cgpa;

    void get_percentage()
    {
        cout<<(cgpa * 100)<<endl;
    }
};

int main() {
    
    return 0;
}