class Solution {
public:
    int countHomogenous(string s) {
        
        int l = 0;
        int r = 1;
        long cnt = 0;
        long kMod = pow(10, 9) + 7;

        if (s.size() == 1)
            return 1;

        while (r <= s.size()){

            while (r != s.size() && s[l] == s[r])
                r ++;

            long length = r - l;
            cnt = (cnt + ((length + 1) * length / 2) % kMod);
            l = r;
            r++;
        }

        return cnt;
    }
};