#include <stdlib.h>

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int left = 0, right = numbersSize - 1;
    int* res = (int*)malloc(2 * sizeof(int));
    
    while(left < right){
        int sum = numbers[left] + numbers[right];
        if(sum == target){
            res[0] = left + 1;
            res[1] = right + 1;
            *returnSize = 2;
            return res;
        } else if(sum < target){
            left++;
        } else {
            right--;
        }
    }
    
    *returnSize = 0; // should never reach here because solution is guaranteed
    return res;
}
