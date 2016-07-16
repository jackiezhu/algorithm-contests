#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <cmath>

using namespace std;

int a[1999];
int sum[1999][1999];
int dp[1999][1999];

int main() {
    int n;
    while (cin >> n) {
        for(int i=0; i<n; i++) {
            cin >> a[i];
        }
        for(int i=0; i<n; i++) {
            sum[i][i] = a[i];
            for(int j=i+1; j<n; j++) {
                sum[i][j] = sum[i][j-1] + a[j];
            }
        }
        for(int i=0; i<n; i++) {
            dp[i][i] = a[i];
        }
        for(int len=2; len<=n; len++) {
            for(int start=0; start+len-1<n; start++) {
                int s = start, e = start + len - 1;
                dp[s][e] = max(a[s]+sum[s+1][e]-dp[s+1][e], a[e]+sum[s][e-1]-dp[s][e-1]);
            }
        }
        
        cout << dp[0][n-1] << endl;
    }
}


