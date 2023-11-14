m, n = map(int, input().split())
ans = 0
for i in range(m):
    s = list(map(int, input().split()))
    for j, x in enumerate(s):
        if i == 0 or i == m - 1 or j == 0 or j == n - 1:
            ans += x
print(ans)
