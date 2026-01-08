using System;
using System.Collections.Generic;

public class RandomizedSet {

    private List<int> nums;
    private Dictionary<int, int> indexMap;
    private Random rand;

    public RandomizedSet() {
        nums = new List<int>();
        indexMap = new Dictionary<int, int>();
        rand = new Random();
    }
    
    public bool Insert(int val) {
        if (indexMap.ContainsKey(val))
            return false;

        indexMap[val] = nums.Count;
        nums.Add(val);
        return true;
    }
    
    public bool Remove(int val) {
        if (!indexMap.ContainsKey(val))
            return false;

        int idx = indexMap[val];
        int lastVal = nums[nums.Count - 1];

        // Move last element to the place of the element to remove
        nums[idx] = lastVal;
        indexMap[lastVal] = idx;

        // Remove last element
        nums.RemoveAt(nums.Count - 1);
        indexMap.Remove(val);

        return true;
    }
    
    public int GetRandom() {
        int randomIndex = rand.Next(nums.Count);
        return nums[randomIndex];
    }
}
