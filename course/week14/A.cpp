#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

const int maxN = 510;

int main()
{
    int N, M;
    while (cin >> N >> M)
    {
        vector<vector<int>> g(maxN, vector<int>());
        vector<int> indeg(maxN, 0);
        int u, v;
        while (M--)
        {
            cin >> u >> v;
            g[u].push_back(v);
            indeg[v]++;
        }
        priority_queue<int, vector<int>, greater<int>> q;
        vector<int> ans;
        for (int i = 1; i <= N; i++)
            if (indeg[i] == 0)
                q.push(i);
        while (!q.empty())
        {
            int u = q.top();
            q.pop();
            ans.push_back(u);
            for (int v : g[u])
                if (--indeg[v] == 0)
                    q.push(v);
        }
        cout << ans[0];
        for (int i = 1; i < ans.size(); i++)
            cout << " " << ans[i];
    }
    return 0;
}