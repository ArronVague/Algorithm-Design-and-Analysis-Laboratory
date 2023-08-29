import sys

text = str(sys.stdin.read())
for i, x in enumerate(text):
    if x.isalpha():
        text[i] = x.lower()
    else:
        text[i] = " "
s = set(text.split())
print(s)
