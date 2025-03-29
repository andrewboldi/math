from math import *
from tqdm import tqdm
from datetime import datetime

fx = input("Enter a function: ") or "x + 2"
t1 = input("Enter lower bound: ") or -10
t2 = input("Enter upper bound: ") or 10
step = input("Enter step: ") or 0.0001
rnd = input("# of decimal places: ") or 2

def f(x):
    return eval(fx.replace("x", str(x)))

def frange(start, stop, step):
    j = 0
    while start + j * step < stop:
        yield start + j * step
        j += 1

start = datetime.now()

ans = 0
err = 1
for i in tqdm(frange(int(t1), int(t2), float(step)), total=round(((int(t2)-int(t1))/float(step)))):
    try:
        ans += float(step)*f(i)
    except:
        print(f"illegal operation x{err}", end="\r")
        err += 1

print("\nAnswer:", round(ans, int(rnd)))
print("Duration:", datetime.now() - start)
