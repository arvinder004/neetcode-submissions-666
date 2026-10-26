class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int res = 0, count = 0;

        // for(int i=0; i<n; i++){
        //     if(nums[i]==1){
        //         count++;
                
        //     } else {
        //         res = max(res, count);
        //         count = 0;
        //     }
        // }
        // return max(res, count);
        for(int num: nums){
            if(num == 1) count++;
            else count = 0;

            res = max(res, count);
        }
        return res;
    }
};