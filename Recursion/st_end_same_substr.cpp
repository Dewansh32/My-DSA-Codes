#include<iostream>
#include<string>
using namespace std;



int sub_str(int st,int end,int count,string S)
{
    if(st == S.length()) return count;
    
    if(st>end)
    {
        return sub_str(st+1,S.length()-1,count,S);
    }

    if(S[st] == S[end])
    {
        count++;
    }

    return sub_str(st,end-1,count,S);

}

int main() {
    string S = "abcab";
    

    cout<<sub_str(0,S.length(),0,S);
    
    return 0;
}