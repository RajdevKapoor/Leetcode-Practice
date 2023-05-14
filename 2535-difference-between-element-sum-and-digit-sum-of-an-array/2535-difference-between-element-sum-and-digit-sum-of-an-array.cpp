class Solution {
    typedef long long ll;
public:
    ll getDigits(ll n){
        ll ans=0;
        while(n>0){
            ans+=n%10;
            n/=10;
        }
        return ans;
    }
    int differenceOfSum(vector<int>&v) {
        ll sum=0, digits=0;
        for(ll it:v){
            sum+=it, digits+=getDigits(it);
        }
        return abs(sum-digits);
    }
};