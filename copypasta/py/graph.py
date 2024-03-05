from heapq import heappop, heappush
from math import inf

# 图论


# 堆优化 Dijkstra（适用于稀疏图）
# n: 节点数
# st: 起点
# roads: (x, y, d) 表示 x->y 的距离为 d
# 返回从 st 出发的最短路长度
def shortestPathDijkstra(n, st, roads):
    g = [[] for _ in range(n)]  # 邻接表
    for x, y, d in roads:
        g[x].append((y, d))
        g[y].append((x, d))  # 有向图去掉这一行

    dis = [inf] * n
    dis[st] = 0
    h = [(0, 0)]
    while h:
        dx, x = heappop(h)
        if dx > dis[x]:
            continue
        for y, d in g[x]:  # 尝试更新 x 的邻居的最短路
            new_dis = dx + d
            if new_dis < dis[y]:
                # 就目前来说，最短路必须经过 x
                dis[y] = new_dis
                heappush(h, (new_dis, y))
    return dis


# 朴素 Dijkstra（适用于稠密图）
# g: 邻接矩阵，g[i][j] 表示 i->j 的距离，inf 表示没有 i->j 的边
# st: 起点
# 返回从 st 出发的最短路长度
def shortestPathDijkstra2(g, st):
    n = len(g)
    dis = [inf] * n
    dis[st] = 0
    done = [False] * n
    while True:
        x = -1
        for i, ok in enumerate(done):
            if not ok and (x < 0 or dis[i] < dis[x]):
                x = i
        if x < 0:
            break
        done[x] = True  # 最短路长度已确定（无法变得更小）
        dx = dis[x]
        for y, d in enumerate(g[x]):  # 尝试更新 x 的邻居的最短路
            new_dis = dx + d
            if new_dis < dis[y]:
                # 就目前来说，最短路必须经过 x
                dis[y] = new_dis
    return dis


# 任意两点最短路 Floyd-Warshall  O(n^3)  本质是求 Min-plus matrix multiplication
# 传入邻接矩阵 dis
# dis[v][w] == inf 表示没有 v-w 边
# dis[v][v] == 0
# 返回 dis[v][w] 表示 v->w 的最短路长度
def shortestPathFloydWarshall(dis):
    n = len(dis)
    for k in range(n):
        for i in range(n):
            for j in range(n):
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j])
    return dis
