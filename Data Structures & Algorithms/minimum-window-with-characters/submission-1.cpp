class Solution {
   public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()){
            return "";
        }

        vector<int> need(128, 0);
        for(char ch: t){
            need[ch]++;
        }

        int minLen = INT_MAX, start = 0, l=0, formed = 0, required = t.size();

        for(int r=0; r<s.size(); r++){
            // add s[r] in window 
            if(need[s[r]] > 0){
                formed++;
            }
            need[s[r]]--;

            //if window length is met, shrink the window
            while(formed == required){
                //shrink left, first calculate window length
                // if current window length is smaller than minimum length then update minimum length and starting index
                if((r-l+1) < minLen){
                    minLen = r-l+1;
                    start = l;
                }
                need[s[l]]++;

                // if the character at l was in t and removed, then remove it from formed as well
                if(need[s[l]] > 0){
                    formed--;
                }
                l++;
            }
        }
        if(minLen == INT_MAX) return "";
        return s.substr(start, minLen);
    }
};
