#include <bits/stdc++.h>
using namespace std;

void stock_span(const vector<int>& stock, vector<int> &span)
{
    if (stock.empty()) return;

    stack<int> S;            // store indices
    span[0] = 1;
    S.push(0);

    for (int i = 1; i < (int)stock.size(); ++i)
    {
        // Pop indices while current price is higher or equal
        while (!S.empty() && stock[i] >= stock[S.top()])
        {
            S.pop();
        }

        // If stack empty, all previous prices are <= current
        if (S.empty())
            span[i] = i + 1;
        else
            span[i] = i - S.top();

        // Push this element's index for future
        S.push(i);
    }
}

int main() {
    vector<int> stock = {100, 80, 60, 70, 60, 85, 100};
    vector<int> span(stock.size(), 0);

    stock_span(stock, span);

    cout << "Price: ";
    for (int p : stock) cout << p << " ";
    cout << "\nSpan : ";
    for (int s : span) cout << s << " ";
    cout << "\n";

    return 0;
}
