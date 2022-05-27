class Solution {
public:
    int numberOfSteps(int num) {
        
        int ans;
        ans=num&1?1:0;
        if(num==0){
            return 0;
        }
        
        while(num!=1){
            num/=2;
            ans++;
            if(num&1){
                ans++;
            }
        }
        
        return ans;
        
    }
};