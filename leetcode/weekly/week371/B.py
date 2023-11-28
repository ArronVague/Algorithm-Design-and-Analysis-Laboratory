from ast import List


class Solution:
    def findHighAccessEmployees(self, access_times: List[List[str]]) -> List[str]:
        n = len(access_times)
        if n < 3:
            return []
        access_times.sort(key=lambda x: (x[0], x[1]))
        ans = set()

        for i in range(n - 2):
            if (
                access_times[i][0] == access_times[i + 2][0]
                and int(access_times[i + 2][1]) - int(access_times[i][1]) < 100
            ):
                ans.add(access_times[i][0])
        return list(ans)
