class Solution {
public:
    void leaveIsland(vector<vector<char>>& grid, vector<vector<bool>>& vist,
                    int row, int col) {
        vist[row][col] = true;
        if (row - 1 >= 0 && grid[row - 1][col] == '1' && !vist[row - 1][col]) {
            leaveIsland(grid, vist, row - 1, col);    
        }
        if (row + 1 < grid.size() && grid[row + 1][col] == '1' && !vist[row + 1][col]) {
            leaveIsland(grid, vist, row + 1, col);  
        }
        if (col + 1 < grid[0].size() && grid[row][col + 1] == '1' && !vist[row][col + 1]) {
            leaveIsland(grid, vist, row, col + 1);
        }
        if (col - 1 >= 0 && grid[row][col - 1] == '1' && !vist[row][col - 1]) {
            leaveIsland(grid, vist, row, col - 1);   
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vist (n, vector<bool> (m, false));
        int numIsland = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1' && !vist[i][j]) {
                    ++numIsland;
                    leaveIsland(grid, vist, i, j);
                }
            }
        }
        return numIsland;
        
    }
};