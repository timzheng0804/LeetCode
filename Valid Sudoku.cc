class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int horizontal[9][9] = {{0}};
        int vertical[9][9] = {{0}};
        int square[9][9] = {{0}};
        
        for(int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] != '.') {
                    int n = board[i][j] - '0' - 1;
                    int k = i / 3 * 3 + j / 3;
                    if (horizontal[i][n] != 0 || vertical[j][n] != 0 || 
                    square[k][n] != 0) return false;
                    horizontal[i][n]++;
                    vertical[j][n]++;
                    square[k][n]++;
                }
            }
        }
        return true;
    }
};