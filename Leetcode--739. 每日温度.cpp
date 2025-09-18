//question link:https://leetcode.cn/problems/daily-temperatures/submissions/663790546/
//本题是关于单调栈知识点的题目，核心原理是从数组的后端向前端遍历，通过更新栈，不断找出比下标i更大的右侧下标的距离差。
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> res(n);
        stack<int> stk;
        for(int i=n-1;i>=0;i--){
            while(!stk.empty()&&temperatures[stk.top()]<=temperatures[i]){
                stk.pop();
            }
            res[i]=stk.empty()?0:stk.top()-i;
            stk.push(i);
        }
        return res;
    }
};
