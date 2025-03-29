from sympy import *
import math

print("make sure to edit function in py file\n")
h = float(input("enter step size: "))
p = float(input("point to estimate: "))

x = Symbol("x")
y = math.e ** (7 * x)
y5prime = str(y.diff(x).diff(x).diff(x).diff(x).diff(x))

error = eval(y5prime.replace("x", str(p))) * (h**5)/120

print("local error: " + str(round(error, 6)))
print("actual error: " + str(round(abs(math.e ** (7*p) - 2.013620865), 9)))
