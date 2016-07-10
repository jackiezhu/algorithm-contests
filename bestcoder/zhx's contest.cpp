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

long long mul(long long n, long long m, long long mod) {
	long long ret = 0, base = m;
	for (; n; base = base * 2 % mod, n >>= 1) {
		if (n & 1) {
			ret = (ret + base) % mod;
		}
	}
	return ret;
}

long long solve(long long n, long long m, long long mod) {
	long long ret = 1, b = m;
	for (; n; n >>= 1, b = mul(b, b, mod)) {
		if (n & 1) {
			ret = mul(ret, b, mod);
		}
	}
	return ret;
}

// 这题推导出公式很简单，2^n -2
// 由于n和p的范围都是long long 的，直接二分乘法会溢出，因此乘法应该用快速乘（即用加法模拟乘法）
// 乘方复杂度logn , 加法复杂度log(MAX_Longlong)
int main() {
	long long n, p;
	while (cin >> n >> p) {
		cout << (solve(n, 2, p) - 2 + p) % p << endl;
	}
}