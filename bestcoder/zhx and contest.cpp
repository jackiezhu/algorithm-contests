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

struct Problem {
	int t, l;
	long long v;
	Problem(int t, long long v, int l) : t(t), v(v), l(l) {}

};
bool operator<(const Problem&a, const Problem &b) {
	return a.l - a.t < b.l - b.t;
}
vector<Problem> problems;
int n, w;
void dfs(int s, int ct, int score, int &ans) {
	if (score >= w) {
		ans = ct;
		return;
	}
	for (int i = s; i < problems.size(); i++) {
		int t = max(ct + problems[i].t, problems[i].l);
		if (t < ans) {
			dfs(i+1, t, score+problems[i].v, ans);
		}
	}
}

int main() {

	while (cin >> n >> w) {
		problems.clear();
		long long total = 0;
		for (int i = 0; i < n; i++) {
			int t, l; long long v;
			scanf("%d %lld %d", &t, &v, &l);
			problems.push_back(Problem(t, v, l));
			total += v;
		}
		if (total < w) {
			puts("zhx is naive!");
			continue;
		}
		sort(problems.begin(), problems.end());
		int ans = MAXI;
		dfs(0, 0, 0, ans);
		cout << ans << endl;

	}
}
