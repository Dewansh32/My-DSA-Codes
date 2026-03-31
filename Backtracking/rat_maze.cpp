#include <bits/stdc++.h>
using namespace std;

bool foundPath = false;  // global flag

void grid_ways(int maze[4][4], int r, int c, int n, int m, string way, vector<vector<bool>> &visited)
{
    if (r < 0 || c < 0 || r >= n || c >= m) return;
    if (maze[r][c] == 0 || visited[r][c]) return;

    if (r == n - 1 && c == m - 1) {
        cout << way << endl;
        foundPath = true;
        return;
    }

    visited[r][c] = true;

    if (c + 1 < m && maze[r][c + 1] && !visited[r][c + 1]) {
        grid_ways(maze, r, c + 1, n, m, way + 'R', visited);
    }
    if (r + 1 < n && maze[r + 1][c] && !visited[r + 1][c]) {
        grid_ways(maze, r + 1, c, n, m, way + 'D', visited);
    }
    if (r - 1 >= 0 && maze[r - 1][c] && !visited[r - 1][c]) {
        grid_ways(maze, r - 1, c, n, m, way + 'U', visited);
    }
    if (c - 1 >= 0 && maze[r][c - 1] && !visited[r][c - 1]) {
        grid_ways(maze, r, c - 1, n, m, way + 'L', visited);
    }

    visited[r][c] = false;
}

int main() {
    int maze[4][4] = {
        {1,0,0,0},
        {1,1,0,1},
        {1,1,0,0},
        {0,1,1,1},
    };

    int n = 4, m = 4;
    vector<vector<bool>> visited(4, vector<bool>(4, false));
    string way = "";

    // Edge case: if start or goal blocked, no need to search
    if (maze[0][0] == 0 || maze[n-1][m-1] == 0) {
        cout << "No path exists\n";
        return 0;
    }

    grid_ways(maze, 0, 0, n, m, way, visited);

    if (!foundPath)
        cout << "No path exists\n";

    return 0;
}
