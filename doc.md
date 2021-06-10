gcc c2py.c -fpic -shared -o libc2py.so

from ctypes import cdll
import numpy as np
import ctypes 

mydll = cdll.LoadLibrary('/home/pi/code/8mic/c2py/libc2py.so')
