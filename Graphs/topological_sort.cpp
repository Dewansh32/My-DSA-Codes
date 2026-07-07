#include<bits/stdc++.h>
using namespace std;

class graph{
    int V;
    list<int> *l;

    public:
        graph(int v)
        {
            V = v;
            l = new list<int> [v];
        }

        void addEdge(int u,int v)
        {
            l[u].push_back(v);
        }

        void printAdjList()
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

        void tsort()
        {
            vector<bool> Vis(V,false);
            stack<int> s;

            for(int i=0;i<V;i++)
            {
                if(!Vis[i])
                {
                    topological_sort(i,Vis,s);
                }
            }

            while(!s.empty())
            {
                cout<<s.top()<<" ";
                s.pop();
            }

        }

        void topological_sort(int u,vector<bool> & Vis,stack<int> &s)
        {
            Vis[u] = true;
            for(int neigh : l[u])
            {
                if(!Vis[neigh])
                {
                    topological_sort(neigh,Vis,s);
                }
            }

            s.push(u);
        }
};

int main()
{
    graph g(6);

    g.addEdge(2,3);
    g.addEdge(3,1);
    g.addEdge(4,0);
    g.addEdge(4,1);
    g.addEdge(5,0);
    g.addEdge(5,2);

    g.tsort();

    return 0;
}