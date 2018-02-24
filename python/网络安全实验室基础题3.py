import base64

s = raw_input()
a = 0
try:
    while True:
        s = base64.decodestring(s)
        a += 1
except Exception:
    print s
print a