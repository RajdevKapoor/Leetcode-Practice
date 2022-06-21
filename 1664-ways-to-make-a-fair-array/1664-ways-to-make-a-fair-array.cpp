class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        
        int n = nums.size();
        vector <int> o(n);
        vector <int> e(n);
        
        int oddsum=0,evensum=0;
        
        for(int i=0;i<n;i++){
            if(i&1){
                oddsum+=nums[i];
            }else{
                evensum+=nums[i];
            }
            
            o[i]=oddsum;
            e[i]=evensum;
        }
        
        int ans=0;
        
        int nos = e[n-1]-e[0];
        int nes = o[n-1];
        
        if(nos==nes) ans++;
        
        for(int i=1;i<n;i++){
            nos = o[i-1]+e[n-1]-e[i];
            nes = e[i-1]+o[n-1]-o[i];
            
            if(nos==nes) ans++;
        }
        
        return ans;
    }
};