#include <vector>
#include <algorithm> // Include algorithm for std::min and std::max

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0; // Starting from the leftmost index
        int right = heights.size() - 1; // Starting from the rightmost index
        int maxArea = 0; // Initialize the maximum area to 0
      
        // Continue looping until the left and right pointers meet
        while (left < right) {
            // Calculate the current area with the minimum of the two heights
            int currentArea = std::min(heights[left], heights[right]) * (right - left);
            // Update the maximum area if the current area is larger
            maxArea = std::max(maxArea, currentArea);
          
            // Move the pointers inward. If left height is less than right height
            // then we move the left pointer to right hoping to find a greater height
            if (heights[left] < heights[right]) {
                ++left;
            } else { // Otherwise, move the right pointer to the left
                --right;
            }
        }
      
        return maxArea; // Return the maximum area found
    }
};
