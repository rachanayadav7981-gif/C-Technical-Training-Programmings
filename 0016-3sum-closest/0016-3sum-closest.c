
#include <stdlib.h>
#include <limits.h>
int compare16(const void* a, const void* b) {
    return (*(int*)a > *(int*)b) -
           (*(int*)a < *(int*)b);
}
int threeSumClosest(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), compare16);
    long closest = (long)nums[0] + nums[1] + nums[2];
    for (int i = 0; i < numsSize - 2; i++) {
        int left = i + 1;
        int right = numsSize - 1;
        while (left < right) {
            long sum = (long)nums[i] +
                       nums[left] + nums[right];
            if (labs(sum - target) < labs(closest - target))
                closest = sum;
            if (sum == target)
                return (int)sum;
            if (sum < target)
                left++;
            else
                right--;
        }
    }

    return (int)closest;
}
