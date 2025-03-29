def prime(a):
     return not (a < 2 or any(a % x == 0 for x in range(2, int(a ** 0.5) + 1)))

e = open("e.txt").read()
for i in range(len(e) - 10):
    curr = e[i:i+10]
    if prime(int(curr)):
        print(curr)
        exit(0)
