class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        if (n <= 2) return true; // Any 2 points are always collinear
        
        // Calculate the differences for the first segment
        int dx = coordinates[1][0] - coordinates[0][0];
        int dy = coordinates[1][1] - coordinates[0][1];
        
        // Check slope with every other point
        for (int i = 2; i < n; ++i) {
            int dx_i = coordinates[i][0] - coordinates[0][0];
            int dy_i = coordinates[i][1] - coordinates[0][1];
            
            // Compare slopes using cross multiplication to avoid floating point
            if (dy * dx_i != dy_i * dx)
                return false;
        }
        
        return true;
    }
};
