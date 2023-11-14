#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> A;
int t;

int main()
{
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> t;
        A.insert(upper_bound(A.begin(), A.end(), t), t);
        if (i & 1 == 1)
        {
            cout << A[i / 2] << '\n';
        }
    }
}