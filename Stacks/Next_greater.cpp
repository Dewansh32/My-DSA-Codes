#include<bits/stdc++.h>
using namespace std;

void Next_greater(vector<int> list,vector<int> &ans)
{
    stack<int>  s;
    int n = list.size();
    int ls = n-1;
    ans[ls] = -1;
    s.push(ls);

    for(int i=ls-1;i>=0;i--)
    {
        while(!s.empty() && list[i]>=list[s.top()])
        {
            s.pop();
        }
        if(s.empty())
        {
            ans[i] = -1;
        }
        else{
            ans[i] = list[s.top()];
        }

        s.push(i);
    }
}

int main() {
    vector<int> list = {6,8,0,1,3};
    vector<int> ans={0,0,0,0,0};

    Next_greater(list,ans);
    for (int s : ans) cout << s << " ";
    cout << "\n";
    return 0;
}