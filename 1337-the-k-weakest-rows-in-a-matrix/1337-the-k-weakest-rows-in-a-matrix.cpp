class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<pair<int, int>> temp; vector<int> res;
        for(int i = 0; i < m; ++i){
            int sum = 0;
            for(int j = 0; j < n; ++j){
                if(mat[i][j] == 1) sum++;
                else break;
            }
            temp.push_back(make_pair(sum, i));
        }
        sort(temp.begin(), temp.end());
        for(int i = 0; i < k; ++i) res.push_back(temp[i].second);
        return res;
    }
};