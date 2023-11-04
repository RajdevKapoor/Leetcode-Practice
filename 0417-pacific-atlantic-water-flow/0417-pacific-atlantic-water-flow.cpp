class Solution {
private:
    void dfs (vector<vector<int>>& heights, int row, int col, int height, vector<vector<int>>& visited) {
        if (row < 0 || row >= heights.size() || col < 0 || col >= heights[row].size()) return;
        if (visited[row][col] || heights[row][col] < height) return;
        
        visited[row][col] = true;
        dfs(heights, row + 1, col, heights[row][col], visited);
        dfs(heights, row - 1, col, heights[row][col], visited);
        dfs(heights, row, col + 1, heights[row][col], visited);
        dfs(heights, row, col - 1, heights[row][col], visited);
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> result;
        if (heights.size() == 0) return result;
        
        int m = heights.size(), n = heights[0].size();
        
        vector<vector<int>> pacific(m, vector<int>(n));
        vector<vector<int>> atlantic(m, vector<int>(n));
        
        for (int i = 0; i < m; ++i) {
            dfs(heights, i, 0, 0, pacific); // left
            dfs(heights, i, n - 1, 0, atlantic); // right
        }
        
        for (int j = 0; j < n; ++j) {
            dfs(heights, 0, j, 0, pacific); // top
            dfs(heights, m - 1, j, 0, atlantic); // buttom
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pacific[i][j] && atlantic[i][j]) result.push_back({i, j});
            }
        }
        return result;
    }
};