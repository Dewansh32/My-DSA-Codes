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

        bool isCycleUndir()
        {
            vector<bool> Vis(V,false);
            return CycHelper(0,-1,Vis);
        }

        bool CycHelper(int u,int par,vector<bool> &Vis)
        {
            Vis[u]=true;
            for(int neigh : l[u])
            {
                if(!Vis[neigh]) CycHelper(neigh,u,Vis);
                if(Vis[neigh] && neigh!=par) return true;
                
            }

            return false;
        }


};

int main()
{
    graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(3,4);

    cout<<g.isCycleUndir();

    return 0;
}