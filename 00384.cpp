#include <bits/stdc++.h>

using namespace std;

bool isSlump(string s) {
	if (s.size() < 3)
		return false;
	else {
		if (s[0] != 'D' && s[0] != 'E')
			return false;

		if (s[1] != 'F')
			return false;

		int i = 1;

		while (i < s.size() && s[i] == 'F')
			i++;

		if (i == s.size() - 1 && s[i] == 'G')
			return true;
		else {
			string sub = s.substr(i);
			if (isSlump(sub))
				return true;
		}

		return false;
	}
}

bool isSlimp(string s) {
	if (s.size() == 2) {
		if (s[0] == 'A' && s[1] == 'H')
			return true;
		else
			return false;
	} else if (s.size() != 0 && s.size() != 1) {
		if (s[0] == 'A' && s[1] == 'B') {
			int posC = s.find_last_of('C');
			if (posC == string::npos || posC != s.size() - 1)
				return false;
			string sub = s.substr(2, posC - 2);
			if (isSlimp(sub))
				return true;
			else
				return false;
		} else if (s[0] == 'A') {
			int posC = s.find('C');
			if (posC == string::npos)
				return false;
			string sub = s.substr(1, posC - 1);
			if (isSlump(sub))
				return true;
			else
				return false;
		} else {
			return false;
		}
	} else {
		return false;
	}
}

bool isSlurpy(string s) {
	for (int i = 0; i < s.size(); i++) {
		string s1, s2;
		s1 = s.substr(0, i);
		s2 = s.substr(i, s.size() - i);
		//cout << s1 << "		" << s2 << endl;
		if (isSlimp(s1) && isSlump(s2))
			return true;
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false);

	string s;
	int t;
	cin >> t;

	cout << "SLURPYS OUTPUT\n";
	while (t--) {
		cin >> s;
		if (isSlurpy(s))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	cout << "END OF OUTPUT\n";
	return 0;
}