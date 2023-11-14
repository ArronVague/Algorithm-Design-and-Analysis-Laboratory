while True:
    cnt = 1
    try:
        N = int(input())  # 读取输入
        a = list(map(int, input().split()))  # 读取一行多个输入
        ans = 0
        for i in range(N):
            res = 1
            for j in range(i, N):
                res *= a[j]
                ans = max(ans, res)
        print("Case #{}: The maximum product is {}.".format(cnt, ans))
        print()
        cnt += 1
    except EOFError:
        break