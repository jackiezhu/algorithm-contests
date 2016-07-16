#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <cmath>

using namespace std;

long double dp[199][699];

int main() {
    cout.precision(2);
    int n,m;
    while (cin >> n >> m) {
        if(m < n || m > 6 * n) {
            cout << fixed << 0.00 << endl;
            continue;
        }
        for(int i=0; i<=m; i++) {
            for(int j=0; j<=n; j++) {
                dp[j][i] = 0;
            }
        }
        dp[0][0] = 1;
        for(int i=1; i<=n; i++) {
            for(int j=m; j>=0; j--) {
                for(int d=1; d<=6; d++) {
                    if(j>=d && dp[i-1][j-d]>0) {
                        if(dp[i][j] < 0) dp[i][j] = 0;
                        dp[i][j] += dp[i-1][j-d] * 1.0 / 6;
                    }
                }
            }
        }
        cout << fixed << dp[n][m] * 100 << endl;
    }
}


