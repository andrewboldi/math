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


while x < p:

    k1 = f(x, ys[n])
    k2 = f(x + 0.5 * h, ys[n] + 0.5 * h * k1)
    k3 = f(x + 0.5 * h, ys[n] + 0.5 * h * k2)
    k4 = f(x + h, ys[n] + h * k3)

    ys.append(ys[n] + (h / 6) * (k1 + 2 * k2 + 2 * k3 + k4))

    x += h
    n += 1

print(round(ys[-1], dec))
