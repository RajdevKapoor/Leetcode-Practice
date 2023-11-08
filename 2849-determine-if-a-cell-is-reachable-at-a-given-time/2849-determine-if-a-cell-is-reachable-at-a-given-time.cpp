class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int dx=abs(fx-sx);
        int dy=abs(fy-sy);
        if (0==dx+dy) {
            return (t!=1);
        }
        return(max(dx, dy)<=t);    
    }
};