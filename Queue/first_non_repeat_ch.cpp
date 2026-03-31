#include<bits/stdc++.h>
using namespace std;

int main() {
    string str = "aabccxb";

    queue<char> Q;
    int freq[26] = {0};

    for(int i=0;i<str.size();i++)
    {
        char ch = str[i];
        freq[ch-'a']++;
        Q.push(ch);
        while(!Q.empty() && freq[Q.front()-'a']>1)
        {
            Q.pop();
        }
        if(Q.empty())
        {
            for(int j=0;j<=i;j++)
            {
                cout<<str[j];
            }
            cout<<": -1"<<endl;
        }
        else
        {
            for(int j=0;j<=i;j++)
            {
                cout<<str[j];
            }
            cout<<": "<<Q.front()<<endl;
        }
    }
    return 0;
}