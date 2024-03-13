from collections import Counter


class Solution:
    def maximumOddBinaryNumber(self, s: str) -> str:
        n = len(s)
        c = Counter(s)
        ans = ["1"] * (c["1"] - 1) + ["0"] * c["0"] + ["1"]
        return "".join(ans)


sol = Solution()
s = "010"
print(sol.maximumOddBinaryNumber(s))
