class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {

        unordered_map<int, int> map;
        int n = nums.size();
        // sort(nums.begin(), nums.end());

        // for(int i=1; i<n; i++){
        //     if(nums[i] == nums[i-1]){
        //         return true;
        //     }
        // }
        for(int i=0; i<n; i++){
            if(map[nums[i]] == 0){
                map[nums[i]]++;
            } else {
                return true;
            }
        }
        return false;
    }
};