#include <iostream>
using namespace std;

int w[] = {7, 11, 13, 24};
int n = 4;
int m = 31;
int x[10];

void SumofSub(int s, int k, int r)
{
    x[k] = 1;

    if (s + w[k] == m)
    {
        cout << "{ ";
        for (int i = 0; i <= k; i++)
            if (x[i] == 1)
                cout << w[i] << " ";
        cout << "}" << endl;   // Subset found
    }

    else if (k + 1 < n && (s + w[k] + w[k + 1] <= m))
        SumofSub(s + w[k], k + 1, r - w[k]);

    if (k + 1 < n && (s + r - w[k] >= m) && (s + w[k + 1] <= m))
    {
        x[k] = 0;
        SumofSub(s, k + 1, r - w[k]);
    }
}

int main()
{
    int total = 0;
    for (int i = 0; i < n; i++)
        total += w[i];

    SumofSub(0, 0, total);

    return 0;
}
