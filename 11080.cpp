#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>
#include <queue>
#include <set>
#include <iostream>

using namespace std;

#define INF 100000

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main() {
	
	int t;
	scanf("%d", &t);
	
	while (t--) {
		int V, E;
		int a, b, s;
		set<int> visitar;
		
		vector<vii> AdjList;
		
		scanf("%d %d", &V, &E);
		
		AdjList.assign(V, vii());
		
		for (int i = 0; i < E; i++) {
			scanf("%d %d", &a, &b);
			AdjList[a].push_back(ii(b, 0));
			AdjList[b].push_back(ii(a, 0));
		}
		
		s = 0;
		
		queue<int> q; q.push(s);
		vi color(V, INF); color[s] = 0;
		bool isBipartite = true;
		
		haha:
		while (!q.empty() && isBipartite) {
			int u = q.front(); q.pop();
			for (int j = 0; j < (int) AdjList[u].size(); j++) {
				ii v = AdjList[u][j];
				if (color[v.first] == INF) {
					color[v.first] = 1 - color[u];
					q.push(v.first);
				} else if (color[v.first] == color[u]) {
					isBipartite = false; break;
				}
			}	
		}
		
		int i = 0;
		while (i < V && color[i] != INF) i++;
		if (i < V && isBipartite) {
			color[i] = 0;
			q.push(i);
			goto haha;
		}
		
		if (isBipartite) {
			int c1 = 0, c2 = 0;
			for (int i = 0; i < V; i++)
				if (color[i] == 0)
					c1++;
				else
					c2++;
					
			int menor = c1 < c2 ? c1 : c2;
			printf("%d\n", menor);
		} else
			printf("-1\n");
		
	}
}
