
#include <limits.h>
double findMedianSortedArrays(int* nums1, int m,
                              int* nums2, int n) {
    if (m > n)
        return findMedianSortedArrays(nums2, n, nums1, m);
    int low = 0, high = m;
    while (low <= high) {
        int i = (low + high) / 2;
        int j = (m + n + 1) / 2 - i;
        int left1 = (i == 0) ? INT_MIN : nums1[i-1];
        int right1 = (i == m) ? INT_MAX : nums1[i];
        int left2 = (j == 0) ? INT_MIN : nums2[j-1];
        int right2 = (j == n) ? INT_MAX : nums2[j];
        if (left1 <= right2 && left2 <= right1) {
            if ((m + n) % 2 == 0)
                return ((double)(left1 > left2 ? left1 : left2)
                      + (double)(right1 < right2 ? right1 : right2)) / 2.0;
            return left1 > left2 ? left1 : left2;
        }
        if (left1 > right2)
            high = i - 1;
        else
            low = i + 1;
    }
    return 0.0;
}
