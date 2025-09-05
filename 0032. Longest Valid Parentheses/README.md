# Problem

Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.

## Example 1

![Image](https://assets.leetcode.com/uploads/2021/03/14/itinerary1-graph.jpg)

Input: s = "(()"

Output: 2

Explanation: The longest valid parentheses substring is "()".

## Example 2

![Image](https://assets.leetcode.com/uploads/2021/03/14/itinerary2-graph.jpg)

Input: s = ")()())"

Output: 4

Explanation: The longest valid parentheses substring is "()()".

## Example 3

Input: s = ""

Output: 0
 
### Constraints

- 0 <= s.length <= 3 * 104
- s[i] is '(', or ')'.
