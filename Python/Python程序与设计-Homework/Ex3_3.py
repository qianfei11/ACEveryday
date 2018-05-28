import os
import random

def fs(dirname, s):
    flag = 0
    txt_file = []
    for item in os.listdir():
        if 'txt' in item:
            txt_file.append(item)
            flag = 1
    if flag == 0:
        f = open('new.txt', 'w')
        f.write(s)
        f.close()
    else:
        random.choice(txt_file)
        f = open(txt_file, 'w')
        f.write(s)
        f.close()

if __name__ == '__main__':
    s = input()
    path = os.getcwd()
    fs(path, s)