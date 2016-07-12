#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <cmath>

using namespace std;

#define eps 1e-9
long double a[199];

long double f(double x, int m) {
    long double res = 0;
    for(int i=m; i>=0; i--) {
        res += a[i] * pow(1+x, m-i);
    }
    return res;
}

int main() {
    freopen("/Users/JackieZhu/Documents/C-large-practice.in", "r", stdin);
    freopen("/Users/JackieZhu/Documents/C-large", "w", stdout);
    cout.precision(12);
    int T;
    cin >> T;
    for(int t=1; t<=T; t++) {
        int m;
        cin >> m;
        for(int i=0; i<=m; i++) {
            cin >> a[i];
        }
        a[0] = -a[0];
        double l = -1.0, h = 1.0;
        while(abs(h-l) > 1e-12) {
            double mid = (l + h) / 2;
            if(f(mid, m) > 0) {
                l = mid;
            } else {
                h = mid;
            }
        }
        cout << "Case #" << t << ": " << fixed << h << endl;
    }
}


