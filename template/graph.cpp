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