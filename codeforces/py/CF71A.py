n = int(input())
s = [input() for _ in range(n)]
for word in s:
    if len(word) <= 10:
        print(word)
        continue
    print(word[0] + str(len(word) - 2) + word[-1])
