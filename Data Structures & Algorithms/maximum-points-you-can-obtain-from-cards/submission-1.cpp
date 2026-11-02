class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int res = 0;

        vector<int> prefix(n+1, 0);
        vector<int> suffix(n+1, 0);

        for(int i=0; i<n; i++){
            prefix[i+1] = prefix[i] + cardPoints[i];
        }

        for(int i=n-1; i>=0; i--){
            suffix[i] = suffix[i+1] + cardPoints[i];
        }

        for(int left = 0; left<=k; left++){
            int right = k -left;
            res = max(res, prefix[left] + suffix[n-right]);
        }
        
        return res;
    }
};