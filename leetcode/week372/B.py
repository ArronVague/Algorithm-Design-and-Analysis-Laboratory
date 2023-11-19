from ast import List
from collections import deque


class Solution:
    def minimumSteps(self, s: str) -> int:
        one = deque()
        ans = 0
        for i, c in enumerate(s):
            if c == "1":
                one.append(i)
            else:
                if len(one) > 0:
                    idx = one.popleft()
                    ans += i - idx
                    one.append(i)
        return ans
