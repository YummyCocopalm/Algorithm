class Solution {
    void updatePair(pair<int, int> &curr, pair<int, int> &prev, int &cost) {
        pair<int, int> next;
        next.first = prev.first + cost;
        next.second = min(next.first, prev.second);
        if (next.second > curr.second) {
            curr = next;
        } else if (next.second == curr.second && next.first > curr.first) {
            curr = next;
        }
    }   
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if (dungeon.empty()) return 1;
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<pair<int, int>> hp(n);        
        vector<pair<int, int>> minhp(n);
        hp[0] = minhp[0] = {dungeon[0][0], dungeon[0][0]};
        for (int i = 1; i < n; ++i) {
            hp[i].first = minhp[i].first = hp[i-1].first + dungeon[0][i];
            hp[i].second = minhp[i].second = min(hp[i-1].second, hp[i].first);
        }
        for (int i = 1; i < m; ++i) {
            hp[0].first = minhp[0].first = hp[0].first + dungeon[i][0];
            hp[0].second = minhp[0].second = min(hp[0].second, hp[0].first);
            for (int j = 1; j < n; ++j) {
                pair<int, int> currhp;                
                if (hp[j].first > hp[j-1].first) {
                    currhp.first = hp[j].first + dungeon[i][j];
                    currhp.second = min(currhp.first, hp[j].second);
                } else if (hp[j].first < hp[j-1].first) {
                    currhp.first = hp[j-1].first + dungeon[i][j];
                    currhp.second = min(currhp.first, hp[j-1].second);
                } else {
                    currhp.first = hp[j].first + dungeon[i][j];
                    currhp.second = min(currhp.first, max(hp[j].second, hp[j-1].second));
                }
                
                pair<int, int> currminhp;
                currminhp.first = hp[j].first + dungeon[i][j];
                currminhp.second = min(currminhp.first, hp[j].second);
                updatePair(currminhp, hp[j-1], dungeon[i][j]);
                updatePair(currminhp, minhp[j], dungeon[i][j]);
                updatePair(currminhp, minhp[j-1], dungeon[i][j]);                
                
                if (currhp.second > currminhp.second) {
                    currminhp = currhp;    
                } else if (currhp.second == currminhp.second && currhp.first > currminhp.first) {
                    currminhp = currhp;
                }
                hp[j] = currhp;
                minhp[j] = currminhp;
            }
        }
        int result = max(hp[n-1].second, minhp[n-1].second);
        return result > 0 ? 1 : (-result + 1);        
    }
};