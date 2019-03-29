#!/usr/bin/env python3
print('Let\'s find out two numbers\' relationship!')
while True:
    num = input('Please input your num(two digits): ')
    tmp = list(num)
    if len(tmp) != 2:
        print('Your input should be two digits!')
        continue
    res = ''
    if tmp[0] > tmp[1]:
        res = 'greater than'
    elif tmp[0] == tmp[1]:
        res = 'equal to'
    else:
        res = 'less than'
    if res != '':
        print('The 1st digit of the number is {} 2nd digit of the number.'.format(res))
        break
