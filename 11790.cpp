#include <cstdio>
#include <vector>

using namespace std;

typedef vector<int> vi;

int lis(const vi& height, const vi&width) {
    int n = height.size();
    int maximum = 0;
    vi sum(n, 0);
    for (int i = 0; i < n; i++) {
        sum[i] = width[i];
        for(int j = 0; j < i; j++)
            if (height[i] > height[j]) {
				sum[i] = sum[i] > sum[j] + width[i] ? sum[i] : sum[j] + width[i];
			}
        maximum = sum[i] > maximum ? sum[i] : maximum;
    }
    return maximum;
}
 
int lds(const vi& height, const vi&width) {
    int n = height.size();
    int maximum = 0;
    vi sum(n, 0);
    for (int i = 0; i < n; i++) {
		sum[i] = width[i];
		for (int j = 0; j < i; j++) {
			if (height[i] < height[j]) {
				sum[i] = sum[i] > sum[j] + width[i] ? sum[i] : sum[j] + width[i];
			}
		}
		maximum = sum[i] > maximum ? sum[i] : maximum;
	}
	return maximum;
}

int main() {
	int t, c = 1;
	scanf("%d", &t);
	
	while (t--) {
		int qtd;
		scanf("%d", &qtd);
		vi height(qtd);
		vi width(qtd);
		
		for (int i = 0; i < qtd; i++) {
			int val;
			scanf("%d", &val);
			height.push_back(val);
		}
		
		for (int i = 0; i < qtd; i++) {
			int val;
			scanf("%d", &val);
			width.push_back(val);
		}
		
		int lisv = lis(height, width);
		int ldsv = lds(height, width);
		
		if (lisv >= ldsv)
			printf("Case %d. Increasing (%d). Decreasing (%d).\n", c, lisv, ldsv);
		else
			printf("Case %d. Decreasing (%d). Increasing (%d).\n", c, ldsv, lisv);
		c++;
			
	}
	
	return 0;
}
