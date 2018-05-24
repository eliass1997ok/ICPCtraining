#include <iostream>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <stdlib.h>

using namespace std;

unsigned long long int gcd (long long int u, long long int v){  // Abre gcd              
	int temp;              
	               
	while (u>v){               
		if (0 == u%v) return v;              
	               
		temp = u;             
		u = v;             
		v = temp - u;           
	               
		if (v > u){
			temp=v; 
			v=u;
			u = temp;
		}  
	}                         
	return u;     
 }   

// long long int GCD(long long int u, long long int v) {
//     while ( v != 0) {
//         long long int r = u % v;
//         u = v;
//         v = r;
//     }
//     return u;
// }

unsigned long long int multiply(long long int* numbers, int length){
	long long int result = 1;
	for(int i=0; i<length; i++){
		result = numbers[i] * result;
	}

	return result;
}

int count_factors(int n)
{	
	int a;
	a = 0;
    while (n%2 == 0)
    {
        a++;
        n = n/2;
    }

    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        while (n%i == 0)
        {
            a++;
            n = n/i;
        }
    }

    if (n > 2)
        a++;
 	return a;
}

void primeFactors(int n)
{
    while (n%2 == 0)
    {
        cout << "2 ";
        n = n/2;
    }

    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        while (n%i == 0)
        {
            cout << i << " ";
            n = n/i;
        }
    }

    if (n > 2)
        cout << n << " ";
}

int main(){
	int amountFirstArray, amountSecondArray;
	long long int* firstArray;
	long long int* secondArray;

	cin >> amountFirstArray;
	cin >> amountSecondArray;

	// cout << "factores del 10: "<<count_factors(10)<<endl;
	// primeFactors(10);

	firstArray = (long long int*)malloc(sizeof(long long int) * amountFirstArray);
	secondArray = (long long int*)malloc(sizeof(long long int) * amountSecondArray);

	for (int i=0; i<amountFirstArray; i++) cin >> firstArray[i];
	for (int i=0; i<amountSecondArray; i++) cin >> secondArray[i];

	unsigned long long int numerator, denominator;
	
	numerator = multiply(firstArray, amountFirstArray);
	denominator = multiply(secondArray, amountSecondArray);

	unsigned long long int gcd2;
	unsigned long long int numeratorFactors;
	unsigned long long int denominatorFactors;

	// std::__gcd(100,24);
	gcd2 = gcd(numerator, denominator);
	// cout << gcd2 << endl;
	numerator = numerator / gcd2;
	denominator = denominator / gcd2;

	numeratorFactors = count_factors(numerator);
	denominatorFactors = count_factors(denominator);

	int flag;
	flag = 0;

	if (denominatorFactors == 0 && numeratorFactors == 0){
		denominatorFactors = 1;
		numeratorFactors = 1;
		flag = 3;
	}
	else if (denominatorFactors == 0)
	{
		denominatorFactors = 1;
		flag = 1;
	}
	else if (numeratorFactors == 0){
		numeratorFactors = 1;
		flag = 2;
	}

	cout << numeratorFactors << " " << denominatorFactors << "\n";

	if (flag == 0){
		primeFactors(numerator);
		cout <<"\n";
		primeFactors(denominator);
		cout << "\n";
	}
	else if (flag == 1){
		primeFactors(numerator);
		cout <<"\n" << 1;
		cout << "\n";
	}
	else if (flag == 3){
		cout << 1 <<"\n";
		cout << 1 << "\n";
	}
	else {
		cout << 1 <<"\n";
		primeFactors(denominator);
		cout << "\n";
	}

	free(firstArray);
	free(secondArray);

	return 0;
}