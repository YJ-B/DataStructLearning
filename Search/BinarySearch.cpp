//
// Created by 鲍伟 on 2022/8/22.
// 二分搜索算法 递归
//

int binarySearch(int *nums, int left, int right, int target) {
    // left -> 左边界 right -> 右边界
    if (right < left) {
        return -1;
    }

    int mid = (left + right) / 2;
    if (nums[mid] == target) return mid;
    if (nums[mid] < target)
        return binarySearch(nums, mid + 1, right, target);
    else
        return binarySearch(nums, left, mid, target);
}
