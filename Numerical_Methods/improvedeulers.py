fn = input("enter function: ")
h = float(input("enter step size: "))
ic = input("IC: (x, y): ")
p = float(input("point to estimate: "))
x = float(ic.split(",")[0].split("(")[1]) + h
y = float(ic.split(", ")[1].split(")")[0])

ys = [y]
n = 1


while x < p + h:
    ystar = round(ys[n-1] + h * round(eval(fn.replace("x", str(x - h)).replace("y", str(ys[n-1]))),4), 4)

    ys.append(round((ys[n-1]+h*( ( round(eval(fn.replace("x", str(x - h)).replace("y", str(ys[n-1]))), 4)) + ( round(eval(fn.replace("x", str(x)).replace("y", str(ystar))), 4)) )/2), 4))

    x += h
    n+=1

print(ys[-1])
