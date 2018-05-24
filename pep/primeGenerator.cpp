#include <iostream>
#include <stdlib.h>
#include <math.h>


using namespace std;

bool* runErathosthenesSieve(int upperBound){
	int upperBoundSquareRoot = (int) sqrt(upperBound);
	bool* isComposite;
	isComposite = (bool*)malloc(sizeof(bool) * (upperBound+1));

	for (int m=2; m <= upperBoundSquareRoot; m++) if (! isComposite[m]) for (int k = m*m; k <= upperBound; k+=m) isComposite[k] = true;

	return isComposite;
}

int main(int argc, char const *argv[])
{	
	int queries, max;
	bool* erathosthenesSieve;
	max = 0;
	cin >> queries;
	long long int** queriesArray;
	queriesArray = (long long int**)malloc(sizeof(long long int*) * queries);

	for(int i=0; i<queries; i++){
		queriesArray[i] = (long long int*)malloc(sizeof(long long int) * 2);
	}

	for(int i=0; i<queries; i++){

		cin >> queriesArray[i][0];
		cin >> queriesArray[i][1];

		if (queriesArray[i][1] > max){
			max = queriesArray[i][1];
		} 
	}

	erathosthenesSieve = (bool*)malloc(sizeof(bool) * max);
	erathosthenesSieve = runErathosthenesSieve(max);
	for(int i=0; i<max; i++) cout << erathosthenesSieve[i] << endl;

	for(int i=0; i<queries; i++){
		for (int j = queriesArray[i][0]; j<=queriesArray[i][1]; j++){
			if(! erathosthenesSieve[j] && j!=1) cout << j;
		}
		cout << endl;
	} 

	for (int i=0; i<queries; i++){
		free(queriesArray[i]);
	}
	free(queriesArray);
	free(erathosthenesSieve);

	return 0;
}