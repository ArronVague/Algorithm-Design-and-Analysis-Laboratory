from ast import List


class Solution:
    def maximumXorProduct(self, a: int, b: int, n: int) -> int:
        MOD = 10**9 + 7
        ans = 0

        def dfs(i, x, mask):
            nonlocal ans
            if i == -1:
                ans = max(ans, (a ^ x) * (b ^ x) % MOD)
            mask |= 1 << i
            ai = a & (1 << i)
            bi = b & (1 << i)
            if ai == bi:
                x |= (ai ^ 1) << i
                dfs(i - 1)
            else:
                maska = mask & a
                maskb = mask & b
                t_x1 = x | 1 << i
                if (maska ^ x) * (maskb ^ x) == (maska ^ t_x1) * (maskb ^ t_x1):
                    dfs(i - 1, x, mask)
                    dfs(i - 1, t_x1, mask)
                elif (maska ^ x) * (maskb ^ x) > (maska ^ t_x1) * (maskb ^ t_x1):
                    dfs(i - 1, x, mask)
                else:
                    dfs(i - 1, t_x1, mask)

        return ans
