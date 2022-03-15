class Solution {
public:
    int combinationSum4(vector<int>& coins, int n) {
        
        vector<unsigned int> v(n+1, 0);
        v[0]=1;
        
        for(int i=1;i<=n;i++){
            
            for(int c: coins){
                if(i>=c){
                    v[i]+=v[i-c];
                }
            }
            
        }
        
       return v[n];
        
    }
        
    
};