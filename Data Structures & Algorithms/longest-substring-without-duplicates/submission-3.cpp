class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int l=0, res=0;

        for(int r=0; r<s.size(); r++){
            //if s[r] is already in mp move l to mp[s[r]] + 1
            // but never more l backwards
            if(mp.find(s[r]) != mp.end()){
                l = max(mp[s[r]] + 1, l);
            }

            //update mp[s[r]] = r
            mp[s[r]] = r;

            //update the longest string
            res = max(res, r-l+1);
        }
        return res;
    }
};
