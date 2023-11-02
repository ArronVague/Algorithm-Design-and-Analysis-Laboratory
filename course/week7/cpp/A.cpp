#include <bits/stdc++.h>
using namespace std;

int N;

int main()
{
    cin >> N;
    long long a = 1;
    long long b = 2;
    for (int i = 0; i < N - 1; ++i)
    {
        long long c = a + b;
        a = b;
        b = c;
    }
    cout << a << endl;
    return 0;
}