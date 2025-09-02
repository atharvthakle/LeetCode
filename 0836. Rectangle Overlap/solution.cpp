class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // Two rectangles do NOT overlap if one is completely to the left/right or above/below the other
        if (rec1[2] <= rec2[0] || // rec1 is left of rec2
            rec2[2] <= rec1[0] || // rec2 is left of rec1
            rec1[3] <= rec2[1] || // rec1 is below rec2
            rec2[3] <= rec1[1])   // rec2 is below rec1
        {
            return false;
        }
        // Otherwise, they must overlap
        return true;
    }
};
