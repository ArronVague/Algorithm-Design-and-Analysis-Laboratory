#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

const int maxN = 510;
int N, M;
int x, y;
priority_queue<int, vector<int>, greater<int>> q;
int indeg[maxN];
vector<int> edge[maxN];
vector<int> ans;

int main()
{
    while (cin >> N >> M)
    {
        ans.clear();
        for (int i = 0; i < maxN; i++)
        {
            edge[i].clear();
        }
        while (M--)
        {
            cin >> x >> y;
            edge[x].push_back(y);
            indeg[y]++;
        }
        for (int i = 1; i <= N; i++)
            if (indeg[i] == 0)
                q.push(i);
        while (!q.empty())
        {
            int u = q.top();
            ans.push_back(u);
            q.pop();
            for (int v : edge[u])
            {
                indeg[v]--;
                if (indeg[v] == 0)
                    q.push(v);
            }
        }
        cout << ans[0];
        for (int i = 1; i < ans.size(); i++)
            cout << " " << ans[i];
        cout << endl;
    }
    return 0;
}