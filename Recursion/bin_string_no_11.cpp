#include<iostream>
#include<string>
using namespace std;

void bin_str(int n,int ls_pl,string ans)
{
    if(n == 0)
    {
        cout<<ans<<endl;
        return;
    }

    if(ls_pl != 1)
    {
        bin_str(n-1,0,ans+'0');
        bin_str(n-1,1,ans+'1');
    }
    else{
        bin_str(n-1,0,ans+'0');
    }
}

int main() {
    string ans;

    bin_str(3,0,ans);

    return 0;
}