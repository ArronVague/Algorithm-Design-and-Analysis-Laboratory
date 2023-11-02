n, m = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()
idx = n - 1
while m > 0 and idx >= 0:
    print(arr[idx], end=" ")
    idx -= 1
    m -= 1
