题目地址：https://leetcode.cn/problems/koko-eating-bananas/


class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //left的初始值不能为0，否则会出现0为除数的情况。
        int left = 1, right = 1000000001;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (f(piles, mid) == h) {
                right = mid - 1;
            } else if (f(piles, mid) > h) {
                left = mid + 1;
            } else if (f(piles, mid) < h) {
                right = mid - 1;
            }
        }
        return left;
    }

    long f(vector<int>& piles, int x) {
        long hours = 0;
        for (int i = 0; i < piles.size(); ++i) {
            hours += piles[i] / x;
            if (piles[i] % x > 0) {
                hours++;
            }
        }
        return hours;
    }
};
