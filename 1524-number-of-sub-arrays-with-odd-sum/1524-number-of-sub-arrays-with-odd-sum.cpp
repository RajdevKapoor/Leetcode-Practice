class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long count=0;
        long long even=0,odd=0;
        long long sum=0,mod=1e9+7;
        for(int i=0;i<arr.size();i++){
            
            sum+=arr[i];
            
            if(sum%2==0){
                count=(count+odd)%mod;
                even++;
            }
            else{
                count++;
                count=(count+even)%mod;
                odd++;
            }
        }
        return count;
    }
};