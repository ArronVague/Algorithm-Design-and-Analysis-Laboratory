#include <iostream>
using namespace std;

const int maxN = 50001;
int fa[maxN * 3];
int N, K;
int D, X, Y;

void init()
{
    for (int i = 1; i <= maxN; i++)
        fa[i] = i;
}

int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y)
{
    fa[find(x)] = find(y);
}

int main()
{
    cin >> N >> K;
    init();
    int ans = 0;
    while (K--)
    {
        cin >> D >> X >> Y;
        if (X > N || Y > N)
        {
            ans++;
            continue;
        }
        if (D == 1)
        {
            if (find(X) == find(Y + N) || find(X) == find(Y + 2 * N))
                ans++;
            else
            {
                merge(X, Y);
                merge(X + N, Y + N);
                merge(X + 2 * N, Y + 2 * N);
            }
        }
        else
        {
            if (find(X) == find(Y) || find(X) == find(Y + 2 * N))
                ans++;
            else
            {
                merge(X, Y + N);
                merge(X + N, Y + 2 * N);
                merge(X + 2 * N, Y);
            }
        }
        // for (int i = 1; i <= N; i++)
        //     cout << fa[i] << " ";
        // cout << endl;
    }
    cout << ans;
}