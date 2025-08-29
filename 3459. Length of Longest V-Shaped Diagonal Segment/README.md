# Problem

You are given a 2D integer matrix grid of size n x m, where each element is either 0, 1, or 2.

A V-shaped diagonal segment is defined as:

- The segment starts with 1.
- The subsequent elements follow this infinite sequence: 2, 0, 2, 0, ....
- The segment:
  - Starts along a diagonal direction (top-left to bottom-right, bottom-right to top-left, top-right to bottom-left, or bottom-left to top-right).
  - Continues the sequence in the same diagonal direction.
  - Makes at most one clockwise 90-degree turn to another diagonal direction while maintaining the sequence.
  - Return the length of the longest V-shaped diagonal segment. If no valid segment exists, return 0.

 

Example 1:

Input: grid = [[2,2,1,2,2],[2,0,2,2,0],[2,0,1,1,0],[1,0,2,2,2],[2,0,0,2,2]]

Output: 5

Explanation:
