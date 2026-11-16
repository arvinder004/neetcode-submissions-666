class Solution {
public:

    int helper(vector<int> nums){
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];

        // vector<int> dp(nums.size());
        // dp[0] = nums[0];
        // dp[1] = max(nums[0], nums[1]);
        int rob0 = 0, rob1 = 0;

        for(int i=0; i<nums.size(); i++){
            int temp = max(rob1, nums[i]+rob0);
            rob0 = rob1;
            rob1 = temp;
        }

        return rob1;
    }

    

    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];

        return max(helper(vector<int>(nums.begin(), nums.end()-1)), helper(vector<int>(nums.begin()+1, nums.end())));
    }
};
