class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int neg = 0, pos = 0;
        vector<int> ans;

        while(neg < nums.size() && pos < nums.size()){
            while(nums[pos] < 0) pos++;
            ans.push_back(nums[pos]); pos++;

            while(nums[neg] > 0) neg++;
            ans.push_back(nums[neg]); neg++; 
        }
        return ans;
    }
};