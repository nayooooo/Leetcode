double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int totalLen = nums1Size + nums2Size;
    int p1 = 0, p2 = 0;
    int idx = totalLen / 2;
    if (totalLen % 2 == 0) {
        idx--;
    }

    for (int i = 0; i < idx; i++) {
        if (p1 < nums1Size && p2 < nums2Size) {
            if (nums1[p1] < nums2[p2]) {
                p1++;
            } else {
                p2++;
            }
        } else {
            if (p1 < nums1Size) {
                p1++;
            } else {
                p2++;
            }
        }
    }

    if (p1 >= nums1Size) {
        if (totalLen % 2 != 0) {
            return nums2[p2];
        } else {
            return 1.0 * (nums2[p2] + nums2[p2 + 1]) / 2;
        }
    } else if (p2 >= nums2Size) {
        if (totalLen % 2 != 0) {
            return nums1[p1];
        } else {
            return 1.0 * (nums1[p1] + nums1[p1 + 1]) / 2;
        }
    } else {
        if (totalLen % 2 != 0) {
            if (nums1[p1] < nums2[p2]) {
                return nums1[p1];
            } else {
                return nums2[p2];
            }
        } else {
            int t1;
            if (nums1[p1] < nums2[p2]) {
                t1 = nums1[p1];
                p1++;
            } else {
                t1 = nums2[p2];
                p2++;
            }
            if (p1 >= nums1Size) {
                return 1.0 * (t1 + nums2[p2]) / 2;
            } else if (p2 >= nums2Size) {
                return 1.0 * (t1 + nums1[p1]) / 2;
            } else {
                if (nums1[p1] < nums2[p2]) {
                    return 1.0 * (t1 + nums1[p1]) / 2;
                } else {
                    return 1.0 * (t1 + nums2[p2]) / 2;
                }
            }
        }
    }
}