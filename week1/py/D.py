from bisect import bisect_left
from sortedcontainers import SortedList

cnt = 1
while True:
    N, Q = map(int, input().split())
    if N == 0 and Q == 0:
        break
    arr = SortedList()
    for _ in range(N):
        x = int(input())
        arr.add(x)
    print("CASE# {}:".format(cnt))
    cnt += 1
    for _ in range(Q):
        # print(arr)
        q = int(input())
        idx = bisect_left(arr, q)
        # print("yes" + str(idx))
        if idx < N and arr[idx] == q:
            print(q, "found at", idx + 1)
        else:
            print(q, "not found")
