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

// 单源最短路 Dijkstra
// 适用于稀疏图 O(mlogm)
// 这里实现的是懒更新（lazy）版本的 Dijkstra，复杂度为 O(mlogm)
// 若在插入堆时元素已在堆中，改成直接更新元素，而不是插入元素，可使复杂度降为 O(mlogn)
//
// st 也可以是一个点集，这相当于同时对多个点跑最短路
// 视频讲解（第四题）https://www.bilibili.com/video/BV1wj411G7sH/
// 可视化 https://visualgo.net/zh/sssp
// https://oi-wiki.org/graph/shortest-path/#dijkstra
// 最短路问题笔记 https://www.luogu.com.cn/blog/SCN/zui-duan-lu-wen-ti-bi-ji
//
// 模板题 https://www.luogu.com.cn/problem/P3371 https://www.luogu.com.cn/problem/P4779
//       https://codeforces.com/problemset/problem/20/C
//       LC743 https://leetcode-cn.com/problems/network-delay-time/
struct dijkstraPair
{
    ll v, dis;
    bool operator<(const dijkstraPair &rhs) const
    {
        return dis > rhs.dis;
    }
};

vector<ll> shortestPathDijkstra(int n, int st, vector<vector<int>> edges)
{
    struct neighbor
    {
        int to, wt;
    };
    vector<vector<neighbor>> g(n, vector<neighbor>());
    for (auto &e : edges)
    {
        int v = e[0], w = e[1], wt = e[2];
        g[v].push_back({w, wt});
        // 有向图需要注释掉下面这行
        // g[w].push_back({v, wt});
    }

    const ll inf = (1ll << 31) - 1;
    vector<ll> dist(n, inf);
    dist[st] = 0;
    vector<int> from(n, -1);
    priority_queue<dijkstraPair> h;
    h.push({st, 0});
    while (h.size())
    {
        auto p = h.top();
        h.pop();
        int v = p.v;
        if (p.dis > dist[v])
        {
            continue;
        }
        for (auto &e : g[v])
        {
            int w = e.to;
            int newD = dist[v] + e.wt;
            if (newD < dist[w])
            {
                dist[w] = newD;
                from[w] = v;
                h.push({w, dist[w]});
            }
        }
    }
    return dist;
}
// 另一种 Dijkstra 写法
// 适用于稠密图 O(n^2)
// 建模 https://codeforces.com/contest/1528/problem/D
// 传入参数
// 传入参数g是邻接矩阵，g[v][i].first表示v的第i条边的终点，g[v][i].second表示v的第i条边的边权
vector<ll> shortestPathDijkstra2(vector<vector<pair<int, int>>> g, int st)
{
    int n = g.size();

    // 2^31 - 1容易爆int，因此用long long
    const ll inf = (1ll << 31) - 1;
    vector<ll> dis(n, inf);
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
        for (auto &e : g[v])
        {
            int w = e.first, wt = e.second;
            int newD = dis[v] + wt;
            if (newD < dis[w])
            {
                dis[w] = newD;
            }
        }
    }
}

// 单源最短路 SPFA O(nm)   队列优化的 Bellman-Ford
// 对于构建一个让 SPFA 跑到最坏情况的（网格）图，见 main/testutil/rand.go 中的 GraphHackSPFA
// 可视化 https://visualgo.net/zh/sssp
// https://oi-wiki.org/graph/shortest-path/#bellman-ford
// https://cp-algorithms.com/graph/bellman_ford.html
// https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm
//
// 模板题 https://www.luogu.com.cn/problem/P3385
vector<ll> shortestPathSPFA(int n, int st, vector<vector<int>> edges)
{
    struct neighbor
    {
        int to, wt;
    };
    vector<vector<neighbor>> g(n, vector<neighbor>());
    for (auto &e : edges)
    {
        int v = e[0], w = e[1], wt = e[2];
        g[v].push_back({w, wt});
        // 有向图需要注释掉下面这行
        // g[w].push_back({v, wt});
    }

    const ll inf = (1ll << 31) - 1;
    vector<ll> dist(n, inf);
    dist[st] = 0;
    queue<int> q;
    q.push(st);
    vector<bool> inQ(n);
    inQ[st] = true;
    vector<int> relaxedCnt(n);
    while (q.size())
    {
        int v = q.front();
        q.pop();
        inQ[v] = false;
        for (auto &e : g[v])
        {
            int w = e.to;
            int newD = dist[v] + e.wt;
            if (newD < dist[w])
            {
                dist[w] = newD;
                relaxedCnt[w] = relaxedCnt[v] + 1;
                if (relaxedCnt[w] >= n)
                {
                    return vector<ll>();
                }
                if (!inQ[w])
                {
                    inQ[w] = true;
                    q.push(w);
                }
            }
        }
    }
    // 注意循环完了 inQ[i] 都是 false

    // EXTRA: 只是找负环的话，初始时将所有点入队即可
    // 注意不能只从一个点出发找负环，因为可能这个点无法到达负环
    // https://www.luogu.com.cn/problem/P2868

    // EXTRA: 打印负环
    // https://cp-algorithms.com/graph/finding-negative-cycle-in-graph.html
    // https://algs4.cs.princeton.edu/code/edu/princeton/cs/algs4/BellmanFordSP.java.html
    return dist;
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
// 传入参数dis是邻接矩阵，dis[v][w]表示v-w的边权，inf表示没有v-w边
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
pair<int, vector<pair<int, int>>> mstPrim(vector<vector<int>> &dis, int root)
{
    int n = dis.size();
    // inf根据题目定，不要太大
    int inf = 1e5;

    vector<pair<int, int>> edges;
    edges.reserve(n - 1);

    vector<pair<int, int>> minD(n, {inf, 0}); // minD[i].first represents the minimum distance from the current MST to vertex i, and minD[i].second represents the corresponding edge (minD[i].second, i).
    minD[root].first = 0;

    vector<bool> inMST(n, false); // Initially, no vertices are in the MST.

    int mst = 0;

    while (true)
    {
        // Find the vertex with the minimum distance to the current MST.
        int v = -1;
        for (int w = 0; w < n; ++w)
        {
            // 没有对非连通图的处理
            // if (!inMST[w] && (v == -1 || minD[w].first < minD[v].first))
            // {
            //     v = w;
            // }
            if (!inMST[w] && minD[w].first < inf && (v == -1 || minD[w].first < minD[v].first))
            {
                v = w;
            }
        }

        if (v == -1)
        { // MST is found.
            break;
        }

        // Add the vertex to the MST.
        inMST[v] = true;
        mst += minD[v].first;

        if (v != root)
        {
            edges.emplace_back(minD[v].second, v);
        }

        // Update minD.
        for (int w = 0; w < n; ++w)
        {
            if (!inMST[w] && dis[v][w] < minD[w].first)
            {
                minD[w].first = dis[v][w];
                minD[w].second = v;
            }
        }
    }

    return {mst, edges};
}

// 二分图判定+染色
// 注：二分图也叫偶图
// https://en.wikipedia.org/wiki/Bipartite_graph
// https://oi-wiki.org/graph/bi-graph/#_3
// https://cp-algorithms.com/graph/bipartite-check.html
// 辅助证明 https://codeforces.com/contest/1839/problem/E
//
// 模板题 LC886 https://leetcode.cn/problems/possible-bipartition/
// https://codeforces.com/problemset/problem/1093/D
// https://www.luogu.com.cn/problem/P6185
// https://codeforces.com/problemset/problem/1537/F
bool isBipartite(vector<vector<int>> g)
{
    // 0 表示未访问该节点
    vector<int> color(g.size());
    function<bool(int, int)> f = [&](int v, int c) -> bool
    {
        color[v] = c;
        for (auto w : g[v])
        {
            // 如果要分组，用 3^c，便于填入下标；如果要根据染色来 +/-，用 -c
            if (color[w] == c || color[w] == 0 && !f(w, -c))
            {
                return false;
            }
        }
        return true;
    };

    for (int i = 0; i < color.size(); ++i)
    {
        int c = color[i];
        if (c != 0)
        {
            continue;
        }
        if (!f(i, 1))
        {
            return false;
        }
    }
    return true;
}

// 二分图最大匹配 - 匈牙利算法/增广路算法 O(nm)    Hungarian algorithm
// 注：更推荐用 Dinic，可以达到 O(m√n) 的复杂度（而且这个复杂度一般不会跑满）
// - 超级源点连左部，右部连超级汇点，所有边的容量均为 1，最大流即最大匹配
// - 代码 https://www.luogu.com.cn/record/123020820
// 【推荐】可视化 https://visualgo.net/zh/matching
//        选择「图示 - CP4 3.11a*」，然后选择「增广路 - 标准」
// https://www.renfei.org/blog/bipartite-matching.html 推荐
// https://oi-wiki.org/topic/graph-matching/bigraph-match/
// https://zhuanlan.zhihu.com/p/62981901
// https://en.wikipedia.org/wiki/Hall%27s_marriage_theorem
// https://www.geeksforgeeks.org/maximum-bipartite-matching/
// https://algs4.cs.princeton.edu/code/edu/princeton/cs/algs4/BipartiteMatching.java.html
// 有关随机贪心(匹配)预处理的 hack https://bzoj.blog.uoj.ac/blog/2427
//
// 模板题 https://www.luogu.com.cn/problem/P3386 https://www.luogu.com.cn/problem/B3605
// LC1349 https://leetcode.cn/problems/maximum-students-taking-exam/
// LCP04 https://leetcode-cn.com/problems/broken-board-dominoes/
// LC2123 https://leetcode.cn/problems/minimum-operations-to-remove-adjacent-ones-in-matrix/
vector<int> maxBipartiteMatchingHungarian(vector<vector<int>> &g)
{
    int n = g.size();
    vector<int> match(n, -1);
    vector<int> vis(n, -1);
    int cnt = 0;

    for (int root = 0; root < n; ++root)
    {
        if (match[root] != -1)
        {
            continue;
        }

        function<bool(int)> dfs = [&](int v) -> bool
        {
            vis[v] = root;
            for (int w : g[v])
            {
                int mw = match[w];
                if (mw == -1 || (vis[mw] != root && dfs(mw)))
                {
                    match[w] = v;
                    match[v] = w;
                    return true;
                }
            }
            return false;
        };

        if (dfs(root))
        {
            cnt++;
        }
    }
    return match;
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