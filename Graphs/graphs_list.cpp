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


};

int main()
{
    graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(2,4);

    g.print();

    return 0;
}