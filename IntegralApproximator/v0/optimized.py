from math import *
from tqdm import tqdm
from datetime import datetime
import numpy as np

fx = input("Enter a function: ") or "x + 2"
t1 = input("Enter lower bound: ") or -10
t2 = input("Enter upper bound: ") or 10
step = float(input("Enter step: ") or 0.0001)
rnd = int(input("# of decimal places: ") or 2)

start = datetime.now()

ans = 0
err = 1

for i in tqdm(np.arange(int(t1), int(t2), step)):
    try:
        ans += step*eval(fx.replace("x", str(i+step/2))) # middle riemann sum

    except:
        print(f"illegal operation x{err}", end="\r")
        err += 1

print("\nAnswer:", round(ans, int(rnd)))
print("Duration:", datetime.now() - start)
