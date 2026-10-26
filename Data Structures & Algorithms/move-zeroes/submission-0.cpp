class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> temp;
        for(int num: nums){
            if(num != 0) temp.push_back(num);
        }

        int n = temp.size();

        for(int i=0; i<n; i++){
            nums[i] = temp[i];
        }

        for(int i=n; i<nums.size(); i++){
            nums[i] = 0;
        }
        
    }
};