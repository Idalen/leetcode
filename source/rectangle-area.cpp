public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {

        int cx1 = max(ax1, bx1),
            cx2 = min(ax2, bx2),
            cy1 = max(ay1, by1),
            cy2 = min(ay2, by2);

        bool intersection = !(cx1 > min(ax2, bx2) ||
                            cx2 < max(ax1, bx1) ||
                            cy1 > min(ay2, by2) ||
                            cy2 < max(ay1, by1));

        cout << intersection;

        return abs(ax1-ax2)*abs(ay1-ay2) 
            +  abs(bx1-bx2)*abs(by1-by2)
            -  abs(cx1-cx2)*abs(cy1-cy2)*intersection;
    }
};