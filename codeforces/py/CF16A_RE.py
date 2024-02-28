from itertools import pairwise
import sys

n, m = map(int, sys.stdin.readline().split())
f = [sys.stdin.readline() for _ in range(n)]
flag = True
for r1, r2 in pairwise(f):
    if r1[0] == r2[0]:
        print("NO")
        sys.exit()
    for j in range(1, m):
        if r1[j] != r1[0]:
            print("NO")
            sys.exit()

for j in range(1, m):
    if f[-1][j] != f[-1][0]:
        print("NO")
        sys.exit()

print("YES")
