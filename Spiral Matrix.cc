class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> spiral;
        if (!matrix.size()) return spiral;
        int m = matrix.size(), n = matrix[0].size();
        int larger = m > n ? n : m;
        int layerSize = larger % 2 == 0 ? larger - 1 : larger;
        for (int layer = 0; layer <= layerSize / 2; ++layer) {
            int first = layer;
            int endRow = m - layer - 1;
            int endCol = n - layer - 1;
            
            // top
            for (int i = first; i <= endCol; ++i) {
                spiral.push_back(matrix[first][i]);
            }
            // right
            for (int i = first + 1; i <= endRow; ++i) {
                spiral.push_back(matrix[i][endCol]);
            }
            
            // bottom
            for (int i = endCol - 1; i >= first && endRow != first; --i) {
                spiral.push_back(matrix[endRow][i]);
            }
            
            // left
            for (int i = endRow - 1; i >=  first + 1 && first != endCol; --i) {
                spiral.push_back(matrix[i][first]);
            }
            
        }
        return spiral;
    }
};