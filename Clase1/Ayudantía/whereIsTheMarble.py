def binarySearch(lista, value):
	first = 0
	last = len(lista)-1
	found = -1

	while first<=last and found == -1:
		midpoint = (first+last)//2
		if lista[midpoint] == value:
			found = midpoint
		else:
			if value < lista[midpoint]:
				last = midpoint-1
			else:
				first = midpoint+1
	return found
    


entry = list(map(int, input().strip().split(" ")))
balls = entry[0]
queries = entry[1]
case = 1

while balls != 0 and queries != 0:
	print ("CASE# " + str(case))
	lista = [0]*balls
	for i in range(balls):
			lista[i] = input()
	for q in range(queries):
		query = input()

		lista.sort()

		flag = binarySearch(lista, query)

		if flag == -1:
			print (str(query) + " not found")
		else: 
			print (str(query) + " found at " + str(flag+1))
	entry = list(map(int, input().strip().split(" ")))
	balls = entry[0]
	queries = entry[1]
	case+=1
