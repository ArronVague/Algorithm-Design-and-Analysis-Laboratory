#include <bits/stdc++.h>
using namespace std;

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

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> dis(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> dis[i][j];
        }
    }
    int mst = 0;
    vector<vector<int>> edges;
    mstPrim(dis, 0, mst, edges);
    cout << mst;
    return 0;
}