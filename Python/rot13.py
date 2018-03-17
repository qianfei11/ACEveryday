#!/usr/bin/python

s = input()
s1 = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz'
s2 = 'NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm'
l1 = list(s1)
l2 = list(s2)
d = dict(zip(l1, l2))
l1 = []
for i in s:
    if i in d:
        data = d.get(i)
    else:
        data = i
    l1.append(data)

l2 = ['']
for i in l1:
    l2[0] = l2[0] + i

print(l2[0])