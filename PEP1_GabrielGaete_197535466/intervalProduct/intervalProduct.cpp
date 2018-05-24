#include <iostream>
#include <stdlib.h>
#import <vector>

using namespace std;

class SegmentTreeRMQ {
	vector<long long> arr, st;
	vector<int> leaf; int n;
	void build(int u, int i, int j) {
		if (i == j) {
			leaf[i] = u;
			st[u] = arr[i];
			return;
		}

		int m = (i+j)/2, l = u*2+1, r = u*2+2;
		build(l, i, m);
		build(r, m+1, j); // es importante el +1
		st[u] = st[l] * st[r]; // range min. query
	}
	
	long long query(int a, int b, int u, int i, int j) {
		if (j < a or b < i)
			return 1; //infinito = neutro del mín.
		if (a <= i and j <= b)
			return st[u]; // responder directamente
		int m = (i+j)/2, l = u*2+1, r = u*2+2;
		long long x = query(a, b, l, i, m);
		long long y = query(a, b, r, m+1, j);// +1 !!
		return x*y;
	}
	void update(int u) {
		int l = u*2+1, r = u*2+2;
		st[u] = st[l] * st[r]; // actualizar info
		if (u != 0) update((u-1)/2);
	}
	public:
	SegmentTreeRMQ(vector<long long> &v) {
		arr = v;
		n = v.size();
		leaf.resize(n);
		st.resize(n*4+5);
		build(0, 0, n-1);
	}
	long long query ( int a, int b) {
		return query(a, b, 0, 0, n-1);
	}
	void update( int index, long long value) {
		int u = leaf[index];
		arr[index] = value;
		st[u] = arr[index];
		if (u != 0) update((u-1)/2);
	}
};

int determineAmountLeft(int number, int pow){
	if (number - pow == 0) return 0;
	else{
		if (pow > number) return pow - number;
		else return determineAmountLeft(number, pow*2);
	}
}

int main(){
	int numbers, queries;

	while(cin >> numbers >> queries){
		vector<long long> myFirstVector = vector<long long> (0,0);
		int isaPowOf2;
		isaPowOf2 = determineAmountLeft(numbers, 1);

		for(int i=0; i<numbers+isaPowOf2; i++){
			if (i < numbers){
				long long a;
				cin >> a;
				myFirstVector.push_back(a);
			}
			else{
				long long a;
				a = 1;
				myFirstVector.push_back(a);
			}
		}

		SegmentTreeRMQ* sgmtree = new SegmentTreeRMQ(myFirstVector);

		for (int i=0; i<queries; i++){
			char action;
			int a, b;
			cin >> action >> a >> b;

			a--;

			if (action == 'C'){
				sgmtree->update(a, b);
			}
			else{
				b--;
				int result;
				result = sgmtree->query(a, b);

				if (result > 0) cout << '+';
				else if (result < 0) cout << '-';
				else cout << '0';
			}

		}
		cout << endl;
	}

	return 0;
}