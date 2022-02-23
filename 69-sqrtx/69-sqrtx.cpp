class Solution {
public:
    int mySqrt(int x) {
        
        long long int l=0;
        long long int r=x;
        long long int ans;
        while(l<=r){
            
            long long int mid = (l+r)/2;
            
            if(mid*mid > x){
                r=mid-1;
                
            }
            else if(mid*mid < x){
                l=mid+1;
                ans=mid;
                
            }
            else{
                return mid;
            }
            
        }
        return ans;
        
    }
};