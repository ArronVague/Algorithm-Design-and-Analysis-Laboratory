from ast import List


class Solution:
    def corpFlightBookings(self, bookings: List[List[int]], n: int) -> List[int]:
        cnt = [0] * (n + 1)
        for first, last, seats in bookings:
            cnt[first - 1] += seats
            cnt[last] -= seats

        ans = [cnt[0]] * n
        for i in range(1, n):
            ans[i] = ans[i - 1] + cnt[i]
        return ans


# 差分数组
# https://leetcode.cn/problems/corporate-flight-bookings/description/
