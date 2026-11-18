class Solution {
public:
    vector<int> memo;

    int dfs(vector<int>& cost, int index){
        int n = cost.size();

        if(index >= n){
            return 0;
        }

        if(memo[index] != -1){
            return memo[index];
        }

        memo[index] = cost[index] + 
                min(dfs(cost, index+1), 
                dfs(cost, index+2));
        
        return memo[index];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memo.resize(cost.size(), -1);
        return min(dfs(cost, 0), dfs(cost, 1));
    }
};
