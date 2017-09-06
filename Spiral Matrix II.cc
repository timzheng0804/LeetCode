class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix (n, vector<int> (n, 0));
        int boarder = 0;
        int row = 0, col = 0;
        bool left = false, right = true, down = false, up = false;
        for (int i = 1; i <= n * n; ++i) {
            matrix[row][col] = i;
            
            // right
            if (right) {
                if (n - boarder - 1 == col) {
                    right = false; down = true;
                    --i;
                } else {
                    ++col;
                }
            }
            
            // left
            else if (left) {
                if (col == boarder) {
                    left = false; up = true;
                    ++boarder;
                    --i;
                } else {
                    --col;
                }
            }
            
            // down
            else if (down) {
                if (row == n - boarder - 1) {
                    down = false; left = true;
                    --i;
                } else {
                    ++row;
                }
            }
            
            // up
            else if (up) {
                if (row == boarder) {
                    up = false; right = true;
                    --i;
                } else {
                    --row;
                }
            }
        }
        return matrix;
    }
};