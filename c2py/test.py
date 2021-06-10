from ctypes import *
import numpy as np


mydll = cdll.LoadLibrary('/home/pi/code/8mic/c2py/libc2py.so')
# pri = mydll.pr

mydll.pr();
mydll.fact(3);
x = c_int(2);
y = c_int(2);
z = c_int(0);
mydll.add(byref(x),byref(y),byref(z))
print(z.value)

GetInt = mydll.GetIntArray
GetInt.argtypes = [c_char_p]

GetIntArray2 = mydll.GetIntArray
GetIntArray2.argtypes =[np.ctypeslib.ndpointer(dtype=np.int ,ndim=1,flags="C_CONTIGUOUS"),
                        c_int]
N= 10
num = np.zeros(N,dtype = 'int')
print(num)
GetIntArray2(num,N)
print(num)
