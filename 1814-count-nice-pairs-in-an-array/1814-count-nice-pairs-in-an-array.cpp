class Solution {
public:
     int rev(int num) {
        int reversed = 0;
        while (num != 0) {
            reversed = reversed * 10 + num % 10;
            num /= 10;
        }
        return reversed;
    }
    
    int countNicePairs(vector<int>& nums) {
        
        unordered_map<int,int> cnt;
        
        for(auto n:nums){
            cnt[n-rev(n)]++;
        }
        
        long result = 0;
        for (auto p : cnt) {
            int count = p.second;
            result += (long) count * (count - 1) / 2;
        }
        
        int mod = (int) (1e9 + 7);
        return (int) (result % mod);
        
    }
};