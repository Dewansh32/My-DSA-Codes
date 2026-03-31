#include<bits/stdc++.h>
using namespace std;

void print_board(vector<vector<char>> &board)
{
    int n = board.size();
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"-----------------------"<<endl;
}

bool isSafe(vector<vector<char>> &board,int row,int col)
{
    int n = board.size();

    //vertical
    for(int i=0;i<row;i++)
    {
        if(board[i][col] == 'Q') return false;
    }

    //diagnol left
    int r = row-1,c = col-1;
    while(r>=0 && c>=0)
    {
        if(board[r][c] == 'Q') return false;
        r--;
        c--;
    }

    //diagnol rigth
    r = row-1,c = col+1;
    while(r>=0 && c<n)
    {
        if(board[r][c] == 'Q') return false;
        r--;
        c++;
    }

    return true;
}

void nQueens(vector<vector<char>> &board,int row)
{
    if(board.size() == row)
    {
        print_board(board);
        return;
    }

    for(int j=0;j<board[row].size();j++)
    {
        if(isSafe(board,row,j))
        {
            board[row][j] = 'Q';
            nQueens(board,row+1);
            board[row][j] = '.';
        }
    }
}

int main() {
    vector<vector<char>> board;
    int n;
    cout<<"Enter size: ";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        vector<char> newRow;
        for(int j=0;j<n;j++)
        {
            newRow.push_back('.');
        }
        board.push_back(newRow);
    }

    print_board(board);
    nQueens(board,0);

    return 0;
}

// 7 11 13 24   m=31   r=54