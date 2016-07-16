#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <cmath>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int res1 = -0x7FFFFFFF, sum = 0, res2 = 0, a;
        for(int i=0; i<n; i++) {
            cin >> a;
            sum += a;
            res1 = max(sum, res1);
            if(a>0) res2 += a;
            if(sum<0) sum = 0;
        }
        if(res2 == 0) res2 = res1;
        cout << res1 << " " << res2 << endl;
    }
}


