#include<bits/stdc++.h>
using namespace std;

class Row{
    public:
    int count;
    int idx;

    Row(int c,int i)
    {
        count = c;
        idx = i;
    }

    bool operator < (const Row &obj)const{
        if(this->count == obj.count)
        {
            return this->idx > obj.idx;
        }

        return this->count > obj.count;
    }
};

void weakestSoldier(vector<vector<int>> matrix,int K)
{
    int n = matrix.size();

     vector<Row> rows;
   

    for(int i=0;i<matrix.size();i++)
    {
        int count = 0;
        for(int j=0;j<matrix[i].size() && matrix[i][j] == 1;j++)
        {
            count++;
        }
        rows.push_back(Row(count,i));
    }

    priority_queue<Row> pq(rows.begin(),rows.end());

    for(int i=0;i<K;i++)
    {
        cout<<"Weakest idx: "<<pq.top().idx<<endl;
        pq.pop();
    }

    return;
}

int main() {
    vector<vector<int>> matrix = {{1,0,0,0},
                                  {1,1,1,1},
                                  {1,0,0,0},
                                  {1,0,0,0}};

    weakestSoldier(matrix,2);

    return 0;
}   