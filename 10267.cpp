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
#include <iomanip>
#include <cstring>
//#include <unistd.h>
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

int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[] = {1, 0, -1, 1, -1, 1, 0, -1};


int main() {
	//ios::sync_with_stdio(false);
	
	char img[255][255];
	char name[255];
	char cmd, color;
	int m = 0, n = 0;
	int x, y, x1, x2, y1, y2;

	FILL(img, 'O');

	scanf("%c", &cmd);

	while (cmd != 'X') {
		if (cmd == 'I') {
			//scanf("%d %d", &n, &m);
			cin >> n >> m;
			FILL(img, 'O');
		} else if (cmd == 'C') {
			FILL(img, 'O');
		} else if (cmd == 'L') {
			//scanf("%d %d %c", &x, &y, &color);
			//getchar();
			cin >> x >> y >> color;
			img[y][x] = color;
		} else if (cmd == 'V') {
			//scanf("%d %d %d %c", &x, &y1, &y2, &color);
			//getchar();
			cin >> x >> y1 >> y2 >> color;
			if (y1 > y2)
				swap(y1, y2);

			//cin >> x >> y1 >> y2 >> color;
			for (int i = y1; i <= y2; i++)
				img[i][x] = color;
		} else if (cmd == 'H') {
			//scanf("%d %d %d %c", &x1, &x2, &y, &color);
			//getchar();
			cin >> x1 >> x2 >> y >> color;
			if (x1 > x2)
				swap(x1, x2);
			//cin >> x1 >> x2 >> y >> color;
			for (int i = x1; i <= x2; i++)
				img[y][i] = color;
		} else if (cmd == 'K') {
			//scanf("%d %d %d %d %c", &x1, &y1, &x2, &y2, &color);
			//getchar();
			cin >> x1 >> y1 >> x2 >> y2 >> color;
			if (y1 > y2)
				swap(y1, y2);
			if (x1 > x2)
				swap(x1, x2);

			for (int i = y1; i <= y2; i++)
				for (int j = x1; j <= x2; j++)
					img[i][j] = color;
		} else if (cmd == 'F') {
			//scanf("%d %d %c", &x, &y, &color);
			//getchar();
			cin >> y >> x >> color;
			char oldColor = img[x][y];
			img[x][y] = color;

			bool visited[m + 2][n + 2];
			CLR(visited);

			queue<pii> toVisit;

			toVisit.push(MP(x, y));
			visited[x][y] = true;


			while (!toVisit.empty()) {
				pii coord = toVisit.front();
				toVisit.pop();

				for (int i = 0; i < 8; i++) {
					int nx = coord.first + dx[i];
					int ny = coord.second + dy[i];

					if (nx > 0 && nx <= m && ny > 0 && ny <= n && !visited[nx][ny] && img[nx][ny] == oldColor) {
						img[nx][ny] = color;
						visited[nx][ny] = true;
						toVisit.push(MP(nx, ny));
					}
				}

			}
		} else if (cmd == 'S') {
			string name;
			cin >> name;
			//scanf("%s", name);
			//getchar();
			cout << name << "\n";
			for (int i = 1; i <= m; i++) {
				for (int j = 1; j <= n; j++) {
					cout << img[i][j];
				}
				cout << "\n";
			}
		} else {
			string s;
			getline(cin, s);
		}

		cin >> cmd;
	}



	return 0;
}