class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        vector<int> dp(n+2, 0);
        
        int top1 = 0, top2 = 0;
        int min_cost = 0;

        for(int i=n-1; i>=0; i--){
            dp[i] = cost[i] + min(dp[i+1], dp[i+2]);
            min_cost = cost[i] + min(top1, top2);
            top2 = top1;
            top1 = min_cost;
        }

        return min(top1, top2);
    }
};
