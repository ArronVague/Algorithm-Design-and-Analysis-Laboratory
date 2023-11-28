#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 10;
int n, m;
int indeg[maxN], outdeg[maxN];
vector<int> g[maxN];
int u, v;
vector<int> ans;
int flag[maxN];

int isEuler()
{
    int start = 1;
    bool allZero = true;
    int sum1 = 0, sum2 = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (indeg[i] != outdeg[i])
        {
            allZero = false;
        }
        if (indeg[i] - outdeg[i] > 1)
        {
            return -1;
        }
        if (indeg[i] - outdeg[i] == 1)
        {
            sum1++;
        }
        if (outdeg[i] - indeg[i] == 1)
        {
            sum2++;
            start = i;
        }
    }
    if (allZero || (sum1 == sum2 && sum1 == 1))
    {
        return start;
    }
    return -1;
}

void dfs(int x)
{
    // cout << "fuck" << endl;
    while (flag[x] < g[x].size())
    {
        int t = flag[x];
        flag[x]++;
        dfs(g[x][t]);
    }
    // cout << "dfs" << x << endl;
    ans.push_back(x);
}

int main()
{
    cin >> n >> m;
    while (m--)
    {
        cin >> u >> v;
        g[u].push_back(v);
        indeg[v]++;
        outdeg[u]++;
    }
    for (int i = 1; i <= n; i++)
    {
        sort(g[i].begin(), g[i].end());
    }
    int start = isEuler();
    // cout << start;
    if (start == -1)
    {
        cout << "No" << endl;
    }
    else
    {
        dfs(start);
        for (int i = ans.size() - 1; i >= 0; i--)
        {
            cout << ans[i] << " ";
        }
    }
    return 0;
}