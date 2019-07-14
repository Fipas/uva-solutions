#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <sstream>
#include <utility>
#include <cctype>
using namespace std;

typedef long long               ll;
typedef long double             ld;
typedef vector<int>             vi;
typedef vector<vi>              vvi;
typedef pair<int, int>          pii;
typedef vector<pii>             vii; // vector of integer pairs
typedef set<int>                si;
typedef map<string, int>        msi;

#define VAR(a,b)        __typeof(b) a=(b)
#define REP(i,n)        for(int i=0;i<(n);++i)     // 0 to n
#define FOR(i,a,b)      for(VAR(i,a);i<=(b);++i)  // a to b, a < b
#define FORD(i,a,b)     for(VAR(i,a);i>=(b);--i)  // a to b, a > b
#define FORE(a,b)       for(VAR(a,(b).begin());a!=(b).end();++a) // for each, e.g. FORE(iter, vect) cout << *iter << endl;
#define SIZE(a)         ((int)((a).size())) // e.g. for (int i = 0; i < SIZE(vect); ++i)
#define ALL(x)          (x).begin(),(x).end() // e.g. sort(ALL(vect))
#define FILL(x,a)       memset(x,a,sizeof(x))
#define CLR(x)          memset(x,0,sizeof(x))
#define VE              vector<int>
#define SZ              size()
#define PB              push_back
#define MP              make_pair
#define FI              first
#define SE              second
#define TRsi(c,it)      for(si::iterator it=(c).begin();it!=(c).end();it++) // cout << " " << *it;
#define TRvii(c,it)     for(vii::iterator it=(c).begin();it!=(c).end();it++) // cout << " " << *it;
#define TRmsi(c,it)     for(msi::iterator it=(c).begin();it!=(c).end();it++)
#define INF             2000000000 // 2 billion
#define SQ(x)           ((x)*(x))
#define getLastDigit(i) (i%10)
#define remLastDigit(i) (i/10)

const double PI=acos(-1.0); //NOTES: PI
const double EPS=1e-11; //NOTES: EPS

// Translator
bool isUpper(char c){return c>='A' && c<='Z';} //NOTES: isUpper(
bool isLower(char c){return c>='a' && c<='z';} //NOTES: isLower(
bool isLetter(char c){return (c>='A' && c<='Z') || (c>='a' && c<='z');} //NOTES: isLetter(
bool isDigit(char c){return c>='0' && c<='9';} //NOTES: isDigit(
char toLower(char c){return (isUpper(c))?(c+32):c;} //NOTES: toLower(
char toUpper(char c){return (isLower(c))?(c-32):c;} //NOTES: toUpper(
int str2int(string s){int r=0;istringstream sin(s);sin>>r;return r;} //NOTES: str2int(
int char2int(char c){return (int)c;} //NOTES: char2int(

// Numeric functions
bool isPowOf2(int i){return (i & i-1) == 0;} //NOTES: isPowOf2


int main() {
	//ios::sync_with_stdio(false);

	int n;
	cin >> n;
	cin.ignore();

	string line;

	for (int c = 1; c <= n; c++) {
		cout << "Case #" << c << ":\n";
		getline(cin, line);
		string n_line = "";

		for (int i = 0; i < line.length(); i++) {
			if (isalpha(line[i]))
				n_line += line[i];
		}

		double s_size = sqrt(n_line.length());

		if (s_size * s_size != round(s_size) * round(s_size)) {
			cout << "No magic :(\n";
		} else {
			char square[(int)s_size][(int)s_size];

			for (int i = 0, p = 0; i < s_size; i++) {
				for (int j = 0; j < s_size; j++, p++) {
					square[i][j] = n_line[p];
				}
			}

			string w1 = "", w2 = "", w3 = "", w4 = "";

			for (int i = 0; i < s_size; i++) {
				for (int j = 0; j < s_size; j++) {
					w1 += square[i][j];
					w2 += square[j][i];
				}
			}

			for (int i = s_size - 1; i >= 0; i--) {
				for (int j = s_size - 1; j >= 0; j--) {
					w3 += square[i][j];
					w4 += square[j][i];
				}
			}


			if (w1 == w2 && w2 == w3 && w3 == w4)
				cout << s_size << endl;
			else
				cout << "No magic :(\n";

		}
	}

	return 0;
}