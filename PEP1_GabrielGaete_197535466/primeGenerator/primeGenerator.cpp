#include <iostream>
#include <stdlib.h>
#include <math.h>


using namespace std;

void runErathosthenesSieve(int left, int upperBound){
	int upperBoundSquareRoot = (int) sqrt(upperBound);
	bool* isComposite;
	isComposite = (bool*)malloc(sizeof(bool) * (upperBound+1));

	for (int m=2; m <= upperBoundSquareRoot; m++){
		if (! isComposite[m]) for (int k = m*m; k <= upperBound; k+=m) isComposite[k] = true;
	}

	for (int m = left; m <= upperBound; m++) if (! isComposite[m] && m != 1) cout << m << " \n"; 
}

int main(int argc, char const *argv[])
{	
	int queries;
	cin >> queries;
	int** queriesArray;
	queriesArray = (int**)malloc(sizeof(int*) * queries);

	for(int i=0; i<queries; i++){
		queriesArray[i] = (int*)malloc(sizeof(int) * 2);
	}
	for(int i=0; i<queries; i++){
		cin >> queriesArray[i][0];
		cin >> queriesArray[i][1];
	}

	for(int i=0; i<queries; i++){
		runErathosthenesSieve(queriesArray[i][0], queriesArray[i][1]);
		if (i+1 < queries) cout << "\n";
	} 

	for (int i=0; i<queries; i++){
		free(queriesArray[i]);
	}
	free(queriesArray);

	return 0;
}