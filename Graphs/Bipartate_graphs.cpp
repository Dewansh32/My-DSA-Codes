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

    bool Bipartate(int u)
    {
        vector<bool> vis(v,false);
        queue<int> q;
        vector<int> col(v,-1);
        q.push(u);
        vis[u] = true;
        col[u] = 0;
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            for(int neigh : l[curr])
            {
                if(!vis[neigh])
                {
                    q.push(neigh);
                    vis[neigh]=true;
                    if(col[curr]==0) col[neigh]=1;
                    else col[neigh]=0;
                }
                else{
                    if(col[neigh] == col[curr]) return false;
                }
            }
        }

        return true;
    }
};


int main() {
    graph g(5);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(3,4);
    g.addEdge(2,4);

    cout<<g.Bipartate(0);
    
    return 0;
}
