using System;

public class Solution {
    private int[] original;
    private int[] array;
    private Random rand;

    public Solution(int[] nums) {
        original = (int[])nums.Clone();
        array = (int[])nums.Clone();
        rand = new Random();
    }
    
    public int[] Reset() {
        array = (int[])original.Clone();
        return array;
    }
    
    public int[] Shuffle() {
        int n = array.Length;
        for (int i = n - 1; i > 0; i--) {
            int j = rand.Next(i + 1); // random index [0, i]
            int tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
        }
        return array;
    }
}
