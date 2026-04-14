#include<bits/stdc++.h>
using namespace std;

class graph{
    int v;
    list<int> *l;

public:
    graph(int v){
        this->v = v;
        l = new list<int>[v]; 
    }

    void addEdge(int u,int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void printAdjList()
    {
        for(int i=0;i<v;i++)
        {
            cout<<i<<" : ";
            for(int neigh : l[i])
            {
                cout<<neigh<<" ";
            }
            cout<<endl;
        }
    }

    void dfs(int u,vector<bool> &vis)
    {
        cout<<u<<" ";
        vis[u] = true;

        for(int v : l[u])
        {
            if(!vis[v])
            {
                dfs(v,vis);
            }
        }
    }
};

int main() {
    graph g(5);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);

    vector<bool> vis(5,false);
    g.dfs(0,vis);

    return 0;
}