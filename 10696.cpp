#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;

    while (cin >> n && n) {
        if (n <= 100) {
            cout << "f91(" << n << ") = 91\n";
        } else {
            cout << "f91(" << n << ") = " << n - 10 << endl;
        }
    }

    return 0;
}