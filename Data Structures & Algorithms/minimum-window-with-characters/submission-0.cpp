class Solution {
public:
    string minWindow(string s, string t) {

    if(t.size() > s.size()) return "";

    vector<int> need(128, 0);

    for(char c : t) {
        need[c]++;
    }

    int required = t.size();
    int formed = 0;

    int l = 0;
    int minLen = INT_MAX;
    int start = 0;

    for(int r = 0; r < s.size(); r++) {

        // 1. Add s[r] to the window
        if(need[s[r]] > 0){
            formed++;
        }
        need[s[r]]--;


        // 2. If window is valid, shrink it
        while(formed == required) {

            // 3. Update minimum window length and start index
            if((r-l+1) < minLen){
                minLen = r-l+1;
                start = l;
            }

            // 4. Remove s[l] from the window
            need[s[l]]++;

            if(need[s[l]] > 0){
                formed--;
            }

            // 5. Move l forward
            l++;
        }
    }

    if(minLen == INT_MAX) return "";

    return s.substr(start, minLen);
}
};
