#include <bits/stdc++.h>

using namespace std;

int main() {
	//ios::sync_with_stdio(false);

	int t;
	cin >> t;
	cout << "INTERSECTING LINES OUTPUT\n";

	while (t--) {
		int x1, x2, x3, x4;
		int y1, y2, y3, y4;
		double iy, ix;
		double m, k, d, b;
		bool inter = false, para = false, useX1 = false, useX2 = false;

		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

		if (x2 == x1) 
			useX1 = true;

		if (x3 == x4)
			useX2 = true;

		if (!useX1)
			m = (double) (y2 - y1) / (x2 - x1);
		else
			m = (double) (x2 - x1) / (y2 - y1);

		if (!useX2)
			k = (double) (y4 - y3) / (x4 - x3);
		else
			k = (double) (x4 - x3) / (y4 - y3);


		if (!useX1 && !useX2 && m == k)
			para = true;


		if (!para) {
			if (useX1 && useX2) {
				para = true;
				if (x1 == x3) {
					inter = true;
				}
			} else if (useX1) {
				d = y3 - k * x3;
				iy = k * x1 + d;

				b = x1 - m * y1;
				ix = m * iy + b;

				inter = true;
			} else if (useX2) {
				b = y1 - m * x1;
				iy = m * x3 + b;

				d = x3 - k * y3;
				ix = k * iy + d;
				inter = true;
			} else {
				b = y1 - m * x1;
				d = y3 - k * x3;
				//printf("%.2lf %.2lf %.2lf %.2lf\n", d, b, m, k);
				ix = (d - b) / (m - k);
				iy = m * ix + b;
				inter = true;
			}
		} else {
			b = y1 - m * x1;
			d = y3 - k * x3;
			if (b == d)
				inter = true;
		}


		if (inter && para) {
			cout << "LINE\n";
		} else if (inter) {
			printf("POINT %.2lf %.2lf\n", ix, iy);
		} else {
			cout << "NONE\n";
		}
	}

	cout << "END OF OUTPUT\n";

	return 0;
}