#include<iostream>
#include<string>
using namespace std;

void Subset(string str,string subset)
{
    if(str.size() == 0)
    {
        cout<<subset<<endl;
        return;
    }

    char ch = str[0];
    Subset(str.substr(1,str.size()-1), subset + ch);
    Subset(str.substr(1,str.size()-1), subset);
}

int main() {
    string str = "abc";
    string subset;

    Subset(str,subset);

    return 0;
}