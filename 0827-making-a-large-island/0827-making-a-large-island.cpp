class Solution {
public:
    int n, m;
    vector<int> vv = {0, -1, 0, 1};
    vector<int> h = {-1, 0, 1, 0};

    bool isValid(int i, int j) {
        return i>=0 && j>=0 && i<n && j<m;
    }

    void dfs(vector<vector<int>>& grid, vector<vector<int>>& v, int paint, int i, int j, int& area) {
        if(v[i][j]) return;
        v[i][j] =1;
        grid[i][j] = paint;
        area+=1;

        for(int k=0;k<4;k++) {
            int ni = i + vv[k];
            int nj = j+ h[k];

            if(isValid(ni, nj) && !v[ni][nj] && grid[ni][nj] == 1) {
                dfs(grid, v, paint, ni, nj, area);
            }
        }
    }

    int largestIsland(vector<vector<int>>& grid) {

        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> v(n, vector<int>(m, 0));
        map<int, int>mp ;
        int paint = 0;
        for(int i=0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(!v[i][j] && grid[i][j] ==1){
                    int area = 0;
                    paint--;
                    dfs(grid, v, paint, i, j, area);
                    mp[paint] = area;
                }
            }
        }

        int max_area =0;

        for(int i=0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(grid[i][j] == 0) {
                    int area = 1;
                    set<int> surr;
                    
                    for(int k = 0 ;k <4 ;k++) {
                        int ni = i + vv[k];
                        int nj = j + h[k];
                        if(isValid(ni, nj) && grid[ni][nj] < 0) {
                            surr.insert(grid[ni][nj]);
                        }
                    }
                    for(auto it = surr.begin(); it != surr.end(); it ++) {
                        area += mp[*it];
                    }
                    max_area = max(max_area, area);
                }
            }
        }
        return max_area == 0 ? n*m : max_area;
        
    }
};