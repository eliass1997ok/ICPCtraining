def createHeap(lista):
	aux = lista
	heap = []

	flag = True

	if flag:
		aux2 = []

		for i in xrange(0, len(aux), 2):
			heap.append(aux[i] | aux[i+1])
			aux2.append(aux[i] | aux[i+1])
		flag = False
		aux = aux2

	if not flag and len(aux) != 1:

		for i in xrange(0, len(aux), 2):
			heap.append(aux[i] ^ aux[i+1])
			aux2.append(aux[i] ^ aux[i+1])
		flag = True



elements = map(int, raw_input().strip().split(" "))
n = elements[0]
queries = elements[1]

elements = map(int, raw_input().strip().split(" "))

