class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) 
    {
        int n = box.size();
        int m = box[0].size();
        vector<vector<char>> rotatedMatrix(m, vector<char>(n));
        for(int i=0; i<n; i++)
        {
            int pos = m-1;
            for(int j=m-1; j>=0; j--)
            {
                if(box[i][j] == '*')
                {
                    pos = j-1;
                }
                else if(box[i][j] == '#')
                {
                    swap(box[i][j], box[i][pos--]);
                }
            }
        }
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
            {
                rotatedMatrix[j][n - i - 1] = box[i][j];
            }
        }
        return rotatedMatrix; 
    }
};