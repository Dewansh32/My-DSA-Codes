#include<bits/stdc++.h>
using namespace std;

struct comparePair{

    bool operator () (pair<string,int> &p1,pair<string,int> &p2)
    {
        return p1.second < p2.second;
    }
};

int main() {
    priority_queue<pair<string,int>,vector<pair<string,int>>,comparePair> pq;

    pq.push(make_pair("aman",2000));
    pq.push(make_pair("bhumika",1250));
    pq.push(make_pair("kanishk",500));

    while(!pq.empty())
    {
        cout<<"top is: "<<pq.top().first<<","<<pq.top().second<<endl;
        pq.pop();
    }

    return 0;
}