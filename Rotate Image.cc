class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int layer = 0; layer < n / 2; ++layer) {
            int first = layer;
            int end = n - 1 - layer;
            for (int i = first; i < end; ++i) {
                int offset = i - first;
                int temp = matrix[first][i];
                matrix[first][i] = matrix[end - offset][first];
                matrix[end - offset][first] = matrix[end][end - offset];
                matrix[end][end - offset] = matrix[i][end];
                matrix[i][end] = temp;
            }    
        }
    }
};