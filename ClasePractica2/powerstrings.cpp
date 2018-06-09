#include <vector>
#include <iostream>

using namespace std;

typedef unsigned long long ull;
ull mod[] = {(int)1e9+7, (int)1e9+9};
//largo máximo que puede tener un string
int maxstrlen = 1e6;

class RH {
	static vector<ull> x[2];
	vector<ull> h[2];
	string str;
	int n;

	//private: usar el método público para obtener el hash
	ull hash(int a, int start, int len) {
		ull ans = 0, end = start + len;
		//descomentar si se consideran substrings cíclicos
		//if (end > n) {end -= n; ans = h[a][0]*x[a][n-start] %mod[a];}
		ans += h[a][start] - h[a][end]*x[a][len] %mod[a] + mod[a];
		return ans %mod[a];
	}

public: 
	RH() {}
	//str: string del cual se producen substrings a hashear
	RH(const string &str)
	{ // complejidad: O(n)
		this->str = str;
		n = str.size();
		if (x[0].empty())
		{
			for(int a=0;a<2;++a)
			{
				x[a].assign(maxstrlen+1, 1);
				for(int i=0;i<maxstrlen;++i)
				{
					x[a][i+1] = x[a][i]*127 %mod[a];
				}
			}
		}
		for(int a=0;a<2;++a)
		{
			h[a].assign(n+1, 0);
			for(int i=n-1;i>=0;--i)
			{
				h[a][i] = (h[a][i+1]*127 + str[i]) % mod[a];
			}
		}
	}

	//obtiene el hash de un substring que comienza en el índice “start”
	//y tiene largo “len”.
	ull hash(int start, int len) { // complejidad: O(1)
		return hash(0, start, len) << 32 | hash(1, start, len);
	}

	int repetitions(string str){
		int repetitions = 1;
		bool chars = true;
		int strlen = str.length();

		for (int i=1; i<strlen; i++){
			if (str[i] == str[0])
			{
				repetitions++;
			}
			else{
				chars = false;
				repetitions = 1;
				break;
			}
		}

		if (chars) return repetitions;

		for (int i=2; i<=strlen/2; i++){
			ull hash = this->hash(0, i);
			bool flag = true;

			if (strlen % i == 0){
				for (int j=i; j<strlen; j = j+i){
					if (hash == this->hash(j, i)){
						repetitions++;
					}

					else {
						repetitions = 1;
						flag = false;
						break;
					}
				}

				if(flag) return repetitions;
			}
		}

		return repetitions;
	}

	//si se usan, insertar aquí los métodos opcionales 1 o 2.
};
//esta línea es importante para que el código compile
vector<ull> RH::x[2];

int main() {
	string input;
	int ans;
	while(cin >> input) {
		if(input[0] == '.') {
			break;
		}
		RH rh = RH(input);
		cout << rh.repetitions(input) << endl;
	}
	return 0;
}