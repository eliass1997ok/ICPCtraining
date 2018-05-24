#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

void isPrime(long long int number){
	if (number < 2){
		cout << "Not Prime\n";
		return;
	}

	for (int i=2; i< (long long int) sqrt(number) + 1; i++){
		if (number % i == 0){
			cout << "Not Prime\n";
			return;
		}
	}

	cout << "Prime\n";
	return;
}

int main(){
	int amountOfNumbers;
	long long int* numbers;

	cin >> amountOfNumbers;

	numbers = (long long int*)malloc(sizeof(long long int) * amountOfNumbers);

	for (int i=0; i<amountOfNumbers; i++) cin >> numbers[i]; 

	for (int i=0; i<amountOfNumbers; i++) isPrime(numbers[i]);

	free(numbers);

	return 0;
}