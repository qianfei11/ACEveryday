import os

def fex(dirpwd):
    names = os.listdir(dirpwd)
    print(names)
    after_list = []
    for name in names:
        if '.' not in name:
            continue
        tmp = name.split('.')
        after_list.append(tmp[-1])
    after_list = list(set(after_list))
    return after_list
