a, b = map(int, input().split())
c = max(a, b)
if c == 1:
    print("1/1")
elif c == 2:
    print("5/6")
elif c == 3:
    print("2/3")
elif c == 4:
    print("1/2")
elif c == 5:
    print("1/3")
else:
    print("1/6")
