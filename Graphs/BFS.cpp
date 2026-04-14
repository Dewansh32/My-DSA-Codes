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

    void BFS() //O(V+E)
    {
        queue<int> q;
        vector<int> vis(v,false);

        q.push(0);
        vis[0] = true;

        while(q.size() > 0)
        {
            int u = q.front();
            q.pop();

            cout<<u<<" ";

            for(int v : l[u])
            {
                if(!vis[v])
                {
                    q.push(v);
                    vis[v] = true;
                }
            }
        }

        cout<<endl;
    }
};

int main() {
    graph g(5);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(2,4);

    g.BFS();

    return 0;
}