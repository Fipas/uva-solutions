#include <bits/stdc++.h>

using namespace std;

unsigned long long table[30010];
int n = 5;
int coin[] = {1, 5, 10, 25, 50};

int main() {

    int n;

    memset(table, 0, sizeof table);
    table[0] = 1;

    for (int i = 0; i < 5; i++) {
        for (int j = coin[i]; j <= 30000; j++) {
            table[j] += table[j - coin[i]];
        }
    }

    while (cin >> n)
        if (table[n] > 1)
            cout << "There are " << table[n] << " ways to produce " << n << " cents change.\n";
        else
            cout << "There is only 1 way to produce " << n << " cents change.\n";

    return 0;
}