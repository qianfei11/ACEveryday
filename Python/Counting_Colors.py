#!/usr/bin/env python3
from PIL import Image
from collections import Counter
import prettytable

img = Image.open('Obama.jpg')
size = w, h = img.size
data = img.read()

colors = []
for x in range(w):
    for y in range(h):
        color = data[x, y]
        hex_color = '#' + ''.join([hex(c)[2:].rjust(2, '0') for c in color])

pt = prettytable.PrettyTable(['Color', 'Count'])

for color, count in Counter(colors).items():
    pt.add_row([color, count])

print(pt)
