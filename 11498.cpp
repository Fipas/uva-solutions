#include <iostream>

using namespace std;

int main() {
	
	int k;
	
	while (cin >> k) {
		if (k == 0) break;
		int oi, oj;
		cin >> oi >> oj;
		
		for (int i = 0; i < k; i++) {
			int xi, xj;
			cin >> xi >> xj;
			
			if (xi > oi && xj > oj)
				cout << "NE\n";
			else if (xi < oi && xj > oj)
				cout << "NO\n";
			else if (xi < oi && xj < oj)
				cout << "SO\n";
			else if (xi > oi && xj < oj)
				cout << "SE\n";
			else
				cout << "divisa\n";
		}
	}
	
	return 0;
}

