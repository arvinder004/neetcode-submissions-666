class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // int n = nums.size();
        // vector<int> arr(n+1, 0);

        // for(int num: nums){
        //     arr[num] = 1;
        // }

        // for(int i=0; i<arr.size(); i++){
        //     if(arr[i] == 0)
        //         return i;
        // }
        // return -1;

        // int n = nums.size();
        // int xor1 = 0, xor2 = 0;

        // for(int i=1; i<n+1; i++){
        //     xor1 = xor1 ^ i;
        // }

        // for(int i=0; i<n; i++){
        //     xor2 = xor2 ^ nums[i];
        // }

        // return xor1 ^ xor2;

        int n = nums.size();
        int xor1 = 0, xor2 = 0;

        for(int i=0; i<n; i++){
            xor2 = xor2 ^ nums[i];
            xor1 = xor1 ^ (i+1);
        }

        return xor1 ^ xor2;
    }
};
