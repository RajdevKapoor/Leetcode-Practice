class Solution {
public:
    int mod = 1e9 + 7;
    
    
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v(nums1);
        sort(v.begin(),v.end());
        int n = nums1.size();
        long long ans = 0;
        int opt = 0;
        int temp;
        for(int i=0; i<n; i++){
            ans += abs(nums1[i] - nums2[i]);
            int it = lower_bound(v.begin(),v.end(), nums2[i]) - v.begin();
            if(it==0) temp = v[it];
            else if(it==n) temp = v[n-1];
            else{
                if(abs(nums2[i] - v[it]) > abs(nums2[i] - v[it-1])) temp = v[it-1];
                else temp = v[it];
            }
            // cout << abs(nums2[i] - temp) <<endl;
            opt = max(opt,abs(nums2[i] - nums1[i]) - abs(nums2[i] - temp));
              
        }
        
        return (ans - opt)%mod;
    }
};