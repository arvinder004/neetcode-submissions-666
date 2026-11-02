class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int res = 0;

        for(int left = 0; left <= k; left++){
            int leftSum = 0;
            for(int i=0; i<left; i++){
                leftSum+=cardPoints[i];
            }

            int rightSum = 0;
            for(int i = n-(k-left); i<n; i++){
                rightSum += cardPoints[i];
            }

            res = max(res, leftSum + rightSum);
        }
        return res;
    }
};