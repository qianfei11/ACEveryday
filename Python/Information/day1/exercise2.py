#!/usr/bin/env python3
# exercise2.py
s = input('Please input a string: ')
s = list(s)
print('Convert the string to list:', s)
print('Display the first element of the string:', s[0])
print('Display the last element of the string:', s[-1])
print('Display the elements except the first and the last elements in the list:', s[1:-1])
print('Display the length of the list:', len(s))
new_s = ''
for c in s:
    new_s += c
print('Convert the list back to string:', new_s)
new_s = new_s.split(' ')
print('Convert the string to list with respect:', new_s)

