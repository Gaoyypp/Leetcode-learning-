题目地址：
https://leetcode.cn/problems/split-array-largest-sum/

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        for (int num : nums) {
            right += num;
        }
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (f(nums, mid) <= k) {
                right = mid;
            } else if (f(nums, mid) > k) {
                left = mid + 1;
            }
        }
        return left;
    }

    int f(vector<int>& nums, int x) {
        // x表示每个数组的最大值
        int k = 1;
        int cur = 0;
        for (int num : nums) {
            if (num > x) {
                return nums.size() + 10;
            }
            if (cur + num > x) {
                k++;
                cur = num;
            } else {
                cur += num;
            }
        }

        return k;
    }
};
