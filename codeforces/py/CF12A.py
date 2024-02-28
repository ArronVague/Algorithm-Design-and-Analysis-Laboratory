n = 3
m = [str(input()) for _ in range(n)]
if (
    m[0][0] == m[2][2]
    and m[0][1] == m[2][1]
    and m[0][2] == m[2][0]
    and m[1][0] == m[1][2]
):
    print("YES")
else:
    print("NO")
