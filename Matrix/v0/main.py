import numpy as np
from datetime import datetime

n = 400
A = np.random.rand(n, n)
B = np.random.rand(n, n)
C = np.zeros((n, n))
start = datetime.now()
for r in range(n):
    for c in range(n):
        for g in range(n):
            C[r][c] += A[r][g] * B[g][c]
end = datetime.now()
my_time = end - start
print(f"My Time: {my_time}")

start = datetime.now()
D = np.matmul(A, B)
end = datetime.now()
np_time = end - start
print(f"NP Time: {np_time}")

print(f"A: {A}")
print(f"B: {B}")
print(f"C: {C}")
print(f"D: {D}")
