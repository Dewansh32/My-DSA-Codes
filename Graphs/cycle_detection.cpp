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

    bool isCycleUndir(int src,int par,vector<bool> &vis)
    {
        vis[src] = true;
        list<int> neigh = l[src];

        for(int it : neigh)
        {
            if(!vis[it])
            {
                if(isCycleUndir(it,src,vis))
                {
                    return true;
                }
            }
            else if(it != par) return true;
        }

        return false;
    }

    bool isCycle()
    {
        vector<bool> vis(v,false);

        for(int i=0;i<v;i++)
        {
            if(!vis[i])
            {

                if(isCycleUndir(i,-1,vis)) return true;
            }
        }

        return false;
    }
};

int main() {
    graph g(5);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(3,4);

    cout<<g.isCycle()<<endl;

    return 0;
}