def binarySearch (arr, l, r, x):

	if r >= l:

		mid = int(l + (r - l)/2)

		if arr[mid] == x:
			return mid

		elif arr[mid] > x:
			return binarySearch(arr, l, mid-1, x)

		else:
			return binarySearch(arr, mid+1, r, x)

	else:
		return -1

flag = True
j=1
while flag:
	entry = list(map(int, input().strip().split(" ")))
	marbles = entry[0]
	queries = entry[1]

	if marbles == 0 and queries == 0:
		flag = False

	else:
		marblesList = ["0"]*marbles
		queriesList = ["0"]*queries

		for i in range(0, marbles):
			marblesList[i] = input()
		for i in range(0, queries):
			queriesList[i] = input()

		print ("CASE# " + str(j) + ":")
		marblesList.sort()
						# position = binarySearch(marblesList, 0, marbles, queriesList[i]);

		for i in range(0, queries):
			position = binarySearch(marblesList, 0, marbles, queriesList[i])
			if position == -1:
				print (str(queriesList[i]) + " not found")
			else:
				print (str(queriesList[i]) + " found at " + str(position+1))

		j+=1