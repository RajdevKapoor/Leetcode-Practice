class Solution {
public:
    double t[101][101];
    double solve(int poured, int row, int glass)
    {
        if(row < 0 || glass > row || glass < 0)
        {
            return 0.00;
        }
        if(row == 0 && glass == 0)
        {
            return poured;
        }
        
        if(t[row][glass] > -1)
        {
            return t[row][glass];
        }
        
        double left = max(0.00,(solve(poured, row - 1, glass - 1) - 1) / 2);
        double right = max(0.00,(solve(poured, row - 1, glass) - 1) / 2);
        
        double total = left + right;
        
        return t[row][glass] = total;
        
        
    }
    double champagneTower(int poured, int query_row, int query_glass) {
        memset(t, -1, sizeof(t));
        return min(1.00, solve(poured, query_row, query_glass));
    }
};