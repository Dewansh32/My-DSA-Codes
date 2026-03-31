#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> A = {4,1,8,7};
    vector<int> B = {2,3,6,5};

    sort(A.begin(),A.end());
    sort(B.begin(),B.end());

    int abs_diff = 0;

    for(int i=0;i<4;i++)
    {
        abs_diff += abs(A[i]-B[i]);
    }

    cout<<"Min Sum of abs difference: "<<abs_diff;
    return 0;
}