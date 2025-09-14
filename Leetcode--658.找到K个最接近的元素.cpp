题目链接:
https://leetcode.cn/problems/find-k-closest-elements/

/*这道题目的精妙之处在于用了一个双端都开的区间,区间元素个数为right-left-1,
通过限定下标的范围,在确定好最终的right 和 left之后再将元素插入数组res中,避免了先插入再排序的额外时间,
在极端条件下,可能为O(n^2)的时间复杂度,算法效率非常地高!!!
还有一个技巧,那就是确定了x之后从中间开始往两边寻找合适的元素,类似回文数的判定技巧*/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        int p = left_bound(arr, x);
        int left = p - 1;
        int right = p;
        // 两边都开的区间(left,right)内的元素个数为right-left-1
        while (right - left - 1 < k) {
            if (left == -1) {
                right++;
            } else if (right == arr.size()) {
                left--;
            } else if (abs(arr[left] - x) > abs(arr[right] - x)) {
                right++;
            } else {
                left--;
            }
        }

        for (int i = left + 1; i < right; i++) {
            res.push_back(arr[i]);
        }
        return res;
    }

    int left_bound(vector<int>& arr, int target) {
        int left = 0, right = arr.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};
