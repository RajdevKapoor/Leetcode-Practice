class Solution {
public:
    vector<int> grayCode(int k) {
        
        vector <int> ans ={0,1};
        
        for(int z=2;z<=k;z++){
            long long int mask = 1<<z-1;
            int n=ans.size();
            for(int i=n-1;i>=0;i--){
                ans.push_back(mask^ans[i]);
            }
            
        }
        
        return ans;
    }
};