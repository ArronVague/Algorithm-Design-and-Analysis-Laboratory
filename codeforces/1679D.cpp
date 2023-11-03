// https://codeforces.com/problemset/problem/1679/D
// Toss a Coin to Your Graph...
/*
 * @brief
输入 n(1≤n≤2e5) m(0≤m≤2e5) k(1≤k≤1e18) 和长为 n 的数组 a(1≤a[i]≤1e9)。
然后输入 m 条边，每条边输入 x y，表示一条从 x 到 y 的有向边。节点编号从 1 开始。
保证图中无自环和重边。

如果图中不存在一条长为 k 的路径（路径有 k 个节点），输出 -1。
否则输出路径上的最大点权的最小值。
注意：你可以重复访问同一个节点。

输入
6 7 4
1 10 2 3 4 5
1 2
1 3
3 4
4 5
5 6
6 2
2 5
输出 4

输入
6 7 100
1 10 2 3 4 5
1 2
1 3
3 4
4 5
5 6
6 2
2 5
输出 10

输入
2 1 5
1 1
1 2
输出 -1

输入
1 0 1
1000000000
输出 1000000000

【灵茶の试炼】题目&题解
https://docs.qq.com/sheet/DWGFoRGVZRmxNaXFz
 */

/*
最大权的最小值，典型的二分答案mx
check中，只考虑权值小于mx的点
如果成环，返回true
如果不成环，拓扑排序计算DAG的最长路（可用dp）
长度大于等于k，返回true
长度小于k，返回false
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m;
ll k;
int x, y;
vector<vector<int>> g;
vector<int> val;

bool check(ll mx)
{
    vector<int> deg(n + 1);
    int left = n;
    for (int i = 1; i <= n; ++i)
    {
        if (val[i] > mx)
        {
            left--;
            continue;
        }
        for (auto nxt : g[i])
        {

            if (val[nxt] <= mx)
            {
                deg[nxt]++;
            }
        }
    }
    queue<int> q;
    vector<ll> depth(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        if (val[i] > mx)
        {
            continue;
        }
        if (deg[i] == 0)
        {

            q.push(i);
            depth[i] = 1;
        }
    }
    while (q.size())
    {
        int cur = q.front();
        q.pop();
        left--;
        for (auto nxt : g[cur])
        {
            if (val[nxt] > mx)
            {
                continue;
            }
            deg[nxt]--;
            depth[nxt] = max(depth[nxt], depth[cur] + 1);
            if (deg[nxt] == 0)
            {
                q.push(nxt);
            }
        }
    }
    // 有环
    return left > 0 || *max_element(depth.begin(), depth.end()) >= k;
}

int binary(int left, int right)
{
    // 开区间写法
    while (left + 1 < right)
    {
        int mid = left + (right - left) / 2;
        if (check(mid))
        {
            // 谁在check()中谁就是答案
            right = mid;
        }
        else
        {
            left = mid;
        }
    }
    return right;
}

int main()
{
    cin >> n >> m >> k;
    g.resize(n + 1);
    val.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> val[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        g[x].push_back(y);
    }
    int ans = binary(0, 1e9 + 1);
    if (ans > 1e9)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
    return 0;
}