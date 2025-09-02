int computeArea(int ax1, int ay1, int ax2, int ay2, 
                int bx1, int by1, int bx2, int by2) {
    // Area of first rectangle
    int area1 = (ax2 - ax1) * (ay2 - ay1);
    // Area of second rectangle
    int area2 = (bx2 - bx1) * (by2 - by1);
    
    // Compute overlap in x and y directions
    int overlapWidth = (ax2 < bx2 ? ax2 : bx2) - (ax1 > bx1 ? ax1 : bx1);
    int overlapHeight = (ay2 < by2 ? ay2 : by2) - (ay1 > by1 ? ay1 : by1);
    
    int overlapArea = 0;
    if (overlapWidth > 0 && overlapHeight > 0) {
        overlapArea = overlapWidth * overlapHeight;
    }
    
    // Total area = area1 + area2 - overlap
    return area1 + area2 - overlapArea;
}
