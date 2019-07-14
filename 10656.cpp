#include <bits/stdc++.h>

using namespace std;


int main() {

    int n;

    while (cin >> n && n) {
        bool found = false;
        int v;

        for (int i = 0; i < n; i++) {
            cin >> v;
            if (v) {
                if (found)
                    cout << " " << v;
                else
                    cout << v;
                found = true;
            }
        }

        if (!found)
            cout << "0\n";
        else
            cout << endl;
    }

    return 0;
}