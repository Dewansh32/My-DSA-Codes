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
            for(int i=0;i<V;i++)
            {
                if(!Vis[i])
                {
                    DFShelper(i,Vis);
                    cout<<endl;
                }
            }
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

        void BFShelper(int u,vector<bool> &Vis)
        {
            queue<int> q;

            q.push(u);
            Vis[u]=true;
            while(!q.empty())
            {
                int curr = q.front();
                cout<<curr<<" ";
                for(int neigh : l[curr])
                {
                    if(!Vis[neigh])
                    {
                        q.push(neigh);
                        Vis[neigh]=true;
                    }
                }
                q.pop();
            }
        }

        void BFS()
        {
            vector<bool> Vis(V,false);
            for(int i=0;i<V;i++)
            {
                if(!Vis[i])
                {
                    BFShelper(i,Vis);
                    cout<<endl;
                }
            }
            cout<<endl;
        }


};

int main()
{
    graph g(10);
    g.addEdge(0,2);
    g.addEdge(2,5);
    g.addEdge(1,6);
    g.addEdge(6,4);
    g.addEdge(4,3);
    g.addEdge(4,9);
    g.addEdge(3,8);
    g.addEdge(3,7);

    g.DFS();

    return 0;
}