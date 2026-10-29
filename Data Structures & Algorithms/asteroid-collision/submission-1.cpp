class Solution {
   public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;

        for (int i : asteroids) {
            bool alive = true;
            if (i > 0) {
                stk.push(i);
            } else {
                while (alive && !stk.empty() && stk.top() > 0) {
                    if (stk.top() < abs(i)) {
                        stk.pop();
                    } else if (stk.top() == abs(i)) {
                        stk.pop();
                        alive = false;
                    } else {
                        alive = false;
                    }
                }
                if (alive) {
                    stk.push(i);
                }
            }
        }
        vector<int> res;
        while (!stk.empty()) {
            res.push_back(stk.top());
            stk.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};