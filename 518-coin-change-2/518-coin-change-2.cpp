class Solution {
public:
    int change(int n, vector<int>& coins) {
        
        vector<int> v(n+1, 0);
        v[0]=1;
        
        // for each coin traversing the possible amount arrays and using pre calculated sum.
        for(int coin:coins){
            for(int i=coin;i<n+1;i++){
                v[i]+=v[i-coin];
            }
        }
        
        return v[n];
        
    }
};