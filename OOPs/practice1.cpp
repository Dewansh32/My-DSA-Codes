#include<iostream>
#include<string>
using namespace std;

class user{
    string id;
    string password;

    public:
    string username;

    user(string id)
    {
        this->id = id;
    }

    void set(string pass)
    {
        password = pass;
    }

    string get()
    {
        return password;
    }
};

int main() {
    user u1("u123");   // constructor called
    u1.username = "Dewansh";
    u1.set("abc123");

    cout << "Username: " << u1.username << endl;
    cout << "Password: " << u1.get() << endl;
    
    return 0;
}