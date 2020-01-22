from functools import reduce
import pandas as pd
import numpy as np
import re

# 列表
print("列表")
l = [1, 2, 3, "apple", "banana"]
print(l)
l.append([1, 2])
print(l)
l.extend([1, 2])
print(l)
l.insert(2, [1, 2])
print(l)
l.insert(2, "orange")
print(l)
print(l.count([1, 2]))
l = [x ** 2 for x in range(10) if x % 2 == 0]
print(l[:-1])
print(l[1:7:2])
print(l)
print(len(l))
print(sum(l))
print(max(l))
print(min(l))
l = [2, 10, -3, 4]
l.sort()
print(l)
l.reverse()
print(l)
print([1, 2, 3] + [2, 3])
print([1, 2] * 3)
l1 = [1, 2, 3]
l2 = ["a", "b", "c", "d"]
print(list(zip(l1, l2)))

# 字符串
print("字符串")
s = "hello world"
print(s.find("or"))
print(s.split(sep=" "))
s = ""
print(s.join("interesting"))
print(s)
s = "       interesting       "
print(s)
print(s.strip())
print(s.count(" "))
print(s.index("i"))

# 元组（不可变）
print("元组")
t = (1, 2, 3, 4)
print(t)
print(t[1:])
print(t[0:4:2])

# 字典
print("字典")
d = {'key': "iamnotkey", 'key2': "iamvalue"}
print(d)
print(d.keys())
print(d.values())
print(d.items())
d.pop('key2')
print(d)

# 集合
print("集合")
s1 = set([x for x in range(10) if x % 2 != 0])
s2 = set([x for x in range(20) if x % 3 == 0])
print(s1)
print(s2)
print(s1.intersection(s2))
print(s1.union(s2))
print(s1.difference(s2))
print(s1.symmetric_difference(s2))

# 内置函数
print("内置函数")
print(list(map(lambda x: x ** 2, [1, 2, 3, 4])))
def judge(x):
    return x % 2 == 0
print(list(filter(judge, [1, 2, 3, 4, 5, 6])))
print(reduce(lambda x, y: x + y, [2, 3, 4, 5, 6], 1))
print(reduce(lambda x, y: x * y, [2, 3, 4, 5, 6]))

# 文件读写
print("文件读写")
f = open("1.txt", "r")
print(f.read())
f.seek(0)
l = f.readlines()
print(l)
f.close()
f = open("1.txt", "w")
f.write("123")
l = ["123", "456", "asdfghjkl"]
f.writelines(l)
f.close()

# 类
print("类")
class person(object):
    def __init__(self, name, gender):
        self.name = name
        self.gender = gender
man1 = person("Kyrie Irving", "male")
print(man1.name)
print(man1.gender)

# 数据科学工具（numpy和pandas）
print("数据科学工具")
print("numpy")
l1 = np.arange(5)
print(l1)
print(l1[2:4])
print(l1[::-1])
print(l1.dtype)
print(l1.shape)
l2 = np.array([np.arange(2), np.arange(2)])
print(l2.shape)
print(l2, l2[0], l2[1], l2[1][1], sep="--")
l3 = np.arange(24).reshape(2, 3, 4)
print(l3)
print(l3.shape)
print(l3[0, 0, 0])
print(l3[0, 0])
print(l3[0])
print(l3[:, 0, 0])
print(l3[:, :, 0])
print(l3.ravel())
l3.shape = (6, 4)
print(l3)
print(l3.transpose())
# linspace用于创建指定数量等间隔的序列，实际生成一个等差数列
l1 = np.linspace(1, 10, 10)
print(l1)
# logspace用于生成等比数列
l2 = np.logspace(0, 2, 5)
print(l2)
l1 = np.arange(0, 4)
l2 = np.arange(1, 5)
print(np.add(l1, l2))
print(np.subtract(l1, l2))
print(np.multiply(l1, l2))
print(np.divide(l1, l2))
print("pandas")
l = [1, 2, 3, "a", "b"]
s1 = pd.Series(l)
print(type(s1))
print(s1)
s2 = pd.Series(l, index=["A", "B", "C", "D", "E"])
print(s2)
d = {'key1': 123, 'key2': 456, 'key3': 789, 'key4': 000}
s3 = pd.Series(d, name='madeviadic')
print(s3)
print(s3[-1:])
dic = {'col1': [1, 2, 3, 4, 5],
       'col2': ["a", "b", "f", "j", "l"],
       'col3': [53, 34, 43, 54, 76]}
df = pd.DataFrame(dic)
print(df)
print(df.iloc[3])
print(df.iloc[3:5, 0:1])

# 正则表达式
text = "hello world"
regex = re.compile(r' ?\w+ ?')
print(regex.findall(text))
res = re.match(r' ?\w+ ?', text)
print(res.group())