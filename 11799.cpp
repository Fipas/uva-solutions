#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

int main() {
	int t;
	scanf("%d", &t);
	
	for (int i = 0, c = 1; i < t; i++, c++) {
		int qtd;
		scanf("%d", &qtd);
		int maxi = -1;
		for (int i = 0; i < qtd; i++) {
			int val;
			scanf("%d", &val);
			maxi = max(maxi, val);
		}
		
		printf("Case %d: %d\n", c, maxi);
	}
	return 0;
}
