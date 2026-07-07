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

        void BFS()
        {
            queue<int> q;
            vector<bool> Vis(V,false);

            q.push(0);
            Vis[0]=true;
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

    g.BFS();

    return 0;
}