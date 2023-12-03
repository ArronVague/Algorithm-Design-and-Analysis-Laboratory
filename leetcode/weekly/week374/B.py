from ast import List
from collections import deque


class Solution:
    def minimumAddedCoins(self, coins: List[int], target: int) -> int:
        coins.sort()
        n = len(coins)
        dp = [0] * (n + 1)
        dp[0] = 0

        for i in range(1, n + 1):
            dp[i] = dp[i - 1] + coins[i - 1]

        sums = set()
        for i in range(n):
            for j in range(i + 1, n + 1):
                sums.add(dp[j] - dp[i])

        ans = 0
        for i in range(1, target + 1):
            if i not in sums:
                ans += 1
        return ans
