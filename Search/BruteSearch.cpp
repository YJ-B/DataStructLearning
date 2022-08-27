//
// Created by 鲍伟 on 2022/8/22.
// 暴力搜索
//

int bruteSearchNoOrder(int * nums, int numsSize, int target) {
    for(int i = 0; i < numsSize; i++) {
        if (nums[i] == target) return i;
    }
    return -1;
}

// 有序的情况下可以进行以下优化
int bruteSearchOrder(int * nums, int numsSize, int target) {
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == target) return i;
        if (nums[i] > target) break;
    }
    return -1;
}