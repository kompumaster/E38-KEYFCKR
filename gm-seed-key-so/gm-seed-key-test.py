from ctypes import *
import os

so_file = os.path.dirname(__file__) + "\\gm-seed-key.so"
so = CDLL(so_file)


def addZ(s, n):
    while len(s) < n:
        s = '0' + s
    return s.upper()


for algo in range(000, 256):
    seed = random(0xFF)
    print(hex(seed)[2:], addZ(hex(algo)[2:], 2), '-', addZ(hex(abs(so.get_key_gmlan(seed, algo)))[2:], 4))
