def main():
    t = int(input())
    while t:
        t -= 1
        n = int(input())
        s = str(input())

        def dfs(left, right, c: chr) -> int:
            if left == right:
                # print(s[left], c, int(s[left] != c))
                return int(s[left] != c)
            mid = (left + right) // 2
            l_res, r_res = 0, 0
            for i in range(mid + 1):
                l_res += s[i] != c
            for i in range(mid + 1, right + 1):
                r_res += s[i] != c
            # print(chr(ord(c) + 1))
            return min(
                l_res + dfs(mid + 1, right, chr(ord(c) + 1)),
                r_res + dfs(left, mid, chr(ord(c) + 1)),
            )

        print(dfs(0, n - 1, "a"))


main()
