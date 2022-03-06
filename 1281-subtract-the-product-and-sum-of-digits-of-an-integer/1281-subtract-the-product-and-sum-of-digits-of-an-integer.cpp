class Solution {
public:
    int subtractProductAndSum(int n) {
        
        long long int pd=1;
        long long int sum=0;
        
        while(n){
            pd*=n%10;
            sum+=n%10;
            n/=10;
        }
        
        return pd-sum;
        
    }
};