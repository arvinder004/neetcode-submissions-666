class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        bool rowZero = false;

        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(matrix[r][c] == 0){
                    matrix[0][c] = 0;
                    if(r>0){
                        matrix[r][0] = 0;
                    } else {
                        rowZero = true;
                    }
                }
            }
        }

        for(int r=1; r<rows; r++){
            for(int c=1; c<cols; c++){
                if(matrix[0][c] == 0 || matrix[r][0] == 0){
                    matrix[r][c] = 0;
                }
            }
        }

        // first col
        if(matrix[0][0] == 0){
            for(int i=0; i<rows; i++){
                matrix[i][0] = 0;
            }
        }

        //first row
        if(rowZero){
            for(int i=0; i<cols; i++){
                matrix[0][i] = 0;
            }
        }
    }
};
