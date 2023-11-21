from ast import List


class Solution:
    def findMinimumOperations(self, s1: str, s2: str, s3: str) -> int:
        if s1[0] == s2[0] == s3[0]:
            pass
        else:
            return -1
        idx = 0
        while idx < min(len(s1), len(s2), len(s3)) and s1[idx] == s2[idx] == s3[idx]:
            idx += 1
        return len(s1) + len(s2) + len(s3) - 3 * idx
