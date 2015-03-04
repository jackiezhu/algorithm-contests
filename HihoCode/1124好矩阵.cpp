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
const int MOD = 1e9 + 7;
const double eps = 1e-6;
const LL MAXL = (0x7fffffffffffffffLL);
const int MAXI = 0x7fffffff;

int a[111111], b[111111];
int acnt[111111], bcnt[111111];
long long binarySearch(int n, int num) {
	int l = -1, r = n;
	while (l + 1 < r) {
		int m = l + ((r - l) >> 1);
		if (b[m] < num) {
			l = m;
		}
		else {
			r = m;
		}
	}

	return l == -1 ? 0 : bcnt[l];
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		while (scanf_s("%d %d", &n, &m) != EOF) {
			int as = 0, bs = 0;
			map<int, int> mpa;
			for (int i = 0; i < n; i++) {
				int x, y;
				scanf_s("%d %d", &x, &y);
				a[as++] = x;
				mpa[x] += y;
			}

			map<int, int> mpb;
			for (int i = 0; i < m; i++) {
				int x, y;
				scanf_s("%d %d", &x, &y);
				b[bs++] = x;
				mpb[x] += y;
			}
			sort(a, a+as);
			sort(b, b + bs);
			as = unique(a, a + as) - a;
			bs = unique(b, b + bs) - b;
			for (int i = 0; i < bs; i++) {
				if (i) {
					bcnt[i] = bcnt[i - 1] + mpb[b[i]];
				}
				else {
					bcnt[i] = mpb[b[i]];
				}
			}
			long long res = 0;
			for (int i = 0; i < as; i++) {
				res += binarySearch(bs, a[i]) * (long long)mpa[a[i]];
			}

			cout << res << endl;
		}
	}

}