class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area1=abs(ax1-ax2)*abs(ay1-ay2);
        int area2=abs(bx1-bx2)*abs(by1-by2);
        int x1=max(ax1,bx1);
        int x2=min(ax2,bx2);
        int y1=max(ay1,by1);
        int y2=min(ay2,by2);
        int area3;
        if(x1<x2 && y1<y2)
            area3=abs(x2-x1)*abs(y2-y1);
        else
            area3=0;
        return area1+area2-area3;
    }
};