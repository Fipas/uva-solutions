#include <bits/stdc++.h>

using namespace std;


int main() {



    for (int i = 1; i <= 300; i++) {
    for (int j = i; j <= (2000 - i) / 3; j++) {
    for (int k = j; k <= (2000 - i - j) / 2; k++) {
    
        int sum = (i + j + k) * 1000000;
        int mult = (i * j * k - 1000000);

        if (mult <= 0 || sum % mult != 0) continue;
        int l = sum / mult;
       
        if (l >= k && i + j + k + l <= 2000)
            cout << fixed << setprecision(2) << (double) i / 100
                 << " " << (double) j / 100 << " " << (double) k / 100 
                 << " " << (double) l / 100 << endl;

        //cout << dl * dk * di * dj << endl;
    }}}

    return 0;
}