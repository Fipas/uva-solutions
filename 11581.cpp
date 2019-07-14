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


int m[3][3];

bool check() {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (m[i][j] != 0)
				return true;

	return false;
}

int main() {
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	while (t--) {
		cin.ignore(2);
		char ch;
		int it;

		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++) {
				cin >> ch;
				m[i][j] = ch - '0';
			}

		if (!check()) {
			cout << "-1\n";
		} else {
			for (int i = 0; check(); i++) {
				it = i;

				int s1 = (m[1][0] + m[0][1]) % 2;
				int s2 = (m[0][0] + m[1][1] + m[0][2]) % 2;
				int s3 = (m[0][1] + m[1][2]) % 2;
				int s4 = (m[0][0] + m[2][0] + m[1][1]) % 2;
				int s5 = (m[1][0] + m[1][2] + m[0][1] + m[2][1]) % 2;
				int s6 = (m[1][1] + m[0][2] + m[2][2]) % 2;
				int s7 = (m[1][0] + m[2][1]) % 2;
				int s8 = (m[1][1] + m[2][0] + m[2][2]) % 2;
				int s9 = (m[2][1] + m[1][2]) % 2;

				m[0][0] = s1;
				m[0][1] = s2;
				m[0][2] = s3;
				m[1][0] = s4;
				m[1][1] = s5;
				m[1][2] = s6;
				m[2][0] = s7;
				m[2][1] = s8;
				m[2][2] = s9;
			}

			cout << it << endl;
		}


	}

	return 0;
}