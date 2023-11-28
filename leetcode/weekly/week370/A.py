from ast import List


class Solution:
    def findChampion(self, grid: List[List[int]]) -> int:
        n = len(grid)
        deg = [0] * n
        for i in range(n):
            for j in range(n):
                if i == j:
                    continue
                if grid[i][j] == 1:
                    deg[j] += 1
        for i, d in enumerate(deg):
            if d == 0:
                return i