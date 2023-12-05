#include <bits/stdc++.h>
using namespace std;

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

int main()
{
    int n, m;
    cin >> n >> m;
    int u, v, w;
    vector<vector<int>> dis(n, vector<int>(n, 1e9));
    while (m--)
    {
        cin >> u >> v >> w;
        dis[u - 1][v - 1] = dis[v - 1][u - 1] = w;
    }
    for (int i = 0; i < n; ++i)
    {
        dis[i][i] = 0;
    }
    dis = shortestPathFloydWarshall(dis);
    for (auto &es : dis)
    {
        for (auto &e : es)
        {
            cout << e << " ";
        }
        cout << endl;
    }
    return 0;
}