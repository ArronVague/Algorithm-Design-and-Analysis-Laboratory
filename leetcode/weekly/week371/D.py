from ast import List

"""
判断两数是否满足强数对的逆推条件
abs(x - y) <= min(x - y)
if x > y:
    x - y <= y
else:
    y - x <= x

x <= 2y
x / y <= 2
y <= 2x
y / x <= 2
"""
# 判断两数是否满足强数对的逆推条件
# abs(x - y) <= min(x - y)
# if x > y:
#


class Solution:
    def maximumStrongPairXor(self, nums: List[int]) -> int:
        k = max(nums).bit_length() - 1
        ans = mask = 0
        for i in range(k, -1, -1):
            mask |= 1 << i
            tmp = ans | 1 << i
            seen = set()
            for x in nums:
                x &= mask
                if tmp ^ x in seen:
                    ans = tmp
                    break
                seen.add(x)
        return ans
