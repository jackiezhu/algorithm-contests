#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <set>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <utility>
#include <cstring>
#include <list>
#include <stack>
#include <cstdio>
using namespace std;

#define ft first
#define sd second

typedef long long LL;
typedef unsigned int UI;

const int MAXN = 511111;
const int MOD = 142857;
const double eps = 1e-6;
const LL MAXL = (0x7fffffffffffffffLL);
const int MAXI = 0x7fffffff;

string repeat(int n, string s) {
    string ret;
    for(int i=0; i<n; i++) {
        ret += s;
    }
    return ret;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        if(n == m) {
            cout << repeat(n, "01") << endl;
            continue;
        }
        if(n > m) {
            cout << repeat(m, "01") + string(n-m, '0') << endl;
            continue;
        } else {
            if(m-n == 1) {
                cout << repeat(n, "10") + '1' << endl;
            } else {
                cout << "NO" << endl;
            }
            
        }
    }
}
