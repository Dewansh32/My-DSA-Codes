#include<bits/stdc++.h>
using namespace std;

class graph{
    int V;
    list<int> *l;

    public:
        graph(int V)
        {
            this->V = V;
            l = new list<int> [V];
        }

        void addEdge(int u,int v)
        {
            l[u].push_back(v);
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

        bool isCycleDir()
        {
            vector<bool> vis(V,false);
            vector<bool> recPath(V,false);

            for(int i=0;i<V;i++)
            {
                if(!vis[i])
                {
                    if(CycleHelper(i,vis,recPath)) return true;
                }
            }

            return false;
        }

        bool CycleHelper(int u,vector<bool> &vis,vector<bool> &recPath)
        {
            vis[u]=true;
            recPath[u]=true;

            for(int v : l[u])
            {
                if(!vis[v]) 
                {
                    if(CycleHelper(v,vis,recPath))
                    {
                        return true;
                    }
                }
                else
                {
                    if(recPath[v]) return true;
                }
            }

            recPath[u]=false;
            return false;
        }
};

int main()
{
    graph g(4);

    g.addEdge(0,2);
    g.addEdge(1,0);
    g.addEdge(2,3);
    g.addEdge(3,0);

    cout<<g.isCycleDir();
    return 0;
}