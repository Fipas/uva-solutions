#include <bits/stdc++.h>

using namespace std;


int main() {

    int n, d, r;

    while (cin >> n >> d >> r && (n || d || r)) {
        vector<int> morningRoutes(n);
        vector<int> eveningRoutes(n);
        int toPay = 0;

        for (int i = 0; i < n; i++)
            cin >> morningRoutes[i];

        for (int i = 0; i < n; i++)
            cin >> eveningRoutes[i];

        sort(morningRoutes.begin(), morningRoutes.end());
        sort(eveningRoutes.begin(), eveningRoutes.end(), greater<int>());

        for (int i = 0; i < n; i++)
            if (morningRoutes[i] + eveningRoutes[i] > d)
            toPay += (morningRoutes[i] + eveningRoutes[i] - d) * r;

        cout << toPay << endl;

    }

    return 0;
}