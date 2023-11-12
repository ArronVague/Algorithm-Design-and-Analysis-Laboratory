from ast import List

# 可以分解成相同的子问题
# 递归边界：


class Solution:
    def minOperations(self, nums1: List[int], nums2: List[int]) -> int:
        n = len(nums1)
        if n < 2:
            return 0

        @cache
        def dfs(i, m, n):
            x, y = nums1[i], nums2[i]
            # print(i, x, y, m, n)
            if i == 0:
                if x <= m and y <= n:
                    return 0
                if x <= n and y <= m:
                    return 1
                return float("inf")
            no = yes = float("inf")
            if x <= m and y <= n:
                no = dfs(i - 1, m, n)
            if x <= n and y <= m:
                yes = dfs(i - 1, m, n) + 1
            # print(i, no, yes)
            return min(no, yes)

        ans = min(
            dfs(n - 2, nums1[-1], nums2[-1]), dfs(n - 2, nums2[-1], nums1[-1]) + 1
        )
        # ans = dfs(n - 2, nums2[-1], nums1[-1]) + 1
        if ans == float("inf"):
            return -1
        return ans
