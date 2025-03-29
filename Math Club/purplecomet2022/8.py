_sum = 1
for i in range(1, 2022 + 1):
    _sum *= ((i + 1)/(i**2 + 1) + 1/4)

print(_sum)
