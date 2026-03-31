#include<iostream>
using namespace std;

class A{
    string secret = "keep secret";
    friend class B;
    friend void revealsecret(A &obj);
};

class B{
    public:
    void showsecret(A &obj)
    {
        cout<<obj.secret<<endl;
    }
};

void revealsecret(A &obj)
{
    cout<<obj.secret<<endl;
}

int main() {
    A c1;
    B c2;

    c2.showsecret(c1);

    revealsecret(c1);

    return 0;
}