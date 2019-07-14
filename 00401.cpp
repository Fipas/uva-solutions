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
#include <cstring>
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

int wx[] = {1, -1, 0, 0};
int wy[] = {0, 0, 1, -1};

int main() {
	ios::sync_with_stdio(false);

	string s;

	map<char, char> reverse;

	reverse['A'] = 'A';
	reverse['B'] = ' ';
	reverse['C'] = ' ';
	reverse['D'] = ' ';
	reverse['E'] = '3';
	reverse['F'] = ' ';
	reverse['G'] = ' ';
	reverse['H'] = 'H';
	reverse['I'] = 'I';
	reverse['J'] = 'L';
	reverse['K'] = ' ';
	reverse['L'] = 'J';
	reverse['M'] = 'M';
	reverse['N'] = ' ';
	reverse['O'] = 'O';
	reverse['P'] = ' ';
	reverse['Q'] = ' ';
	reverse['R'] = ' ';
	reverse['S'] = '2';
	reverse['T'] = 'T';
	reverse['U'] = 'U';
	reverse['V'] = 'V';
	reverse['W'] = 'W';
	reverse['X'] = 'X';
	reverse['Y'] = 'Y';
	reverse['Z'] = '5';
	reverse['1'] = '1';
	reverse['2'] = 'S';
	reverse['3'] = 'E';
	reverse['4'] = ' ';
	reverse['5'] = 'Z';
	reverse['6'] = ' ';
	reverse['7'] = ' ';
	reverse['8'] = '8';
	reverse['9'] = ' ';





	while (cin >> s) {
		bool isPalindrome = true;
		bool isMirrored = true;

		for (int i = 0, j = s.size() - 1; i < s.size(); i++, j--) {
			if (s[i] != s[j])
				isPalindrome = false;
		}

		for (int i = 0, j = s.size() - 1; i < s.size() / 2 + s.size() % 2; i++, j--) {
			if (reverse[s[i]] != s[j])
				isMirrored = false;
		}

		//cout << s << endl;
		//cout << sor << endl;

		if (isPalindrome && isMirrored) {
			cout << s << " -- is a mirrored palindrome.\n\n";
		} else if (isPalindrome) {
			cout << s << " -- is a regular palindrome.\n\n";
		} else if (isMirrored) {
			cout << s << " -- is a mirrored string.\n\n";
		} else {
			cout << s << " -- is not a palindrome.\n\n";
		}
	}

	return 0;
}