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

        void inDeg(vector<int> &indeg)
        {
            for(int i=0;i<V;i++)
            {
                for(int neigh:l[i])
                {
                    indeg[neigh]++;
                }
            }
        }

        void topo_kahn()
        {
            vector<int> indeg(V,0);
            queue<int> q;
            inDeg(indeg);
            vector<int> ans;

            for(int i=0;i<V;i++)
            {
                if(indeg[i]==0)
                {
                    q.push(i);
                }
            }

            while(!q.empty())
            {
                int curr = q.front();
                q.pop();
                ans.push_back(curr);

                for(int neigh : l[curr])
                {
                    indeg[neigh]--;
                    if(indeg[neigh] == 0) q.push(neigh);
                }
            }

            for(int i=0;i<V;i++)
            {
                cout<<ans[i]<<" ";
            }
            
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

    g.topo_kahn();  

    return 0;
}