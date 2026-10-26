class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st;

        for(int num: nums){
            st.insert(num);
        }

        int i = 0;
        for(auto ind:st){
            nums[i] = ind;
            i++;
        }
        return i;
    }
};