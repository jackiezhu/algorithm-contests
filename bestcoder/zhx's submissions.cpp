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


//java BigInteger 可以自定义进制 

inline int toInt(char c) {
	if (c >= '0' && c <= '9') return c - '0';
	return c - 'a' + 10;
}

inline char toChar(int c, int base) {
	c %= base;
	if (c >= 0 && c <= 9) {
		return (char)(c + '0');
	}
	return (char)('a' + c - 10);
}
inline void add(string &res, const string &number, int base) {
	for (int i = 0; i < number.length(); i++) {
		int c = toInt(res[i]) + toInt(number[i]);
		res[i] = toChar(c, base);
	}
}

int main() {
	int n, b;
	while (cin >> n >> b) {
		string res(222, '0');
		for (int i = 0; i < n; i++) {
			char s[222];
			scanf("%s", s);
			string number(s);
			reverse(number.begin(), number.end());
			add(res, number, b);
		}
		reverse(res.begin(), res.end());
		if (res.find_first_not_of('0') == string::npos) {
			cout << 0 << endl;
		}
		else {
			cout << res.substr(res.find_first_not_of('0')) << endl;
		}
	}
}