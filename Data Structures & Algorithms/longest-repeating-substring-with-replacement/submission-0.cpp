class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);

        int l=0, res = 0, maxFreq=0;

        for(int r=0; r<s.size(); r++){
            freq[s[r] - 'A']++;
            maxFreq = max(maxFreq, freq[s[r] - 'A']);

            int windowLength = r-l+1;

            if(windowLength - maxFreq > k){
                freq[s[l] - 'A']--;
                l++;
            }

            windowLength = r-l+1;

            res = max(res, windowLength);
        }

        return res;
    }
};
