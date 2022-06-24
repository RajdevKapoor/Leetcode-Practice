class Solution {
public:
    int arrangeCoins(int n) {
        int low=0;
        int high=n;
        long mid, curr;
        while(low<=high){
            mid = low +(high-low)/2;
            curr = mid * (mid + 1) / 2;
            if(curr==n) return (int)mid;
            
            if(n<curr){
                high=mid-1;
            }else{
                low = mid+1;
            }
        }
        
        return high;
    }
};