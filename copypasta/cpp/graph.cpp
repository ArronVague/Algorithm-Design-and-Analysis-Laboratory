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
        g[v].push_back(w);
        inDeg[w]++;
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
        path.push_back(u);
    };
    dfs(st);

    reverse(path.begin(), path.end());
    return path;
}

// 另一种 Dijkstra 写法
// 适用于稠密图 O(n^2)
// 建模 https://codeforces.com/contest/1528/problem/D
vector<int> shortestPathDijkstra2(vector<vector<int>> g, int st)
{
    int n = g.size();

    const int inf = 2e9;
    vector<int> dis(n, inf);
    dis[st] = 0;
    vector<bool> vis(n);
    while (true)
    {
        int v = -1;
        for (int w = 0; w < vis.size(); ++w)
        {
            bool b = vis[w];
            if (!b && (v < 0 || dis[w] < dis[v]))
            {
                v = w;
            }
        }
        if (v < 0)
        {
            return dis;
        }
        vis[v] = true;
        for (int w = 0; w < g[v].size(); ++w)
        {
            int wt = g[v][w];
            int newD = dis[v] + wt;
            if (newD < dis[w])
            {
                dis[w] = newD;
            }
        }
    }
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

// 最小生成树 Kruskal
// 适用于稀疏图 O(mlogm)，或者边已经按权值排序的情况
// 性质：
// - 对于不同的 MST，同一边权的边的个数都是相同的（应用见后面的最小生成树计数）
// - 对于任意正确加边方案，加完小于某权值的边后，图的连通性是一样的
// https://oi-wiki.org/graph/mst/#kruskal
// https://cp-algorithms.com/graph/mst_kruskal.html
// 边权 [0,1] 的随机完全图的 MST 权值和是 ζ(3) = 1.202…	https://en.wikipedia.org/wiki/Random_minimum_spanning_tree https://www.sciencedirect.com/science/article/pii/0166218X85900587
//
// TIPS: 混合点权边权的问题，可以创建一个超级源点，把每个点 i 和超级源点相连，边权为点 i 的点权。这样就转换成了 MST 问题。
int mstKruskal(int n, vector<vector<int>> edges)
{
    sort(edges.begin(), edges.end(), [](const vector<int> &a, const vector<int> &b)
         { return a[2] < b[2]; });

    vector<int> fa(n);
    for (int i = 0; i < fa.size(); ++i)
    {
        fa[i] = i;
    }
    function<int(int)> find = [&](int x)
    {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    };

    int sum = 0;
    int cntE = 0;
    for (auto &e : edges)
    {
        int v = e[0], w = e[1], wt = e[2];
        int fv = find(v), fw = find(w);
        if (fv != fw)
        {
            fa[fv] = fw;
            sum += wt;
            cntE++;
        }
    }

    if (cntE < n - 1)
    {
        return -1;
    }
    return sum;
}

// 最小生成树 Prim
// 适用于稠密图 O(n^2)，传入邻接矩阵 dis
// dis[v][w] == inf 表示没有 v-w 边
// 有些题目需要在连通分量上求 MST，这时就需要用到 root
// 可视化 https://visualgo.net/zh/mst
// https://oi-wiki.org/graph/mst/#prim
void mstPrim(vector<vector<int>> dis, int root, int &mst, vector<vector<int>> &edges)
{
    // 注意：dis 需要保证 dis[i][i] = inf，从而避免自环的影响

    const int inf = 2e9;
    struct Node
    {
        int v;
        int d;
    };
    // minD[i].d 表示当前 MST 到点 i 的最小距离，对应的边为 minD[i].v-i
    vector<Node> minD(dis.size());
    for (int i = 0; i < dis.size(); ++i)
    {
        minD[i] = {i, inf};
    }
    minD[root].d = 0;
    vector<bool> inMST(dis.size());
    while (true)
    {
        // 根据切分定理，求不在当前 MST 的点到当前 MST 的最小距离，即 minD[v].d
        int v = -1;
        for (int w = 0; w < inMST.size(); ++w)
        {
            bool in = inMST[w];
            if (!in && (v < 0 || minD[w].d < minD[v].d))
            {
                v = w;
            }
        }
        // 已求出 MST
        if (v < 0)
        {
            return;
        }

        // 加入 MST
        inMST[v] = true;
        mst += minD[v].d;
        if (v != root)
        {
            edges.push_back({minD[v].v, v});
        }

        // 更新 minD
        for (int w = 0; w < dis[v].size(); ++w)
        {
            int d = dis[v][w];
            if (!inMST[w] && d < minD[w].d)
            {
                minD[w] = {v, d};
            }
        }
    }
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

// 强连通分量分解 Strongly Connected Component (SCC)
// https://en.wikipedia.org/wiki/Kosaraju%27s_algorithm
// https://oi-wiki.org/graph/scc/#kosaraju
// https://algs4.cs.princeton.edu/code/edu/princeton/cs/algs4/KosarajuSharirSCC.java.html

vector<vector<int>> sccKosaraju(int n, int m)
{
    vector<vector<int>> g(n), rg(n);
    for (int i = 0; i < m; ++i)
    {
        int v, w;
        cin >> v >> w;
        g[v].push_back(w);
        rg[w].push_back(v);
    }

    // 生成 DFS 后序（用于跑逆后序遍历，这样生成的 SCC 一定是拓扑序）
    vector<int> vs;
    vector<bool> vis(n);
    function<void(int)> dfs = [&](int v)
    {
        vis[v] = true;
        for (auto w : g[v])
        {
            if (!vis[w])
            {
                dfs(w);
            }
        }
        vs.push_back(v);
    };
    for (int i = 0; i < n; ++i)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }

    vis.assign(n, false);
    vector<int> comp;
    function<void(int)> rdfs = [&](int v)
    {
        vis[v] = true;
        comp.push_back(v);
        for (auto w : rg[v])
        {
            if (!vis[w])
            {
                rdfs(w);
            }
        }
    };

    vector<vector<int>> scc;

    // 逆后序遍历，就可以像无向图那样求出 SCC
    for (int i = n - 1; i >= 0; --i)
    {
        int v = vs[i];
        if (!vis[v])
        {
            comp.clear();
            rdfs(v);
            scc.push_back(comp);
        }
    }
    return scc;
}

// 基环树（环套树），英文名叫 pseudotree，基环树森林叫 pseudoforest
// https://en.wikipedia.org/wiki/Pseudoforest
// https://leetcode.cn/problems/maximum-employees-to-be-invited-to-a-meeting/description/ 参加会议的最多员工数

// g 为内向基环树（森林）
void pseudotree(vector<int> g)
{
    vector<int> deg(g.size());
    for (auto w : g)
    {
        deg[w]++;
    } // g 上每个节点的入度

    // 拓扑排序，剪掉 g 上的所有树枝
    // 拓扑排序后 deg 值为 1 的点必定在基环上，为 0 的点必定在树枝上
    // 注：拓扑排序时还可以做 DP，比如给树枝上的每个点标记反向深度
    vector<vector<int>> rg(g.size()); // g 的反图（外向基环树）
    queue<int> q;
    for (int i = 0; i < deg.size(); ++i)
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
        int y = g[x];
        rg[y].push_back(x); // 顺便建一下反图（在这里建反图可以避免加入基环上的边）
        if (--deg[y] == 0)
        {
            q.push(y);
        }
    }

    // 在反图上遍历入环点+树枝
    // 由于考虑了入环点，所以可以遍历到基环树上的所有点
    function<void(int, int)> rdfs = [&](int v, int depth) -> int
    {
        for (auto w : rg[v])
        {
            rdfs(w, depth + 1);
        }
    };

    // 注意可能有多棵基环树
    for (int i = 0; i < deg.size(); ++i)
    {
        if (deg[i] <= 0)
        {
            continue;
        }

        vector<int> ring{i};
        for (int v = g[i]; v != i; v = g[v])
        {
            // 将基环上的点的入度标记为 -1，避免重复访问
            deg[v] = -1;
            // 收集基环上的点
            ring.push_back(v);
        }

        // 遍历基环
        // 特别注意基环大小小于 3 的特殊情况
        for (auto v : ring)
        {
            rdfs(v, 0);
        }
    }
}