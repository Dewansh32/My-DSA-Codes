#include<bits/stdc++.h>
using namespace std;

class graph{
    int V;
    list<pair<int,int>> *l;

    public:
        graph(int V){
            this->V = V;
            l = new list<pair<int,int>> [V];
        }

        void addEdge(int u,int v,int w)
        {
            l[u].push_back({v,w});
            l[v].push_back({u,w});
        }

        void print()
        {
            for(int i=0;i<V;i++)
            {
                cout<<i<<" : ";
                for(pair<int,int> neigh : l[i])
                {
                    cout<<"("<< neigh.first <<","<<neigh.second<<") ";
                }
                cout<<endl;
            }
        }

        void MST(int src)
        {
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
            vector<bool> set(V,false);

            int ans = 0;
            pq.push({0,src});

            while(!pq.empty())
            {
                int u = pq.top().second;
                int wt = pq.top().first;
                pq.pop();

                if(!set[u])
                {
                    set[u] = true;
                    ans += wt;
                    for(pair<int,int> n : l[u])
                    {
                        int v = n.first;
                        int currWt = n.second;
                        pq.push({currWt,v});
                    }

                }

            }

            cout<<"Final MST cost : "<<ans<<endl;
        }
};

int main()
{
    graph g(5);
    g.addEdge(0,1,10);
    g.addEdge(0,2,15);
    g.addEdge(1,3,10);
    g.addEdge(2,3,50);
    g.addEdge(0,3,30);

    g.MST(0);

    return 0;
}