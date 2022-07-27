class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        int bits = 32;
        while (bits--) {
            res = res << 1;
            if (n % 2) {
                res += 1;
            }
            n = n >> 1;
        }
        
        return (res);
    }
};