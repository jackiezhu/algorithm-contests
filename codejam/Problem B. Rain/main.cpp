#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <queue>

using namespace std;

int height[59][59];
int R, C;
int dir[4][2] = {{1, 0}, {0,1}, {-1, 0}, {0, -1}};

bool canFill(int i, int j, int h) {
    if(i == 0 || j == 0 || i == R - 1 || j == C - 1) return false;
    queue<int> que;
    set<int> visited;
    que.push(i*C+j);
    visited.insert(i*C+j);
    while (!que.empty()) {
        int ii = que.front() / C;
        int jj = que.front() % C;
        que.pop();
        for(int d=0; d<4; d++) {
            int x = ii + dir[d][0];
            int y = jj + dir[d][1];
            if(x < R && x >= 0 && y < C && y >= 0&& height[x][y] < h
               && visited.find(x*C+y) == visited.end()) {
                if(x == 0 || y == 0 || x == R - 1 || y == C - 1) {
                    return false;
                }
                que.push(x*C + y);
                visited.insert(x*C+y);
            }
        }
    }
    return true;
    
}

int maxHeight(int i, int j) {
    int l = height[i][j], h = 1000;
    while (l + 1 < h) {
        int m = (l + h) >> 1;
        if(canFill(i, j, m)) {
            l = m;
        } else {
            h = m;
        }
    }
    return l - height[i][j];
}


int main() {
    freopen("/Users/JackieZhu/Documents/B-large.in", "r", stdin);
    freopen("/Users/JackieZhu/Documents/B-large.out", "w", stdout);
    int T;
    cin >> T;
    for(int t=1; t<=T; t++) {
        cin >> R >> C;
        for (int i=0; i<R; i++) {
            for (int j=0; j<C; j++) {
                cin >> height[i][j];
            }
        }
        
        int sum = 0;
        for (int i=0; i<R; i++) {
            for(int j=0; j<C; j++) {
                sum += maxHeight(i, j);
            }
        }
        
        cout << "Case #" << t << ": " << sum << endl;
    }
}


