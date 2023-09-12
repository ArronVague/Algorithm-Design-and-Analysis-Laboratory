case = 0
while True:
    N = int(input())
    if N == 0:
        break
    if case:
        print()
    base = 1234
    flag = False
    while base * N <= 98765:
        s = set(str(base * N)) | set(str(base))
        if len(s) == 10 or (len(s) == 9 and '0' not in s):
            flag = True
            print(base * N, '/', base if len(str(base)) == 5 else '0'
                   + str(base), '=', N)
        base += 1
    if not flag:
        print('There are no solutions for', str(N) + '.')
    case += 1