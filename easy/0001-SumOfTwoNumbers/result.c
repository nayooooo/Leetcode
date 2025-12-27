static int _sort(int *arr, int left, int right)
{
    int div = arr[left];
    int flag = 1;

    while (left != right)
    {
        if (flag) {
            if (arr[right] < div) {
                arr[left] = arr[right];
                left++;
                flag = 0;
            } else {
                right--;
            }
        } else {
            if (arr[left] > div) {
                arr[right] = arr[left];
                right--;
                flag = 1;
            } else {
                left++;
            }
        }
    }
    arr[left] = div;

    return left;
}

static void sort(int *arr, int left, int right)
{
    int div;

    if (left < right) {
        div = _sort(arr, left, right);
        sort(arr, left, div - 1);
        sort(arr, div + 1, right);
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int l = 0;
    int r = numsSize - 1;
    int *numsBackup = (int *)malloc(numsSize * sizeof(int));
    if (numsBackup == NULL) {
        return NULL;
    }
    memcpy(numsBackup, nums, numsSize * sizeof(int));

    sort(nums, 0, numsSize - 1);
    while (l != r) {
        if (nums[l] + nums[r] == target) {
            int *result = (int *)malloc(2 * sizeof(int));
            if (result == NULL) {
                free(numsBackup);
                return NULL;
            }
            int k = 0;
            for (int i = 0; i < numsSize; i++) {
                if (!(k & 0x1) && numsBackup[i] == nums[l]) {
                    result[0] = i;
                    k |= 0x1;
                    continue;
                }
                if (!(k & 0x2) && numsBackup[i] == nums[r]) {
                    result[1] = i;
                    k |= 0x2;
                    continue;
                }
                if (k == 0x3) {
                    break;
                }
            }
            *returnSize = 2;
            free(numsBackup);
            return result;
        } else if (nums[l] + nums[r] < target) {
            l++;
        } else {
            r--;
        }
    }

    *returnSize = 0;
    free(numsBackup);
    return NULL;
}