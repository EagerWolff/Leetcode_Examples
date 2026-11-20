#include <string.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int * const dest = nums1 + m;
    int destIndex = n - 1;
    int nums2Index = n - 1;
    int nums1Index = m - 1;

    for (;nums1Index >= 0 && nums2Index >= 0;){
        if (*(nums1 + nums1Index) > *(nums2 + nums2Index))
            *(dest + destIndex--) = *(nums1 + nums1Index--);
        else if (*(nums1 + nums1Index) <= *(nums2 + nums2Index))
            *(dest + destIndex--) = *(nums2 + nums2Index--);
    }

    if (nums2Index >= 0)
        memcpy(nums1, nums2, (nums2Index + 1) * sizeof(int));
}
