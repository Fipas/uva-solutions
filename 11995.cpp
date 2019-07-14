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

	int n;

	while (cin >> n) {

		priority_queue<int> pq;
		queue<int> q;
		stack<int> s;
		int type, num;

		bool is_pq = true;
		bool is_q = true;
		bool is_s = true;

		for (int i = 0; i < n; i++) {
			cin >> type >> num;

			if (type == 1) {
				pq.push(num);
				s.push(num);
				q.push(num);
			} else {
				if (!pq.empty()) {
					int n_pq = pq.top();
					int n_q = q.front();
					int n_s = s.top();

					pq.pop();
					q.pop();
					s.pop();

					if (n_pq != num) is_pq = false;
					if (n_s != num) is_s = false;
					if (n_q != num) is_q = false;
				} else {
					is_pq = is_s = is_q = false;
				}
			}

		}


		int sure = 0;

		if (is_pq) sure++;
		if (is_q) sure++;
		if (is_s) sure++;

		if (sure > 1) {
			cout << "not sure\n";
		} else if (sure == 0) {
			cout << "impossible\n";
		} else if (is_pq) {
			cout << "priority queue\n";
		} else if (is_s) {
			cout << "stack\n";
		} else if (is_q) {
			cout << "queue\n";
		}
	}

	return 0;
}