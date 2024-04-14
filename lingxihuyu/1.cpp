#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        uint64_t x, y;
        cin >> x >> y;
        uint64_t z = 0;
        for (int i = 0; i < 32; i++)
        {
            z |= ((x >> i) & 1) << (2 * i + 1);
            z |= ((y >> i) & 1) << (2 * i);
        }
        cout << z << endl;
    }
}