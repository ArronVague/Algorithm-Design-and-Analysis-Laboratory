if __name__=="__main__":
    n, r = map(int, input().split())
    ans = []
    for i in range(1 << n):
        cnt = 0
        for j in range(n):
            if i & (1 << j):
                cnt += 1
        if cnt == r:
            res = []
            for j in range(n):
                if i & (1 << j):
                    res.append(j + 1)
            ans.append(res)
    ans.sort()
    for res in ans:
        for x in res:
            print("{:3d}".format(x), end=' ')
        print()