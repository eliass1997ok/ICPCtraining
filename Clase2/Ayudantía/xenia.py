class Tree(object):
	orList = []
	xorList = []
	elements = []
	tree = []

	def __init__(self, elements):
		self.elements = elements
		self.tree = [0] * (len(elements)*2-1)
	
	def createOrList(self):
		for i in xrange(0, len(self.elements), 2):
			self.orList.append(self.elements[i] | self.elements[i+1])
	def createXorList(self):
		for i in xrange(0, len(self.orList), 2):
			self.xorList.append(self.orList[i] ^ self.orList[i+1])
	def createHeap(self):
		



elements = map(int, raw_input().strip().split(" "))
n = elements[0]
queries = elements[1]

elements = map(int, raw_input().strip().split(" "))

arbol = Tree(elements)

#print arbol.elements

arbol.createOrList()
arbol.createXorList()

print arbol.orList
print arbol.xorList
