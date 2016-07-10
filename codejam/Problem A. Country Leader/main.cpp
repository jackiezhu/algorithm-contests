#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <map>
#include <set>

using namespace std;


bool cmp(const string &a, const string &b) {
    set<char> distincta, distinctb;
    int maxLen = a.length() > b.length()? a.length() : b.length();
    for(int i=0; i<maxLen; i++) {
        if(i<a.length() && a[i] <= 'Z' && a[i] >= 'A') {
            distincta.insert(a[i]);
        }
        if(i<b.length() && b[i] <= 'Z' && b[i] >= 'A') {
            distinctb.insert(b[i]);
        }
    }

    if(distincta.size() != distinctb.size()) return distincta.size() > distinctb.size();
    return a < b;
}

int main() {
    //freopen("/Users/JackieZhu/Documents/A-small-attempt0.in", "r", stdin);
    //freopen("/Users/JackieZhu/Documents/A0.out", "w", stdout);
    int T;
    cin >> T;
    for(int t=1; t<=T; t++) {
        int n;
        cin >> n;
        string s;
        getline(cin, s);
        vector<string> vec;
        for(int p=0; p<n; p++) {
            getline(cin, s);
            vec.push_back(s);
        }

        sort(vec.begin(), vec.end(), cmp);
        cout << "Case #" << t << ": " << vec[0] << endl;
    }
}


