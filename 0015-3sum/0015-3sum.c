
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a > *(int*)b) -
           (*(int*)a < *(int*)b);
}

int** threeSum(int* nums, int numsSize,
               int* returnSize, int** returnColumnSizes) {

    int capacity = numsSize * numsSize;
    int** result = malloc(capacity * sizeof(int*));

    *returnSize = 0;
    *returnColumnSizes = malloc(capacity * sizeof(int));

    qsort(nums, numsSize, sizeof(int), compare);

    for (int i = 0; i < numsSize - 2; i++) {

        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int left = i + 1;
        int right = numsSize - 1;

        while (left < right) {

            long sum = (long)nums[i] +
                       nums[left] + nums[right];

            if (sum == 0) {

                int* triplet = malloc(3 * sizeof(int));

                triplet[0] = nums[i];
                triplet[1] = nums[left];
                triplet[2] = nums[right];

                result[*returnSize] = triplet;
                (*returnColumnSizes)[*returnSize] = 3;
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
            else if (sum < 0) {
                left++;
            }
            else {
                right--;
            }
        }
    }
    return result;
}
