#include <bits/stdc++.h>
using namespace std;

pair<int, vector<pair<int, int>>> mstPrim(vector<vector<int>> &dis, int root)
{
    int n = dis.size();
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
            // if (!inMST[w] && (v == -1 || minD[w].first < minD[v].first))
            // {
            //     v = w;
            // }
            // 没有对非连通图的处理
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

int main()
{
    int N, M;
    cin >> N >> M;
    int X, Y, Z;
    vector<vector<int>> dis(N, vector<int>(N, 1e5));
    while (M--)
    {
        cin >> X >> Y >> Z;
        dis[X - 1][Y - 1] = dis[Y - 1][X - 1] = min(dis[X - 1][Y - 1], Z);
    }
    auto [mst, edges] = mstPrim(dis, 1);
    if (edges.size() < N - 1)
    {
        cout << "orz" << endl;
    }
    else
    {
        cout << mst << endl;
    }
}