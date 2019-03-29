#!/usr/bin/env python3
a = eval(input('Please input number a: '))
b = eval(input('Please input number b: '))
output = '''
1. Addition
2. Subtraction
3. Multiplication
4. Division
5. Quit
Enter the operation you need to perform: 
'''
while True:
    print(output)
    choice = eval(input())
    if choice == 1:
        res = a + b
        print('Result is: {}'.format(str(res)))
        break
    elif choice == 2:
        res = a - b
        print('Result is: {}'.format(str(res)))
        break
    elif choice == 3:
        res = a * b
        print('Result is: {}'.format(str(res)))
        break
    elif choice == 4:
        res = a / b
        print('Result is: {}'.format(str(res)))
        break
    elif choice == 5:
        break
    else:
        print('Enter the correct option: ')
        continue
