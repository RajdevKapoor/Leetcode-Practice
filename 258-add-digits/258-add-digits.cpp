class Solution {
public:
  
    
    int addDigits(long long int num) {
        
        long long int ans = 0;
        while(num>0){
            ans+=num%10;
            num/=10;
        }
        
        
        return ans <10 ? ans : addDigits(ans);
    }
};