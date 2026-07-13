#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int v;
    int wt;

    Edge(int v, int wt) {
        this->v = v;
        this->wt = wt;
    } 

    int Dj(int u,int target,vector<vector<Edge>> &graph)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(graph.size(),INT_MAX);

        pq.push({0,0});
        dist[u] = 0;

        while(!pq.empty())
        {
            int u = pq.top().second;
            int dis = pq.top().first;

            pq.pop();

            for(Edge e : graph[u])
            {
                if(dist[e.v]>dist[u] + e.wt)
                {
                    dist[e.v] = dist[u] + e.wt;
                    pq.push({dist[e.v],e.v});
                }
            }
        }

        return dist[target];
    }

    
};

int main() {

    int V = 6;

    vector<vector<Edge>> graph(V);
    graph[0].push_back(Edge(1, 2));
    graph[0].push_back(Edge(2, 4));

    graph[1].push_back(Edge(2, 1));
    graph[1].push_back(Edge(3, 7));

    graph[2].push_back(Edge(4, 3));

    graph[3].push_back(Edge(5, 1));

    graph[4].push_back(Edge(3, 2));
    graph[4].push_back(Edge(5, 5));

    Edge e(0,0);

    cout<<"Shortest Distance : "<<e.Dj(0,5,graph);

    

    return 0;
}