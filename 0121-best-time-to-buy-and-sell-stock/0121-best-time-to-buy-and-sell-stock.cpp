class Solution {
public:
    int maxProfit(vector<int>& p) {
        
        int n=p.size();
        
        int profit =0;
        int mini = p[0];
        
        for(int i=0;i<n;i++){
            profit = max(profit,p[i]-mini);
            mini = min(mini,p[i]);
        }
        
        return profit;
        
    }
};