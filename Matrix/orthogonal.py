# Python code to check
# whether a matrix is
# orthogonal or not
import math

def isOrthogonal(a, m, n) :
	if (m != n) :
		return False
	
	trans = [[0 for x in range(n)]
				for y in range(n)]
				
	# Find transpose
	for i in range(0, n) :
		for j in range(0, n) :
			trans[i][j] = a[j][i]
			
	prod = [[0 for x in range(n)]
			for y in range(n)]
				
	# Find product of a[][]
	# and its transpose
	for i in range(0, n) :
		for j in range(0, n) :
	
			sum = 0
			for k in range(0, n) :
		
				# Since we are multiplying
				# with transpose of itself.
				# We use
				sum = sum + (a[i][k] *
							a[j][k])
	
			prod[i][j] = sum

	# Check if product is
	# identity matrix
	for i in range(0, n) :
		for j in range(0, n) :

			if (i != j and prod[i][j] != 0) :
				return False
			if (i == j and prod[i][j] != 1) :
				return False

	return True

# Driver Code
a = [[3/math.sqrt(11), math.sqrt(2/11)],
	[-1*math.sqrt(2/11), 3/math.sqrt(11)]]
		
if (isOrthogonal(a, 2, 2)) :
	print ("Yes")
else :
	print ("No")

# This code is contributed by
# Manish Shaw(manishshaw1)

