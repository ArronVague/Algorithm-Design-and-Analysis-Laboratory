#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

int N, M;

int main()
{
    int cnt = 1;
    while (cin >> N)
    {
        vector<string> a(N);
        unordered_map<string, int> m;
        for (int i = 0; i < N; ++i)
        {
            cin >> a[i];
            m[a[i]] = i;
        }
        cin >> M;
        vector<int> indeg(N);
        vector<vector<int>> g(N);
        while (M--)
        {
            string s;
            getline(cin, s);
            int pos = s.find(' ');
            string pre = s.substr(0, pos);
            string suf = s.substr(pos + 1);
            g[m[pre]].push_back(m[suf]);
        }
        queue<int> q;
        for (int i = 0; i < N; ++i)
        {
            if (indeg[i] == 0)
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            for (auto &nxt : g[cur])
            {
                if (--indeg[nxt] == 0)
                {
                    q.push(nxt);
                }
            }
        }
    }
    return 0;
}