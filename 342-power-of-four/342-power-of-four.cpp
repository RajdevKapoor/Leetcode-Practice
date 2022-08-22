class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n < 1) return false;
        return n == pow(4, (int)(log10(n)/log10(4)));
    }
};