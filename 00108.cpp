#include <iostream>

using namespace std;

int main() {
	
	int tam;
	cin >> tam;
	int matriz[tam][tam];
	
	for (int i = 0; i < tam; i++) {
		for (int j = 0; j < tam; j++) {
			cin >> matriz[i][j];
			if (i > 0) 
				matriz[i][j] += matriz[i-1][j];
			if (j > 0) 
				matriz[i][j] += matriz[i][j-1];
			if (i > 0 && j > 0) 
				matriz[i][j] -= matriz[i-1][j-1];
		}
	}
	
	int max_total = -10000000;
	int max_atual;
	
	for (int i = 0; i < tam; i++) {
		for (int j = 0; j < tam; j++) {
			for (int k = i; k < tam; k++) {
				for (int l = j; l < tam; l++) {
					max_atual = matriz[k][l];
					if (i > 0)
						max_atual -= matriz[i-1][l];
					if (j > 0)
						max_atual -= matriz[k][j-1];
					if (i > 0 && j > 0)
						max_atual += matriz[i-1][j-1];
					max_total = max(max_total, max_atual);
				}
			}
		}
	}
	
	cout << max_total << endl;
}
