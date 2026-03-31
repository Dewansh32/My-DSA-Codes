#include<bits/stdc++.h>
using namespace std;

void permutation(string str,string ans)
{
    if(str.size() == 0)
    {
        cout<<ans<<endl;
        return;
    }
    for(int i=0;i<str.size();i++)
    {
        char c = str[i];
        string rest = str;     // make a copy
        rest.erase(i, 1);      // remove the chosen character
        permutation(rest, ans + c);
    }
}

int main() {
    string str = "abc";
    string ans = "";

    permutation(str,ans);
    return 0;
}