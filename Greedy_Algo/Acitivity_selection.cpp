#include<bits/stdc++.h>
using namespace std;

int maxActivities(vector<int> start,vector<int> end)
{
    int size = start.size();
    vector<pair<int,int>> activity;
    for(int i=0;i<size;i++)
    {
        activity.push_back({end[i],start[i]});
    }

    sort(activity.begin(),activity.end());

    int count = 1;
    int lastend = end[0];

    for(int i=1;i<size;i++)
    {
        if(activity[i].second>=lastend)
        {
            count++;
            lastend = end[i];
        }
    }

    return count;
}

int main() {
    vector<int> start = {1,3,0,5,8,5};
    vector<int> end = {2,4,6,7,9,9};
    

    cout<<"Max number of activities: "<<maxActivities(start,end);
    return 0;
}