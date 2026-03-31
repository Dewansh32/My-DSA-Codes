#include<iostream>
using namespace std;

int main() {
    string str = "Apna college";
    
    // for with length
    for (int i=0;i<str.length();i++)
    {
        cout<<str[i];
    }
    cout<<endl;

    for(char ch:str)
    {
        cout<<ch;
    }
    
    return 0;
}