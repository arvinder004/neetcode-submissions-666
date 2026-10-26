class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l=0, r = heights.size()-1;
        int maxArea = 0;

        while(r > l){
            int area = min(heights[r], heights[l]) * (r-l);
            maxArea = max(maxArea, area);

            if(heights[r] < heights[l]) r--; else l++;
        }
        return maxArea;
    };
};
