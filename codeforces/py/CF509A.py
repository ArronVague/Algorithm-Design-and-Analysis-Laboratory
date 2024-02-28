n = int(input())
m = [[1 for _ in range(n)] for _ in range(n)]
ans = 1
for i in range(1, n):
    for j in range(1, n):
        m[i][j] = m[i - 1][j] + m[i][j - 1]
        ans = max(ans, m[i][j])
print(ans)
