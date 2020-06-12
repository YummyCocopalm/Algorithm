#include <bits/stdc++.h>

using namespace std;

const int WEAK_MAX = 15;
const int DIST_MAX = 8;

vector<int> weak, dist;
int savedwc[DIST_MAX][WEAK_MAX];
int n;

void init() {
    for (int i = 0; i < dist.size(); ++i) for (int j = 0; j < weak.size(); ++j) {
        int left = weak[j] - dist[i];
        int right = weak[j];
        for (int l = 0; l < weak.size(); ++l) {
            if ((left <= weak[l] && weak[l] <= right)
             || (left <= weak[l]-n && weak[l]-n <= right)) {
                savedwc[i][j] |= (1<<l);
            }
        }
    }
}

void dfs(int picked, int &count, int weakCheck) {
    if (weakCheck == (1<<weak.size())-1) {
        count = picked;
        return;
    }        
    
    for (int i = 0; i < weak.size() && picked+1 < count; ++i) {
        if (weakCheck & (1<<i)) continue;
        dfs(picked+1, count, weakCheck | savedwc[picked][i]);
    }
}

int solution(int _n, vector<int> _weak, vector<int> _dist) {
    n = _n;
    weak = _weak;
    dist = _dist;
    
    sort(dist.begin(), dist.end(), greater<int>());
    init();
    vector<pair<int,int>> picked;
    int count = dist.size()+1;
    dfs(0, count, 0);
    return count == dist.size()+1 ? -1:count;
}