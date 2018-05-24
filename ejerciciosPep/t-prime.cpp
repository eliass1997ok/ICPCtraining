#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

struct node{
	long long int value;
	node *left;
	node *right;
};

class btree{
public:
	btree();
	~btree();

	void insert(long long int key);
	node *search(long long int key);

private:
	void insert(long long int key, node *leaf);
	node *search(long long int key, node *leaf);

	node *root;
};


btree::btree(){
	root = NULL;
}

void btree::insert(long long int key, node *leaf){

	if(key < leaf->value){
		if(leaf->left != NULL){
			insert(key, leaf->left);
		}else{
			leaf->left = new node;
			leaf->left->value = key;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	}else if(key >= leaf->value){
		if(leaf->right != NULL){
			insert(key, leaf->right);
		}else{
			leaf->right = new node;
			leaf->right->value = key;
			leaf->right->right = NULL;
			leaf->right->left = NULL;
		}
	}

}

void btree::insert(long long int key){
	if(root != NULL){
		insert(key, root);
	}else{
		root = new node;
		root->value = key;
		root->left = NULL;
		root->right = NULL;
	}
}

node *btree::search(long long int key, node *leaf){
	if(leaf != NULL){
		if(key == leaf->value){
			return leaf;
		}
		if(key < leaf->value){
			return search(key, leaf->left);
		}else{
			return search(key, leaf->right);
		}
	}else{
		return NULL;
	}
}

node *btree::search(long long int key){
	return search(key, root);
}



void isPrime(long long int number, btree** tree){
	if (number < 2){
		cout << "NO\n";
		return;
	} 

	for (int i=2; i < (long long int)(sqrt(number)) + 1; i++){
		if (number % i == 0){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
	(*tree)->insert(number*number);
	return;
}


// #include <iostream>
// #include <stdlib.h>
// #include <math.h>
// using namespace std;

// struct node{
// 	int value;
// 	node *left;
// 	node *right;
// };

// class btree{
// public:
// 	btree();

// 	void insert(int key);
// 	node *search(int key);

// private:
// 	void insert(int key, node *leaf);
// 	node *search(int key, node *leaf);

// 	node *root;
// };


// btree::btree(){
// 	root = NULL;
// }

// node *btree::search(int key, node *leaf){
// 	if(leaf != NULL){
// 		if(key == leaf->value){
// 			return leaf;
// 		}
// 		if(key < leaf->value){
// 			return search(key, leaf->left);
// 		}else{
// 			return search(key, leaf->right);
// 		}
// 	}else{
// 		return NULL;
// 	}
// }

// node *btree::search(int key){
// 	return search(key, root);
// }

// void btree::insert(int key, node *leaf){

// 	if(key < leaf->value){
// 		if(leaf->left != NULL){
// 			insert(key, leaf->left);
// 		}else{
// 			leaf->left = new node;
// 			leaf->left->value = key;
// 			leaf->left->left = NULL;
// 			leaf->left->right = NULL;
// 		}
// 	}else if(key >= leaf->value){
// 		if(leaf->right != NULL){
// 			insert(key, leaf->right);
// 		}else{
// 			leaf->right = new node;
// 			leaf->right->value = key;
// 			leaf->right->right = NULL;
// 			leaf->right->left = NULL;
// 		}
// 	}

// }

// void btree::insert(int key){
// 	if(root != NULL){
// 		insert(key, root);
// 	}else{
// 		root = new node;
// 		root->value = key;
// 		root->left = NULL;
// 		root->right = NULL;
// 	}
// }

// void isPrime(long long int number, btree** tree){
// 	if (number < 2){
// 		cout << "NO\n";
// 		return;
// 	} 

// 	for (int i=2; i <  (long long int)(sqrt(number)) + 1; i++){
// 		if (number % i == 0){
// 			cout << "NO\n";
// 			return;
// 		}
// 	}
// 	cout << "YES\n";
// 	(*tree)->insert(number*number);
// 	return;
// }

int main() {


	btree *tree = new btree();

	long long int cantidad;

	cin>>cantidad;

	long long int* array;
	array = (long long int*)malloc(sizeof(long long int)*cantidad);
  long long int a,j,i,n;

  for (i = 0; i < cantidad; i++)
  {
  	cin>>array[i];
  }

  for (i = 0; i < cantidad; i++)
  {
  	if (tree->search(array[i]))
  	{
  		cout<<"YES"<<endl;
  	}
  	else{
	  	if (sqrt(array[i]) == (long long int)sqrt(array[i]))
	  	{
	  		isPrime(sqrt(array[i]), &tree);
	  	}
	  	else{
	  		cout<<"NO"<<endl;
	  	}
  	}
	}
  return 0;

}


// // int main(){	
// // 	int amountOfNumbers;
// // 	long long int* numbers;
// // 	btree *tree = new btree();

// // 	cin >> amountOfNumbers;

// // 	numbers = (long long int*)malloc(sizeof(long long int)*amountOfNumbers);

// // 	for (int i=0; i<amountOfNumbers; i++) cin >> numbers[i];

// // 	for (int i=0; i<amountOfNumbers; i++){
// // 		double root;
// // 		root = sqrt(numbers[i]);
// // 		if (tree->search(numbers[i])) cout << "YES\n";
// // 		else{
// // 			if (root == (long long int) root) isPrime(root, &tree);
// // 			else cout << "NO\n";
// // 		}

// // 	}

// //     // cout << "Hello, World!" << endl;
// //     return 0;
// // }