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
	double h, u, d, f;
	
	while (scanf("%lf %lf %lf %lf", &h, &u, &d, &f), h) {
		f = (f/100) * u;
		float tot = 0;
		int di = 0;
		
		while (true) {
			di++;
			tot += u;
			if (tot > h) break;
			tot -= d;
			if (tot < 0) break;
			u -= f;
			if (u < 0) u = 0;
		}
		
		if (tot > 0)
			printf("success on day %d\n", di);
		else
			printf("failure on day %d\n", di);
			
	}
	return 0;
}
