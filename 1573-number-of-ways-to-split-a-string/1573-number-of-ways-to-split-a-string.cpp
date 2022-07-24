class Solution {
public:
    
    long long mod = 1e9 + 7;
    
    int numWays(string str) {
        
        int n = str.size();
        
        
        if(n < 3)
            return 0;
        
        int count_1 = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(str[i] == '1')
                count_1++;
        }
        
        
        if(count_1 % 3)
            return 0;
        
        
        if(count_1 == 0)
        {
            long long ans = (long long) (n - 1) * (long long) (n - 2) / 2;
            
            return ans % mod;
        }
        
        
        int need = count_1 / 3;
        
        // left_1 keep track of no. of 1 till (i - 1)th from left
        
        int left_1 = 0;
        
        // left_count keep track of no. of prefixes which have (need) no. of ones
        
        int left_count = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(str[i] == '1')
                left_1++;
            
            if(left_1 == need)
            {
                left_count++;
            }
            
            else if(left_1 > need)
                break;
        }
        
        int right_1 = 0;
        
        
        int right_count = 0;
        
        for(int i = n - 1; i >= 0; i--)
        {
            if(str[i] == '1')
                right_1++;
            
            if(right_1 == need)
            {
                right_count++;
            }
            
            else if(right_1 > need)
                break;
        }
        
        return (left_count % mod * right_count % mod) % mod;
    }
};