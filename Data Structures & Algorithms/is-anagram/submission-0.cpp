class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        vector<int> map(26, 0);
        for(int i=0; i<s.length(); i++){
            map[s[i] - 'a']++;
            map[t[i] - 'a']--;
        }

        for(int i: map){
            if(i != 0)
                return false;
        }
        return true;
    }
};
