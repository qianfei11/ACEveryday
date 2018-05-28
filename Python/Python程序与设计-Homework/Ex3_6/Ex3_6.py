import fib1, fib2, fib3
n = 40
print("Pure python: ")
fib1.fibtime(n)
print("Py in Cython: ")
fib2.fibtime(n)
print("C in Cython: ")
fib3.fibtime(n)
