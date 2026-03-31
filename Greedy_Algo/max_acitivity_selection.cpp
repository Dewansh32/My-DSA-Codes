#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> p1,pair<int,int> p2)
{
    return p1.second<p2.second;
}

int maxActivities(vector<pair<int,int>> pairs)
{
    int size = pairs.size();
    

    sort(pairs.begin(),pairs.end(),compare);

    int count = 1;
    int lastend = pairs[0].second;

    for(int i=1;i<size;i++)
    {
        if(pairs[i].first>=lastend)
        {
            count++;
            lastend = pairs[i].second;
        }
    }

    return count;
}

int main() {
   vector<pair<int,int>> pairs = {
    {5, 24},
    {39, 60},
    {5, 28},
    {27, 40},
    {50, 90}
    };

    

    cout<<"Max number of activities: "<<maxActivities(pairs);
    return 0;
}