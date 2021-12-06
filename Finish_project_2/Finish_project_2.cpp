#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main()
{
    int n, y, x, k, i;
    double H;
    cin >> n >> y >> x >> k;
    int k1 = k;
    vector<int> h(n + 1);

    for (i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    for (k = 0; k < k1; k++)
    {
        for (i = 0; i < n; i++)
        {
            if (h[i] + y <= x)
            {
                h[i] += y;
            }
            else h[i] = x - y;
        }
    }
    int s = 0;
    for (i = 0; i < n; i++)
    {
        s += h[i];
    }

    H = double(s) / n;
    cout.precision(4);
    cout << fixed << H;
}

