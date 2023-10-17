n = int(input())
arr = list(map(int, input().split()))
max_sum = 0
ans = float("-inf")
for x in arr:
    max_sum = max(0, max_sum) + x
    ans = max(ans, max_sum)
print(ans)
