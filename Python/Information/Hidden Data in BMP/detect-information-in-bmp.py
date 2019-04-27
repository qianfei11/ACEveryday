#!/usr/bin/env python
import struct

with open('dakota-johnson-1-hidden.bmp', 'rb') as f_in:
    byte_in = bytearray(f_in.read())
    if byte_in[0x0A] != 0x36:
        print '[*] hidden information detected!'
        offset = byte_in[0x0A]
        info = byte_in[0x36:offset]
        print info

