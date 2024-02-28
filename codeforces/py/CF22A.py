n = int(input())
a = list(map(int, input().split()))
a.sort()
flag = False
for i in range(1, n):
    if a[i] != a[i - 1]:
        print(a[i])
        flag = True
        break
if not flag:
    print("NO")
