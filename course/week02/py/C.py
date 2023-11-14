MOD = 10 ** 9 + 7
base = 31

def getHash(s: str):
    res = 0
    for x in s:
        res = (res * base + ord(x)) % MOD
    return res

N = int(input())
s = set()
for i in range(N):
    s.add(getHash(input()))
print(len(s))