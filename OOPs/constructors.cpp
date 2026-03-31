#include<iostream>
#include<string>
using namespace std;

class car{
    string name;
    string color;

    public:

    car()
    {
        cout<<"Constructor is called\n";
    }

    void start()
    {
        cout<<"car has started"<<endl;
    }
    void stop()
    {
        cout<<"car has stopped"<<endl;
    }

};

int main() {
    car c1;
    

    return 0;
}