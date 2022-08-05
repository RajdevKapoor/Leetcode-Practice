class Solution {
public:
    int calculate(int digit){
        int ans = 9;
        int temp = 9;
        for(int i=1;i<=digit-1;i++)ans *= temp, temp--;
        return ans;
    }
    int countNumbersWithUniqueDigits(int n){
        if(n == 0)return 1;
        int ans = 1;
        for(int digit=1;digit<=n;digit++)ans += calculate(digit);
        return ans;
    }
};