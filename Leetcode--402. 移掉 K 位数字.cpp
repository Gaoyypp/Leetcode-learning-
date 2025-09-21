//Problem link:
//https://leetcode.cn/problems/remove-k-digits/

//这题巧妙利用了单调性，需要把前位的大数字删去，留下小数字，尽可能地让数字的大头小，小头大，同时对0的处理也很周到，不会让栈底存放一个0，妙哉妙哉！
class Solution {
public:
    string removeKdigits(string num, int k) {
        // 先让数字从左往右递增，让小的数字占据高位
        // 如果之后k还大于0，删除末位的大数字
        stack<char> s;
        for (char ch : num) {
            while (k > 0 && !s.empty() && s.top() > ch) {
                s.pop();
                k--;
            }
            if (s.empty() && ch == '0') {
                continue;
            }
            s.push(ch);
        }
        while (k > 0 && !s.empty()) {
            s.pop();
            k--;
        }
        if (s.empty()) {
            return "0";
        }
        string res;
        while (!s.empty()) {
            int c = s.top();
            s.pop();
            res += c;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
