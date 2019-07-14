#include <bits/stdc++.h>

using namespace std;

int main() {
	cout << "COWCULATIONS OUTPUT\n";

	int n;
	map<char, int> cowToInt;
	map<int, char> intToCow;

	cowToInt['V'] = 0;
	cowToInt['U'] = 1;
	cowToInt['C'] = 2;
	cowToInt['D'] = 3;

	intToCow[0] = 'V';
	intToCow[1] = 'U';
	intToCow[2] = 'C';
	intToCow[3] = 'D';

	cin >> n;

	while (n--) {
		string num1;
		string num2;
		string result;
		char op;

		cin >> num1 >> num2;

		while (num1.size() < 8) num1 = 'V' + num1;
		while (num2.size() < 8) num2 = 'V' + num2;

		//cout << endl;
		//cout << num1 << endl;
		//cout << num2 << endl;

		for (int c = 0; c < 3; c++) {
			cin >> op;

			if (op == 'A') {
				int carry = 0;
				int sum = 0;
				string num3 = "";

				for (int i = num2.size() - 1; i >= 0; i--) {
					int nn2 = cowToInt[num2[i]];
					int nn1 = cowToInt[num1[i]];

					sum = nn2 + nn1;
					sum += carry;
					carry = 0;

					if (sum > 3) {
						while (sum > 3) {
							carry++;
							sum -= 4;
						}
					} else {
						carry = 0;
					}
					num3 = intToCow[sum] + num3;
				}
				//cout << "num2 after A:" << num3 << endl;
				num2 = num3;
			} else if (op == 'L') {
				for (int i = 0; i < num2.size() - 1; i++)
					num2[i] = num2[i + 1];
				num2[num2.size() - 1] = 'V';
				//cout << "num2 after L: " << num2 << endl;
			} else if (op == 'R') {
				for (int i = num2.size() - 1; i > 0; i--) {
					num2[i] = num2[i - 1];
				}
				num2[0] = 'V';
				//cout << "num2 after R: " << num2 << endl;
			}
		}

		cin >> result;

		while (result.size() < 8) result = 'V' + result;

		//cout << "num2: " << num2 << endl;
		//cout << "result: " << result << endl;

		if (result == num2) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

	cout << "END OF OUTPUT\n";

	return 0;
}