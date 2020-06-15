const int N_MAX = 100;
const int COST_MAX = 10000000;
const int INVALID = -1;

class Solution {
public:
    int dp[N_MAX][N_MAX][N_MAX] = {0};
    
    int calDP(int src, int dst, int K, int &n) {
        if (dp[src][dst][K] != 0) return dp[src][dst][K];
        if (K == 0) {
            dp[src][dst][K] = INVALID;
            return dp[src][dst][K];
        }
        int costMin = COST_MAX;
        for (int i = 0; i < n; ++i) {
            if (i == src || i == dst) continue;
            if (calDP(src, i, 0, n) == INVALID) continue;
            if (calDP(i, dst, K-1, n) == INVALID) continue;
            costMin = min(costMin, dp[src][i][0] + dp[i][dst][K-1]);
        }
        dp[src][dst][K] = costMin == COST_MAX ? INVALID : costMin;
        return dp[src][dst][K];
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        if (n == 1) return 0;
        for (auto& it: flights)
            dp[it[0]][it[1]][0] = it[2];
        int costMin = COST_MAX;
        for (int i = 0; i <= K; ++i) {
            if (calDP(src, dst, i, n) == INVALID) continue;
            costMin = min(costMin, dp[src][dst][i]);
        }
        return costMin == COST_MAX ? INVALID : costMin;
    }
};