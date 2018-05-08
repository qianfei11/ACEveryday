#!/usr/bin/python
import requests
import os

url = input()
root = "D://pics//"
path = root + url.split('/')[-1]
try:
    if not os.path.exists(root):
        os.mkdir(root)
    if not os.path.exists(path):
        r = requests.get(url)
        with open(path, 'wb') as f:
            f.write(r.content)
            f.close()
            print("Image saved successfully!\n")
    else:
        print("Image already exists!\n")
except:
    print("Failed!\n")

