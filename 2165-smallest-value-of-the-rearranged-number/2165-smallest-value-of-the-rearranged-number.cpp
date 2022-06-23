class Solution {
public:
    long long smallestNumber(long long num) {
        
        string s = to_string(abs(num));
        
        
        sort(s.begin(),s.end());
        if(num<0){
            reverse(s.begin(),s.end());
        }
        
        int i=0;
        
        while(s[i]=='0') i++;
        if(i==s.size()) return 0;
        swap(s[0],s[i]);
        
        long long ans = stoll(s);
        
        return num>0 ? ans:-1*ans;
        
        
    }
};