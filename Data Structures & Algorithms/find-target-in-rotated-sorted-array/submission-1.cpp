class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int start, int end){
        while(start <= end){
            int mid = start + (end - start)/2;
            if (nums[mid] == target) return mid;
            else if(nums[mid] < target) start = mid + 1;
            else end = mid - 1;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l < r){
            int m = l + (r-l)/2;
            if(nums[m] > nums[r]){
                l = m+1;
            } else {
                r = m;
            }
        }
        int pivot = l;
        int res = binarySearch(nums, target, 0, pivot-1);
        if(res != -1) return res;
        return binarySearch(nums, target, pivot, nums.size()-1);
    }
};
