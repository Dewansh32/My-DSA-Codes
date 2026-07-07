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

        void Allpath()
        {
            vector<bool> Vis(V,false);
            string path="";
            helper(1,5,Vis,path);
        }

        void helper(int d,int s,vector<bool> &Vis,string &path)
        {
            if(s == d)
            {
                cout<<path<<d;
                cout<<endl;
                return;
            }
            Vis[s]=true;
            path += to_string(s);
            for(int neigh : l[s])
            {
                if(!Vis[neigh]) helper(d,neigh,Vis,path);
            }

            path = path.substr(0,path.size()-1);
            Vis[s] = false;
        }


};

int main()
{
    graph g(6);
    g.addEdge(0,3);
    g.addEdge(2,3);
    g.addEdge(3,1);
    g.addEdge(4,0);
    g.addEdge(4,1);
    g.addEdge(5,0);
    g.addEdge(5,2);

    g.Allpath();

    return 0;
}