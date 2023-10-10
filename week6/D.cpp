#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, R;

bool cmp(const vector<int> &a, const vector<int> &b)
{
    return a[1] < b[1];
}

int main()
{
    cin >> N >> M >> R;
    vector<vector<int>> a(M + 1, vector<int>(3, 0));
    for (int i = 1; i <= M; ++i)
    {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        a[i][1] += R;
    }
    sort(a.begin(), a.end(), cmp);
    vector<int> p(M + 1, 0);
    for (int i = M; i >= 1; --i)
    {
        for (int j = i - 1; j > 0; --j)
        {
            if (a[j][1] <= a[i][0])
            {
                p[i] = j;
                break;
            }
        }
    }
    vector<int> d(M + 1, 0);
    for (int i = 1; i <= M; ++i)
    {
        d[i] = max(d[p[i]] + a[i][2], d[i - 1]);
    }
    cout << d[M] << endl;
    return 0;
}