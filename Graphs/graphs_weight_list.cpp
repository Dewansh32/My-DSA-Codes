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


};

int main()
{
    graph g(5);
    g.addEdge(0,1,5);
    g.addEdge(1,2,1);
    g.addEdge(1,3,3);
    g.addEdge(2,3,1);
    g.addEdge(2,4,2);

    g.print();

    return 0;
}