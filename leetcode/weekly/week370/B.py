from ast import List


class Solution:
    def findChampion(self, n: int, edges: List[List[int]]) -> int:
        deg = [0] * n
        for i, j in edges:
            deg[j] += 1
        win = [i for i, d in enumerate(deg) if d == 0]
        if len(win) == 0 or len(win) > 1:
            return -1
        return win[0]