#include <cstdio>
#include <iostream>
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
#include <iomanip>
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
//bool isPowOf2(int i){return (i & i-1) == 0;} //NOTES: isPowOf2

int main() {
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	cin.ignore(2);

	while (n--) {
	
		int reg[10];
		int ram[1000];
		int v, pc = 0, ni = 1;
		string line;

		CLR(reg);
		CLR(ram);

		while (getline(cin, line) && !line.empty()) {
			v = atoi(line.c_str());
			ram[pc++] = v;
		}

		//cout << "teste\n";

		pc = 0;

		while (ram[pc] != 100) {
			int f = ram[pc] / 100;
			int s = (ram[pc] % 100) / 10;
			int t = ram[pc] % 10;

			if (f == 1) {
				pc++;
				pc %= 1000;
				continue;
			}

			//cout << f << s << t << "\n";


			if (f == 2) {
				reg[s] = t;
				reg[s] %= 1000;
			}

			if (f == 3) {
				reg[s] += t;
				reg[s] %= 1000;
			}

			if (f == 4) {
				reg[s] *= t;
				reg[s] %= 1000;
			}

			if (f == 5) {
				reg[s] = reg[t];
				reg[s] %= 1000;
			}

			if (f == 6) {
				reg[s] += reg[t];
				reg[s] %= 1000;
			}

			if (f == 7) {
				reg[s] *= reg[t];
				reg[s] %= 1000;
			}

			if (f == 8) {
				reg[s] = ram[reg[t]];
				reg[s] %= 1000;
			}

			if (f == 9) {
				ram[reg[t]] = reg[s];
			}

			if (f == 0) {
				if (reg[t] != 0) {
					pc = reg[s];
					pc %= 1000;
					ni++;
					continue;
				}
			}

			pc++;
			ni++;
			pc %= 1000;
		}
			

		cout << ni << endl;
		if (n != 0)
			cout << endl;
	}

	return 0;
}