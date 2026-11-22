
#include <stdlib.h>
int compare18(const void* a, const void* b) {
    return (*(int*)a > *(int*)b) -
           (*(int*)a < *(int*)b);
}
int** fourSum(int* nums, int numsSize, int target,
              int* returnSize, int** returnColumnSizes) {
    int capacity = numsSize * numsSize;
    int** result = malloc(capacity * sizeof(int*));
    *returnColumnSizes = malloc(capacity * sizeof(int));
    *returnSize = 0;
    qsort(nums, numsSize, sizeof(int), compare18);
    for (int i = 0; i < numsSize - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        for (int j = i + 1; j < numsSize - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;
            int left = j + 1;
            int right = numsSize - 1;
            while (left < right) {
                long sum = (long)nums[i] + nums[j] +
                           nums[left] + nums[right];
                if (sum == target) {
                    int* quad = malloc(4 * sizeof(int));
                    quad[0] = nums[i];
                    quad[1] = nums[j];
                    quad[2] = nums[left];
                    quad[3] = nums[right];
                    result[*returnSize] = quad;
                    (*returnColumnSizes)[*returnSize] = 4;
                    (*returnSize)++;
                    left++;
                    right--;
                    while (left < right &&
                           nums[left] == nums[left - 1])
                        left++;
                    while (left < right &&
                           nums[right] == nums[right + 1])
                        right--;
                }
                else if (sum < target) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }
    }
    return result;
}
