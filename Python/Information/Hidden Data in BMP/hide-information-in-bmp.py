import struct

with open('dakota-johnson-2.bmp', 'rb') as f_in, open('dakota-johnson-2-hidden.bmp', 'wb') as f_out:
    byte_in = bytearray(f_in.read())
    flag = b'ZJGSCTF{h0w_c4n_U_f1nd_1nf0m4t10n_1n_4_6mp}'
    byte_out = bytearray(b'0' * (len(byte_in) + len(flag)))
    byte_out[0:0x02] = byte_in[0:0x02]
    size = struct.unpack('i', byte_in[0x02:0x06])[0] + len(flag)
    size_byte = struct.pack('i', size)
    byte_out[0x02:0x06] = size_byte
    byte_out[0x06:0x0A] = byte_in[0x06:0x0A]
    byte_out[0x0A] = byte_in[0x0A] + len(flag)
    byte_out[0x0B:0x36] = byte_in[0x0B:0x36]
    byte_out[0x36:0x36+len(flag)] = flag
    byte_out[0x36+len(flag):] = byte_in[0x36:]
    f_out.write(byte_out)