// 图论

// 拓扑排序
// https://leetcode.cn/problems/collect-coins-in-a-tree/description/ 收集树中金币

class Solution
{
public:
    int collectTheCoins(vector<int> &coins, vector<vector<int>> &edges)
    {
        int n = coins.size();

        // 模板
        vector<vector<int>> g(n);
        vector<int> deg(n);
        for (auto &e : edges)
        {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
            // 视情况取入度
            deg[x]++;
            deg[y]++;
        }

        // 模板
        queue<int> q;
        for (int i = 0; i < n; ++i)
        {
            if (deg[i] == 1 && !coins[i])
            {
                q.push(i);
            }
        }
        int ans = n - 1;
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            ans--;
            for (auto &y : g[x])
            {
                if (--deg[y] == 1 && !coins[y])
                {
                    q.push(y);
                }
            }
        }
        for (int i = 0; i < n; ++i)
        {
            if (deg[i] == 1 && coins[i])
            {
                q.push(i);
            }
        }
        ans -= q.size();
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (auto &y : g[x])
            {
                if (--deg[y] == 1)
                {
                    ans--;
                }
            }
        }
        return max(ans * 2, 0);
    }
};

// 有向图的拓扑排序 Kahn's algorithm
// 可以用来判断有向图是否有环、求 DAG 上的 DP 等
// https://oi-wiki.org/graph/topo/
// https://cp-algorithms.com/graph/topological-sort.html
// DAG DP https://codeforces.com/problemset/problem/1679/D
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
    // 计算入度
    vector<int> deg(n + 1);
    int left = n;
    for (int i = 1; i <= n; ++i)
    {
        for (auto nxt : g[i])
        {
            deg[nxt]++;
        }
    }
    queue<int> q;
    vector<ll> depth(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        if (deg[i] == 0)
        {

            q.push(i);
            // 可初始化dp
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
            deg[nxt]--;
            depth[nxt] = max(depth[nxt], depth[cur] + 1);
            if (deg[nxt] == 0)
            {
                q.push(nxt);
            }
        }
    }
    // 若left > 0说明有环
}

int main()
{
    cin >> n >> m >> k;
    // 建图
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
}

// 基环树（环套树），英文名叫 pseudotree，基环树森林叫 pseudoforest
// https://en.wikipedia.org/wiki/Pseudoforest
// https://leetcode.cn/problems/maximum-employees-to-be-invited-to-a-meeting/description/ 参加会议的最多员工数

int maximumInvitations(vector<int> &favorite)
{
    int n = favorite.size();
    vector<int> deg(n);
    for (auto f : favorite)
    {
        deg[f]++;
    } // g 上每个节点的入度

    // 拓扑排序，剪掉 g 上的所有树枝
    // 拓扑排序后 deg 值为 1 的点必定在基环上，为 0 的点必定在树枝上
    vector<vector<int>> rg(n); // g 的反图（外向基环树）
    queue<int> q;
    for (int i = 0; i < n; ++i)
    {
        if (deg[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        int y = favorite[x];
        rg[y].push_back(x); // 顺便建一下反图（在这里建反图可以避免加入基环上的边）
        if (--deg[y] == 0)
        {
            q.push(y);
        }
    }

    // 在反图上遍历入环点+树枝
    // 由于考虑了入环点，所以可以遍历到基环树上的所有点
    function<int(int)> rdfs = [&](int root) -> int
    {
        int max_depth = 1;
        for (auto son : rg[root])
        {
            max_depth = max(max_depth, rdfs(son) + 1);
        }
        return max_depth;
    };

    int sum_chain_size = 0;
    int max_ring_size = 0;
    // 注意可能有多棵基环树
    for (int i = 0; i < n; ++i)
    {
        if (deg[i] == 0)
        {
            continue;
        }
        deg[i] = 0; // 将基环上的点的入度标记为 0，避免重复访问
        int x = favorite[i];
        int ring_size = 1;
        // 遍历基环
        while (x != i)
        {
            ring_size++;
            deg[x] = 0;
            x = favorite[x];
        }
        // 注意基环长度为 2 的情况
        if (ring_size == 2)
        {
            sum_chain_size += rdfs(i) + rdfs(favorite[i]);
        }
        else
        {
            max_ring_size = max(max_ring_size, ring_size);
        }
    }
    return max(max_ring_size, sum_chain_size);
}