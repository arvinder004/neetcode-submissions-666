class Solution {
public:
    bool isValid(string s) {
        stack<int> stk;

        for(const auto brac:s){
            if(!stk.empty() && (brac == ']' && stk.top() == '[')){
                stk.pop();
            } else if(!stk.empty() && (brac == ')' && stk.top() == '(')){
                stk.pop();
            } else if(!stk.empty() && (brac == '}' && stk.top() == '{')){
                stk.pop();
            } else {
                stk.push(brac);
            }
        }

        return stk.empty();
    }
};
