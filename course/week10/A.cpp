#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>
#include <cctype>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;
#define MAXN 400000

struct State
{
    int state[9];
    int pos;                                             // 空格位置
    char ch[50];                                         // 记录原始状态到达当前状态的路径(数组不能开太大不然超内存)
} s[MAXN];                                               // 每一个状态对应一个结构体
int factor[9] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320}; // 阶乘数组
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};      // 方向数组
char dirtion[4] = {'u', 'r', 'd', 'l'};
int vis[MAXN]; // 标记某个状态是否被走过
int start;     // 保存原始输入状态的哈希值
State star;    // 原始状态对应的结构体
queue<int> q;  // 这里不能直接放结构体，不然肯定超时

// 哈希映射
int Hash(int s[])
{
    int i, j, temp, num;
    num = 0;
    for (i = 0; i < 9; i++)
    {
        temp = 0;
        for (j = i + 1; j < 9; j++)
        {
            if (s[j] < s[i])
                temp++;
        }
        num += factor[8 - i] * temp;
    }
    return num;
}

// 广搜
bool Bfs()
{
    while (!q.empty())
        q.pop();
    memset(vis, 0, sizeof(vis));
    start = Hash(star.state);
    vis[start] = 1;
    s[start] = star;
    q.push(start);

    while (!q.empty())
    {
        State cur = s[q.front()];
        q.pop();

        int x, y, r, c;
        x = cur.pos / 3;
        y = cur.pos % 3;
        for (int i = 0; i < 4; i++)
        {
            r = x + dir[i][0];
            c = y + dir[i][1];
            if (r < 0 || c < 0 || r >= 3 || c >= 3)
                continue;

            State tmp = cur;
            tmp.state[tmp.pos] = tmp.state[3 * r + c]; // 原先空格位置换成新的编号
            tmp.pos = 3 * r + c;
            tmp.state[tmp.pos] = 9; // 重新更新空格位置

            int hash = Hash(tmp.state); // 求出当前哈希值
            if (vis[hash])
                continue;

            vis[hash] = 1;
            int len = strlen(cur.ch); // 求出前一个状态的路径长度
            tmp.ch[len] = dirtion[i]; // 更新路径
            s[hash] = tmp;            // 赋值
            if (hash == 0)
            { // 如果搜索到目标节点直接输出退出
                printf("%s\n", s[hash].ch);
                return 1;
            }
            q.push(hash); // 入对列
        }
    }
    return 0;
}

int main()
{
    char c;
    while (scanf("%c", &c) != EOF)
    {
        if (c == 'x')
        {
            star.state[0] = 9;
            star.pos = 0;
        }
        else
            star.state[0] = c - '0';
        for (int i = 1; i < 9; i++)
        {
            scanf(" %c", &c);
            if (c == 'x')
            {
                star.pos = i;
                star.state[i] = 9;
            }
            else
                star.state[i] = c - '0';
        }
        getchar();
        int flag = Bfs();
        if (!flag)
            printf("unsolvable\n"); // 无解的情况
    }
    return 0;
}