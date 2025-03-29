import math

fn = input("enter function: ")
h = float(input("enter step size: "))
ic = input("IC: (x, y): ")
p = float(input("point to estimate: "))
x = float(ic.split(",")[0].split("(")[1])
y = float(ic.split(", ")[1].split(")")[0])
dec = int(input("number of decimal places: "))

ys = [y]
n = 0

def f(x, y):
    return eval(fn.replace("x", str(x)).replace("y", str(y)))

# rk4 for first 3 terms
while n < 3:
    
    k1 = f(x, ys[n])
    k2 = f(x + 0.5*h, ys[n] + 0.5*h*k1)
    k3 = f(x + 0.5*h, ys[n] + 0.5*h*k2)
    k4 = f(x + h, ys[n] + h*k3)

    ys.append(ys[n] + (h/6)*(k1+2*k2+2*k3+k4))

    x += h
    n+=1


# abm
while x < p:
    ypn  = f(x, ys[-1])
    ypn1 = f(x - h, ys[-2])
    ypn2 = f(x - 2 * h, ys[-3])
    ypn3 = f(x - 3 * h, ys[-4])

    ystar = ys[n] + (h/24) * (55*ypn - 59*ypn1 + 37*ypn2 - 9 * ypn3)

    ypnp1 = f(x + h, ystar)
    ys.append(ys[-1] + (h/24) * (9*ypnp1 + 19*ypn - 5*ypn1 + ypn2))

    n += 1
    x += h


print(round(ys[-1], dec))
