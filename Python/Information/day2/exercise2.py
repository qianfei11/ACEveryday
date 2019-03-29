#!/usr/bin/env python3
score = input('Enter the mark: ')
score = eval(score)
res = ''
if score <= 100 and score > 90:
    res = 'S'
elif score <= 90 and score > 80:
    res = 'A'
elif score <= 80 and score > 70:
    res = 'B'
elif score <= 70 and score > 60:
    res = 'C'
elif score <= 60 and score > 50:
    res = 'D'
elif score <= 50 and score > 40:
    res = 'E'
elif score <= 40 and score >= 0:
    res = 'F'
else:
    res = ''
if res == '':
    print('Your score is illegal!')
else:
    print('You have scored {} grade'.format(res))
