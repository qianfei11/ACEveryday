#!/usr/bin/python

s = input('Input your id(1--17bit):')
a = list(s)
for i in range(17):
    a[i] = eval(a[i])
w = [7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2]
s = 0
for i in range(17):
    s += a[i] * w[i]
s %= 11
d = {0:'1', 1:'0', 2:'X', 3:'9', 4:'8', 5:'7', 6:'6', 7:'5', 8:'4', 9:'3', 10:'2'}
if s in d:
    print(d.get(s))