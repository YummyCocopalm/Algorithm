class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int N = costs.size() / 2;
        vector<pair<int, int>> diff;
        for (int i = 0; i < costs.size(); ++i)
            diff.push_back({costs[i][0]-costs[i][1], i});
        sort(diff.begin(), diff.end());
        int costMin = 0;
        for (int i = 0; i < N; ++i)
            costMin += costs[diff[i].second][0];
        for (int i = 2*N-1; i >= N; --i)
            costMin += costs[diff[i].second][1];
        return costMin;
    }
};
