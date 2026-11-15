# Problem

You are given the root of a binary tree.

Return the leftmost value in the last row of the tree.

## Example 1

![Image](https://assets.leetcode.com/uploads/2020/12/14/tree1.jpg)

Input: root = [2,1,3]

Output: 1

Explanation: The last row is [1,3], so the leftmost value is 1.

## Example 2

![Image](https://assets.leetcode.com/uploads/2020/12/14/tree2.jpg)

Input: root = [1,2,3,4,null,5,6,null,null,7]

Output: 7

Explanation: The last row contains only the node 7.
 
### Constraints

- The number of nodes in the tree is in the range [1, 10^4].
- -2^31 <= Node.val <= 2^31 - 1
