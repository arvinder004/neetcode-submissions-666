class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // int n = nums.size();

        // for(int i=0; i<n; i++){
        //     nums[i] = nums[i]*nums[i];
        // }

        // sort(nums.begin(), nums.end());
        // return nums;

        int n = nums.size();
        int l = 0, r = n-1, resIndex=n-1;
        vector<int> res(n);

        while(l<=r){
            if(abs(nums[l]) > abs(nums[r])){
                res[resIndex] = nums[l] * nums[l];
                l++;
            } else {
                res[resIndex] = nums[r]*nums[r];
                r--;
            }
            resIndex--;
        }
        return res;
    }
};