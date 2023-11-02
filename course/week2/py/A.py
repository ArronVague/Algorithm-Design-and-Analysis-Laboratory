n = int(input())
a = list(map(int, input().split(' ')))
ans = [0] * n
s = []
for i, x in enumerate(a):
    while s and a[s[-1]] < x:
        ans[s.pop()] = i + 1
    s.append(i)
print(*ans, end=' ')