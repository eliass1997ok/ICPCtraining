import math
def isPrime(number):
	if number < 2:
		print "NO"
		return
	for i in range(2, int(math.sqrt(number)) + 1):
		if number % i == 0:
			print "NO"
			return 
	print "YES"
	return

numbers = input()
array = map(int, raw_input().strip().split(" "))

for i in xrange(numbers):
	root = math.sqrt(array[i])
	if root - int(root) == 0:
		isPrime(root)
	else:
		print "NO"