from ast import List
from itertools import accumulate


class Solution:
    def minGroups(self, intervals: List[List[int]]) -> int:
        cnt = [0] * (10**6 + 1)
        for left, right in intervals:
            cnt[left - 1] += 1
            cnt[right] -= 1
        return max(s for s in accumulate(cnt[:-1]))


# 差分/贪心
# 这里用了差分，理解为上下车问题
# https://leetcode.cn/problems/divide-intervals-into-minimum-number-of-groups/description/
