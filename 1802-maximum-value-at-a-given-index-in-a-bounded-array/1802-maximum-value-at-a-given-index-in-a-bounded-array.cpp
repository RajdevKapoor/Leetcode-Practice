class Solution {
public:
    bool ispossible(long long mid,int n,int idx,int sum){

        long long curr_sum = ((mid)*(mid + 1)/2);
        curr_sum += ((mid - 1)*(mid)/2);
        
        if(mid > n - idx - 1){
            long long x = mid - (n - idx - 1) - 1;
            curr_sum -= ((x)*(x + 1))/2;
        }
        if(mid > idx + 1){
            long long x = mid - (idx + 1);
            curr_sum -= ((x)*(x + 1)/2);
        }
        
        curr_sum += max(n - idx - mid,0ll);
        curr_sum += max((idx - 1) - (mid - 1) + 1,0ll);
        
        return curr_sum <= sum;
        
    
    }
    int maxValue(int n, int index, int maxSum) {
        int l = 0,r = 1e9;
        int ans = 1;
        while(l <= r){
            int mid = (l + (r - l)/2);
            if(ispossible(mid,n,index,maxSum)){
                ans = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return ans;
    }
};