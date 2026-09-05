#include<bits/stdc++.h>
using namespace std;

int countValidPrefixes(string s) {
        int n = s.length();
        int ans = 1;

        for(int i=1;i<n;i++)
        {
            string subs = s.substr(0,i);
            int count0 = 0;
            int count1 = 0;
            for(int j=0;j<subs.length();j++)
            {
                if(subs[j] == '0') count0++;
                else count1++;
            }

            if(count1 >= count0-1 && count1 <= count0+1) ans++;        
        }

        return ans;
    }

int main() {
    string s = "00101";
    cout<<countValidPrefixes(s);
    return 0;
}

