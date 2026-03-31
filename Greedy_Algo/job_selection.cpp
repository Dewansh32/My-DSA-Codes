#include <bits/stdc++.h>
using namespace std;

// pair = {deadline, profit}
bool compare(pair<int,int> p1, pair<int,int> p2) {
    return p1.second > p2.second;   // sort by profit
}

int maxProfit(vector<pair<int,int>> jobs) {
    sort(jobs.begin(), jobs.end(), compare);

    int profit = jobs[0].second;
    int safeDeadline = jobs[0].first;

    for(int i = 1; i < jobs.size(); i++) {
        if(jobs[i].first > safeDeadline) {
            profit += jobs[i].second;
            safeDeadline++;
        }
    }

    return profit;
}

int main() {
    vector<pair<int,int>> jobs = {
        {2, 100},
        {1, 19},
        {2, 27},
        {1, 25},
        {3, 15}
    };

    cout << maxProfit(jobs);
    return 0;
}
