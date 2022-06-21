class Solution {
public:
    int sumSubseqWidths(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        long long ans = 0;
        long long mod = 1000000007;
        vector<long long> pow (n);
        pow[0] = 1;
        for(int i = 1 ; i < n ; i++){
            pow[i] = (pow[i-1]*2)%mod; 
        }
        
        for(int i = 0 ; i < n ; i++){
            ans=ans%mod;
            ans += (arr[i]*(pow[i] - pow[n - i - 1]))%mod;
            ans=ans%mod;
        }
        
        return (int)ans;
        
    }
};