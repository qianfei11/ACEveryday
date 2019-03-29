#!/usr/bin/env python
t1 = tuple([12, 3, 4, 5, 5, 7])
t2 = tuple([100])
t3 = t1+t2
print('The max of the tuple is {}'.format(max(t3)))
print('The min of the tuple is {}'.format(min(t3)))
print('Slice tuple from 2 to 5 (t3[2:5]) :', t3[2:5])
tmp = []
for e in t3:
    if e == 3:
        continue
    else:
        tmp.append(e)
del t3
t3 = tuple(tmp)
print('Delete 3 from the tuple: ', t3)
print('Length of the new tuple: ', len(t3))
tmp = []
for e in t3: 
    if e == 12:
        tmp.append(98)
        continue
    else:
        tmp.append(e)
del t3
t3 = tuple(tmp)
print('Replace 12 with 98: ', t3)
