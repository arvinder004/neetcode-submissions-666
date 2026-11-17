class Solution {
public:
    bool dfs(vector<int>& nums, int i, unordered_map<int, bool>& memo){
        // if already present in the map return it
        if(memo.count(i)){
            return memo[i];
        }

        //if i is the last index then we have reached so return true
        if(i == nums.size()-1){
            return true;
        }

        //if we are at 0 we cant take any jumps forward so return false
        if(nums[i] == 0){
            return false;
        }

        // calculate the farthest we can go
        int end = min((int)nums.size(), i + nums[i] + 1);

        // all possible jumps in the range
        for(int j=i+1; j<end; j++){
            if(dfs(nums, j, memo)){
                memo[i] = true;
                return true;
            }
        }
        memo[i] = false;
        return false;
    }

    bool canJump(vector<int>& nums) {
        unordered_map<int, bool> memo;

        return dfs(nums, 0, memo);
    }
};
