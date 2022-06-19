class Solution {
public:
   
    int maximumSwap(int num) {
        string s = to_string(num);
        
        vector<int> d = vector(10, -1);
        
        for(int i=0; i<s.size(); i++) {
            d[s[i]-'0'] = i;
        }
        
        int ans = num;
        bool swapped  = false;
        for(int i=0; i<s.size(); i++) {
            int digit = s[i] - '0';
            for(int j=9; j>digit; j--) {
                if(i < d[j]) {
                    swap(s[i],s[d[j]]);
                    int x=stoi(s);
                    return x;
                }
            }
        }
        
        return ans;
    }
};