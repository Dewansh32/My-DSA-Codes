#include<bits/stdc++.h>
using namespace std;

class car{
public:
    int idx;
    int distSq;

    car(int i,int dSq)
    {
        idx = i;
        this->distSq = dSq;
    }

    // Reverse logic to make min heap
    bool operator < (const car &obj) const
    {
        return this->distSq > obj.distSq;
    }
};

void nearbyCars(vector<pair<int,int>> pos,int k)
{
    vector<car> cars;

    // Step 1: Store cars with distance
    for(int i=0;i<pos.size();i++)
    {
        int distSq = pos[i].first*pos[i].first + pos[i].second*pos[i].second;
        cars.push_back(car(i,distSq));
    }

    // Step 2: Build heap
    priority_queue<car> pqc(cars.begin(),cars.end());

    // Step 3: Get k nearest cars  
    for(int i=0;i<k;i++)
    {
        cout << "Car index: " << pqc.top().idx << endl;
        pqc.pop();
    }
}

int main() {
    vector<pair<int,int>> pos;

    pos.push_back(make_pair(3,3));   // dist = 18
    pos.push_back(make_pair(5,-1));  // dist = 26
    pos.push_back(make_pair(-2,4));  // dist = 20

    nearbyCars(pos, 2);

    return 0;
}