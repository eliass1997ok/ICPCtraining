#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<unsigned long> rollingHashing(string string1, int b){
	unsigned long hashing = 0;
	vector<unsigned long> array(string1.length());

	for (int i = 0; i < string1.length(); ++i){
		hashing = hashing + int(string1[i]) * pow(b, i);
		array[i] = hashing;
	} 

	return array;
}

 long long int substringRollingHashing(int start, int end, int b, vector<unsigned long> acumRollHash){
	 long long int endHash;
	 long long int starthash;

	endHash = acumRollHash[end];
	// cout << " - " << endHash << endl;

	// for (int i=0; i<acumRollHash.size(); i++) cout << acumRollHash[i] << endl;

	if (start == 0) starthash = 0;

	else starthash = acumRollHash[start-1];

	return (endHash - starthash) * pow(b, -start);
}

// int compareHashings(vector<unsigned long> hashing, int b){
// 	int instances = 1;
// 	unsigned long hash;

// 	for (int i=0; i<hashing.size(); i++){
// 		if (i == 0 || (i > 0 && hashing.size() % i == 0)){
// 			hash = substringRollingHashing(0, i, b, hashing);
// 			for (int j=0; j<hashing.size();){
// 				cout <<"J " <<j << endl;
// 				cout << "instances: " << instances << endl;
// 				if (hash == substringRollingHashing(j, j+i, b, hashing)){
// 					instances++;
// 					if (i==0) j = j+1;
// 					else j = j + i;	
// 				} 
// 				else{
// 					cout << instances << endl;
// 					break;
// 				}
// 			}
// 		}
// 		break;
// 	}

// 	return instances;
// }

int main(){
	string string1;
	string1 = "aaaaaaaaaaaaaaaaaaaaaaaaa";

	vector<unsigned long> array2 = rollingHashing(string1, 37);

	// cout << array2[array2.size()-1] << endl;
	// cout << compareHashings(array2, 37) << endl;
	for (int i=0; i<array2.size(); i++) cout << substringRollingHashing(i, i, 37, array2) << endl;
	// cout <<  << endl;
	// cout << substringRollingHashing(1, 3, 37, array2) << endl;

	return 0;
}