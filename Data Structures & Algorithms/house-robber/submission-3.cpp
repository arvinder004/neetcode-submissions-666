class Solution {
public:

    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];

        vector<int> dp(nums.size(), 0);

        int first = nums[0];
        int second = max(nums[0], nums[1]);

        for(int i=2; i<nums.size(); i++){
            int newRob = max(second, first + nums[i]);
            first = second;
            second = newRob;
        }

        return second;
    }
};
