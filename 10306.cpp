#include <math.h>
#include <cstdio>

#define CE 2.7182818284

double solve_it(int p, int q, int r, int s, int t, int u, double x) {
	return (p * pow(CE, -x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u);
}

double mod(double d) {
	if (d < 0) return -d;
	return d;
}

using namespace std;

int main() {
	
	int p, q, r, s, t, u;
	
	while (scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF) {
		double inicio = 0, fim = 1;
		double fun_inicio = solve_it(p, q, r, s, t, u, 0), fun_final = solve_it(p, q, r, s, t, u, 1);
		
		if (fun_inicio * fun_final > 0) {
			printf("No solution\n");
		} else {
			
			if (fun_final < fun_inicio) {
					inicio = 1;
					fim = 0;
			}
			
			while (mod(fim - inicio) > 1e-9) {
				double d = (fim + inicio) / 2.00;
				if (solve_it(p, q, r, s, t, u, d) < 0)
					inicio = d;
				else
					fim = d;
			}
			
			printf("%.4lf\n", (inicio + fim) / 2.00);
		}
	}
}
