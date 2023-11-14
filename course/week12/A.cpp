#include <bits/stdc++.h>
using namespace std;

int N;
const int MAXN = 1e5;
int a[MAXN];

int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> a[i];
    }
    sort(a, a + N);
    for (int i = 0; i < N; ++i)
    {
        cout << a[i] << " ";
    }
}