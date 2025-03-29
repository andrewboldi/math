c = [0] * 100000;

def coef(n):
	c[0] = 1;
	for i in range(n):
		c[1 + i] = 1;
		for j in range(i, 0, -1):
			c[j] = c[j - 1] - c[j];
		c[0] = -c[0];
		
def isPrime(n):
	
	# Calculating all the coefficients
	# by the function coef and storing
	# all the coefficients in c array .
	coef(n);
	
	# subtracting c[n] and adding
	# c[0] by 1 as ( x - 1 )^n -
	# ( x^n - 1), here we are
	# subtracting c[n] by 1 and
	# adding 1 in expression.
	c[0] = c[0] + 1;
	c[n] = c[n] - 1;
	
	i = n;
	while (i > -1 and c[i] % n == 0):
		i = i - 1;
	
	return True if i < 0 else False;

# Driver Code
n = int(input("enter number: "));
if (isPrime(n)):
	print("Prime");
else:
	print("Not Prime");
	
