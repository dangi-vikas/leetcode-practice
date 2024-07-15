class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area1 = (ax2 - ax1) * (ay2- ay1);
        int area2 = (bx2 - bx1) * (by2- by1);
        int commonArea = 0;;
        
        int X1 = max(ax1, bx1);
        int X2 = min(ax2, bx2);
        int Y1 = max(ay1, by1);
        int Y2 = min(ay2, by2);
        
        if(X2 > X1 && Y2 > Y1)
            commonArea = (X2 - X1) * (Y2 - Y1);
        
        return area1 + area2 - commonArea;
    }
};