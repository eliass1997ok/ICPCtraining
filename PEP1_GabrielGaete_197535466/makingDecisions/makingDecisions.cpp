#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main(){
	int numberOfStrings;
	string a;

	cin >> numberOfStrings;

	int* solutions;
	solutions = (int*)malloc(sizeof(int)*numberOfStrings);

	for (int i=0; i<numberOfStrings; i++){
		string word;
		int length;
		cin >> word;
		length = word.length();
		if (length % 2 == 0){
			int first, last;

			first = word[(length/2) - 1];
			last = word[length/2];

			if (first - last == 0) solutions[i] = 1;
			else solutions[i] = 0;
		}
		else{
			int first;
			first = word[length/2];

			if (first == 48) solutions[i] = 1;
			else solutions[i] = 0;
		}

	} 
	for (int i=0; i<numberOfStrings; i++){
		if (solutions[i] == 1) cout << "Do-it\n";
		else cout << "Do-it-Not\n";
	}
	free(solutions);
	return 0;
}