#!/usr/bin/env python3
# exercise3.py
l1 = [1, 10, 3, 14]
l2 = [7, 9, 0, 2]
print('The first list:', l1)
print('The second list:', l2)
l3 = l1 + l2
# print(type(l3))
print('Add two list:', l3)
print('The maximum of the third list:', max(l3))
print('The minimum of the third list:', min(l3))
l3.sort()
print('Sort the third list:', l3)
l3.reverse()
print('Reverse the third list:', l3)
l3.remove(2)
print('Remove element \'2\' in the list:', l3)
l3.pop()
print('Pop the last element of the list:', l3)

