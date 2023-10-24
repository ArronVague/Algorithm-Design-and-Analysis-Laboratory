from functools import cache

s = list(map(int, input().split()))
ans = 0
res = float("inf")


@cache
def dfs(l, r, j):
    global res
    if j >= len(t):
        res = min(res, max(l, r))
        return
    dfs(l + t[j], r, j + 1)
    dfs(l, r + t[j], j + 1)


for x in s:
    t = list(map(int, input().split()))
    res = float("inf")
    dfs(0, 0, 0)
    ans += res

print(ans)
