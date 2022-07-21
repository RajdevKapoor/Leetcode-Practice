class Solution {
public:
    string largestOddNumber(string nums) {
        
        string ans="";
        int i;
        for(i=nums.length()-1;i>=0;i--){
            if((nums[i]-'0')&1) break;
        }
        
        for(int j=0;j<=i;j++){
            ans+=nums[j];
        }
        
        return ans;
        
    }
};