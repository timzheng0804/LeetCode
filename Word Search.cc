class Solution {
public:
    bool find(vector<vector<char>>& board, string& word, int index, int row, int col) {
        if (index == word.size()) return true;
        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || board[row][col] == '\0') return false;
        if (board[row][col] == word[index]) {
            board[row][col] = '\0';
            ++index;
            if (find(board, word, index, row + 1, col) || find(board, word, index, row, col + 1) || 
                find(board, word, index, row - 1, col) || find(board, word, index, row, col - 1)) {
                return true;
            }
            board[row][col] = word[index - 1];
        }
        return false;
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == word[0]) {
                    if (find(board, word, 0, i, j)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};