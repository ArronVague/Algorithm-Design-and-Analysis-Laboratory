l, r, k = map(int, input().split())
ans = 1
flag = False
while True:
    if l <= ans <= r:
        flag = True
        print(ans, end=' ')
    if ans > r:
        break
    ans *= k

if not flag:
    print(-1)