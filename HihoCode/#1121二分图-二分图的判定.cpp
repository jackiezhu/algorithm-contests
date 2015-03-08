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

vector<vector<int> > graph;
vector<int> visit;

bool dfs(int start, int n) {
	for (int i = 0; i < graph[start].size(); i++) {
		if (visit[graph[start][i]] == 0) {
			visit[graph[start][i]] = - visit[start];
			bool ans = dfs(graph[start][i], n);
			if (!ans) return false;
		}
		else {
			if (visit[graph[start][i]] == visit[start]) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		scanf_s("%d %d", &n, &m);
		graph.clear();
		graph.resize(n+1);
		for (int i = 0; i < m; i++) {
			int s, e;
			scanf_s("%d %d", &s, &e);
			graph[s].push_back(e);
			graph[e].push_back(s);
		}

		visit.clear();
		visit.resize(n+1, 0);
		bool ans = true;
		for (int i = 1; i <= n; i++) {
			if (!ans) break;
			if (visit[i] == 0) {
				visit[i] = 1;
				bool temp = dfs(i, n);
				if (temp == false) {
					ans = false;
					break;
				}
			}
		}
		cout << (ans ? "Correct" : "Wrong") << endl;
	}
}
