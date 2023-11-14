# 图论


# 任意两点最短路 Floyd-Warshall  O(n^3)  本质是求 Min-plus matrix multiplication
# 传入邻接矩阵 dis
# dis[v][w] == inf 表示没有 v-w 边


def shortestPathFloydWarshall(dis):
    n = len(dis)
    for k in range(n):
        for i in range(n):
            for j in range(n):
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j])
    return dis
