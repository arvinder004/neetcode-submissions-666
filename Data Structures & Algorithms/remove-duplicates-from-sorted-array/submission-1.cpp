class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // set<int> st;

        // for(int num: nums){
        //     st.insert(num);
        // }

        // int i = 0;
        // for(auto ind:st){
        //     nums[i] = ind;
        //     i++;
        // }
        // return i;
        int n = nums.size();
        int i =0;
        for(int j=1; j<n; j++){
            if(nums[j] != nums[i]){
                swap(nums[i+1], nums[j]);
                i++;
            }
        }
        return i+1;
    }
};