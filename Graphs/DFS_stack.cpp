#include<bits/stdc++.h>
using namespace std;

class graph{
    int V;
    list<int> *l;

    public:
        graph(int V){
            this->V = V;
            l = new list<int> [V];
        }

        void addEdge(int u,int v)
        {
            l[u].push_back(v);
            l[v].push_back(u);
        }

        void print()
        {
            for(int i=0;i<V;i++)
            {
                cout<<i<<" : ";
                for(int neigh : l[i])
                {
                    cout<<neigh<<" ";
                }
                cout<<endl;
            }
        }

        void DFS()
        {
            vector<bool> Vis(V,false);
            DFShelper(0,Vis);
        }

        void DFShelper(int u,vector<bool> &Vis)
        {
            Vis[u]=true;
            cout<<u<<" ";
            for(int neigh : l[u])
            {
                if(!Vis[neigh]) DFShelper(neigh,Vis);
            }
        }


};

int main()
{
    graph g(7);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(3,4);
    g.addEdge(2,4);
    g.addEdge(3,5);
    g.addEdge(4,5);
    g.addEdge(5,6);

    g.DFS();

    return 0;
}