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

    bool isCycleBFShepler(int src,vector<bool> &vis) //O(V+E)
    {
        queue<pair<int,int>> q;
        vector<int> vis(v,false);

        q.push({src,-1});
        vis[src] = true;

        while(q.size() > 0)
        {
            int u = q.front().first;
            int par = q.front().second;
            q.pop();

            for(int v : l[u])
            {
                if(!vis[v])
                {
                    q.push({v,u});
                    vis[v] = true;
                    
                }
                else if(v != par) return true;
            }
        }

        return false;
    }

    bool isCycleBFS(int src)
    {
        vector<bool> vis(v,false);
        for(int i=0;i<v;i++)
        {
            if(!vis[i])
            {
                if(isCycleBFShepler(src,vis)) return true;
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
    g.addEdge(2,3);
    g.addEdge(2,4);

    cout<<g.isCycleBFS(0);

    return 0;
}