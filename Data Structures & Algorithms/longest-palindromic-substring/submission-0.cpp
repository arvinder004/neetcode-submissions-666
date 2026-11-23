class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int resLen = 0, resIdx = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for(int i=n-1; i>=0; i--){
            for(int j=i; j<n; j++){
                //either the ends and inside are same OR just the ends are same and string len is less than = 2
                if(s[i] == s[j] && (j-i<=2 || dp[i+1][j-1])){
                    dp[i][j] = true;
                    // if we get a new max len then update it
                    if(resLen < (j-i+1)){
                        resIdx = i;
                        resLen = j-i+1;
                    }
                }
            }
        }
        return s.substr(resIdx, resLen);
    }
};
