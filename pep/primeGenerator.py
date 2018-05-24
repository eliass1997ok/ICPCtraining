import math
def isPrime(n):
	if n==2:
		return True
	elif n==1:
		return False
	else:
		for i in range(2, math.ceil(math.sqrt(n)) +1):
			if n%i == 0:
				return False
		return True

def cribaErastotenes(n):
	primos = [False]*2 + [True]*(n-1)
	for i in range(2, n+1):
		if (primos[i] and isPrime(i)):
			for j in range(i*i, n, 1):
				primos = False
		else:
			primos[i] = False
	for i in range(0, n+1):
		if primos[i]:
			print (i)

def erasthothenesSieve(left, rigth):
	# rigthSquareRoot = math.ceil(math.sqrt(rigth))
	primes = [False] * ((rigth - left)+1)
	for m in range(0, (left - rigth)+1):
		if not primes[m]:
			print (str(m) + "hola")
			for k in range(m*m, rigth+1, m):
				primes[k] = True

	for m in range(0, (rigth - left) +1):
		if not primes[m]:
			print (str(m+left) + " ")

# queries = input()

# cribaErastotenes(int(queries))
left = int(input())
rigth = int(input())
erasthothenesSieve(left, rigth)

# for i in xrange(queries):
# 	rangeToGenerate = map(int, raw_input().strip().split())
# 	leftLimit = rangeToGenerate[0]
# 	rigthLimit = rangeToGenerate[1]

