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
#include <cstring>
#include <cstdlib>
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

bool valid(long long x, long long y, long long n) {
	return x >= 0 && x < n && y >= 0 && y < n;
}


int main() {
	ios::sync_with_stdio(false);

	long long n, v;

	long long test = 999998000001;
	cout << test << endl;

	while (cin >> n >> v && n && v) {

		long long x = n / 2;
		long long y = n / 2;
		bool found = false;

		if (v == 1) {
			cout << "Line = " << n / 2 + 1;
			cout << ", column = " << n / 2 + 1 << ".\n";
		} else {

			int range = 1;
			int insRange = 0;
			int dir = 1;
			int start = 1;

			while (!(v >= start && v <= start + range)) {

				if (pos % 4 == 0) {
					x -= range;
				}

				if (pos % 4 == 1) {
					y -= range;
				}

				if (pos % 4 == 2) {
					x += range;
				}

				if (pos % 4 == 3) {
					y += range;
				}

				pos++;
				start += range;
				dir = (dir + 1) % 2;
				range += dir;
			}

			for (long long i = 2, j = 2, f = 0; i <= n * n && !found; j += 2, f++) {

				if (f % 2 == 0) {
					for (long long k = 0; k < (j / 2) && i <= n * n && valid(x, y, n) && !found; k++, i++) {
						x--;
						if (i == v) {
							cout << "Line = " << n - x;
							cout << ", column = " << y + 1 << ".\n";
							found = true;
						}
					}

					for (long long k = 0; k < (j / 2) && i <= n * n && valid(x, y, n) && !found; k++, i++) {
						y--;
						if (i == v) {
							cout << "Line = " << n - x;
							cout << ", column = " << y + 1 << ".\n";
							found = true;
						}
					}

				} else {
					for (long long k = 0; k < (j / 2) && i <= n * n && valid(x, y, n) && !found; k++, i++) {
						x++;
						if (i == v) {
							cout << "Line = " << n - x;
							cout << ", column = " << y + 1 << ".\n";
							found = true;
						}
					}

					for (long long k = 0; k < (j / 2) && i <= n * n && valid(x, y, n) && !found; k++, i++) {
						y++;
						if (i == v) {
							cout << "Line = " << n - x;
							cout << ", column = " << y + 1 << ".\n";
							found = true;
						}
					}

				}

			}

		}
	}

	return 0;
}