class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int left = 0, right = cols-1;
        int top = 0, bottom = rows-1;

        vector<int> res;

        while(left <= right && top <=bottom){
            //left to right
            for(int i=left; i<=right; i++){
                res.push_back(matrix[top][i]);
            }
            top++;

            //top to bottom
            for(int i=top; i<=bottom; i++){
                res.push_back(matrix[i][right]);
            }
            right--;

            //right to left
            if(top <= bottom){
                for(int i=right; i>=left; i--){
                    res.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            
            //bottom to top
            if(left <= right){
                for(int i=bottom; i>=top; i--){
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return res;
    }
};
