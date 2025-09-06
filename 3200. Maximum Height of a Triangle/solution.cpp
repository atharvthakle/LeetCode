class Solution {
public:
    int build(int red, int blue, bool startRed) {
        int level = 1;
        while (true) {
            if (startRed) {
                if (red < level) break;  // not enough red balls
                red -= level;
            } else {
                if (blue < level) break; // not enough blue balls
                blue -= level;
            }
            startRed = !startRed; // alternate colors
            level++;
        }
        return level - 1; // last successful row
    }

    int maxHeightOfTriangle(int red, int blue) {
        return max(build(red, blue, true), build(red, blue, false));
    }
};
