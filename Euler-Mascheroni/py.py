import math

ans = 0
end = 10000000000
for i in range(1, end):
    ans += 1/i

ans -= math.log(end)
print("{0:.100f}".format(ans))
