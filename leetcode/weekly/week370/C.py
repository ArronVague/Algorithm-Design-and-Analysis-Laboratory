from ast import List


class Solution:
    def maximumScoreAfterOperations(self, edges: List[List[int]], values: List[int]) -> int:
        n = len(values)
        tree = [[0] * n for _ in range(n)]
        for x, y in edges:
            tree[x][y] = 1
            tree[y][x] = 1

        def dfs_need(cur, parent):
            cnt = [i for i, d in enumerate(tree[cur]) if i != parent and d == 1]
            if len(cnt) == 0:
                return 0
            no_need = sum(dfs_no_need(i, cur) for i, d in enumerate(tree[cur]) if (i != parent and d == 1))
            need = values[cur] + sum(dfs_need(i, cur) for i, d in enumerate(tree[cur]) if (i != parent and d == 1))
            if cur == 7:
                print(cur, no_need, need)
            return max(no_need, need)
            
        def dfs_no_need(cur, parent):
            cnt = [i for i, d in enumerate(tree[cur]) if i != parent and d == 1]
            if len(cnt) == 0:
                return values[cur]
            return values[cur] + sum(dfs_no_need(i, cur) for i, d in enumerate(tree[cur]) if (i != parent and d == 1))
        

        return dfs_need(0, -1)
    
[[0,1],[0,2],[0,3],[2,4],[4,5]]
[5,2,5,2,1,1]
[[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]]
[20,10,9,7,4,3,5]
[[7,0],[3,1],[6,2],[4,3],[4,5],[4,6],[4,7]]
[2,16,23,17,22,21,8,6]

11
40
113