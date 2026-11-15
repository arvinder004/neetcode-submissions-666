class Solution {
public:

    int houserobber(vector<int>& nums){
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];

        int rob1 = 0, rob2 = 0;

        for(int num: nums){
            int nextRob = max(rob1 + num, rob2);
            rob1 = rob2;
            rob2 = nextRob;
        }
        return rob2;
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        
        vector<int> temp1, temp2;

        for(int i=0; i<nums.size(); i++){
            if(i != 0) temp1.push_back(nums[i]);
            if(i != nums.size()-1) temp2.push_back(nums[i]);
        }

        return max(houserobber(temp1), houserobber(temp2));
    }
};
