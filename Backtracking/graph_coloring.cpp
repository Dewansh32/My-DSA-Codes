#include <iostream>
using namespace std;

int n, m;
int G[25][25];
int x[25];

bool issafe(int k, int c)
{
    for (int i = 0; i < n; i++)
        if (G[k][i] == 1 && x[i] == c)
            return false;
    return true;
}

void graphcolor(int k)
{
    for (int c = 1; c <= m; c++)
    {
        if (issafe(k, c))
        {
            x[k] = c;

            if (k + 1 < n)
                graphcolor(k + 1);
            else
            {
                for (int i = 0; i < n; i++)
                    cout << x[i] << " ";
                cout << endl;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> G[i][j];

    graphcolor(0);
    return 0;
}
