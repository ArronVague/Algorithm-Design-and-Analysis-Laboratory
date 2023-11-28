#include <bits/stdc++.h>
#define ll long long
using namespace std;

// 图论

// 欧拉图（欧拉回路）   半欧拉图（欧拉路径）
// 半欧拉图：具有欧拉路径而无欧拉回路的图
// 判别法如下 https://oi-wiki.org/graph/euler/#_3
// 无向图-欧拉回路：连通且没有奇度数点
// 无向图-欧拉路径：连通且恰有 0 或 2 个奇度数点（若有则选择其中一奇度数点为起点）
// 有向图-欧拉回路：SCC 只有一个且每个点的入度和出度相同
// 有向图-欧拉路径：1. 对应的无向图是连通的；2. 若每个点的入度和出度相同则起点任意；否则起点的出度比入度多一，终点的入度比出度多一，且其余点的入度和出度相同
//
// NOTE: 递归前对边排序可保证输出的是字典序最小的路径

vector<int> eulerianPathOnDirectedGraph(int n, int m)
{
    // 有向图版本
    vector<vector<int>> g(n, vector<int>());
    vector<int> inDeg(n);

    for (int i = 0; i < m; ++i)
    {
        int v, w;
        cin >> v >> w;
        g[v - 1].push_back(w - 1);
        inDeg[w - 1]++;
        // read g ...
    }

    // 排序，保证字典序最小
    for (auto &es : g)
    {
        sort(es.begin(), es.end());
    }

    int st = -1, end = -1;
    for (int i = 0; i < g.size(); ++i)
    {
        // 出度比入度大一，为起点
        if (g[i].size() == inDeg[i] + 1)
        {
            // 无欧拉路径
            if (st >= 0)
            {
                return vector<int>();
            }
            st = i;
        }
        // 入度比出度大一，为终点
        if (g[i].size() + 1 == inDeg[i])
        {
            // 无欧拉路径
            if (end >= 0)
            {
                return vector<int>();
            }
            end = i;
        }
    }

    // 任选一起点（比如字典序最小），此时返回的是欧拉回路
    if (st < 0)
    {
        st = 0;
    }

    vector<int> path;
    function<void(int)> dfs = [&](int u)
    {
        while (g[u].size())
        {
            int v = g[u].front();
            g[u].erase(g[u].begin());
            dfs(v);
        }
        path.push_back(u + 1);
    };
    dfs(st);

    reverse(path.begin(), path.end());
    return path;
}

/*
// 任意两点最短路 Floyd-Warshall  O(n^3)  本质是求 Min-plus matrix multiplication
// 传入邻接矩阵 dis
// dis[v][w] == inf 表示没有 v-w 边
// https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm
// https://en.wikipedia.org/wiki/Min-plus_matrix_multiplication
// https://oi-wiki.org/graph/shortest-path/#floyd
// https://zhuanlan.zhihu.com/p/623757829
*/

vector<vector<int>> shortestPathFloydWarshall(vector<vector<int>> dis)
{
    // dis[k][i][j] 表示「经过若干个编号不超过 k 的中间节点」时，从 i 到 j 的最短路长度，其中第一维可以压缩掉
    // 为什么可以把第一维度去掉？dis[i][k] 和 dis[k][j] 不会被覆盖掉吗？
    // 见算法导论第三版练习 25.2-4（网络上有习题解答）
    int n = dis.size();
    for (int k = 0; k < n; ++k) // 中间节点的最大编号
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                // 决策（k 不是中间节点，k 是中间节点）
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    return dis;
}

// 拓扑排序
// https://leetcode.cn/problems/collect-coins-in-a-tree/description/ 收集树中金币

// 有向图的拓扑排序 Kahn's algorithm
// 可以用来判断有向图是否有环、求 DAG 上的 DP 等
// https://oi-wiki.org/graph/topo/
// https://cp-algorithms.com/graph/topological-sort.html
// DAG DP https://codeforces.com/problemset/problem/1679/D

vector<int> topoSort(int n, vector<vector<int>> edges)
{
    vector<vector<int>> g(n);
    vector<int> deg(n);
    for (auto &e : edges)
    {
        int v = e[0], w = e[1];
        g[v].push_back(w);
        deg[w]++;
    }

    queue<int> q;
    vector<int> orders;
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
        orders.push_back(x);
        for (auto y : g[x])
        {
            if (--deg[y] == 0)
            {
                q.push(y);
            }
        }
    }
    return orders;
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