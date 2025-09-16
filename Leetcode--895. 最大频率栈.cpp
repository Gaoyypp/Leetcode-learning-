//题目链接：https://leetcode.cn/problems/maximum-frequency-stack/


class FreqStack {
    int maxfreq = 0;
//记录每一个val对应的freq
    unordered_map<int, int> valtofreq;
//记录每一个freq对应的val，用stack可以记录最新出现的当前的freq对应的val
    unordered_map<int, stack<int>> freqtoval;

public:
    FreqStack() {}

    void push(int val) {
        valtofreq[val]++;
        maxfreq = max(maxfreq, valtofreq[val]);
        freqtoval[valtofreq[val]].push(val);
    }

    int pop() {
        int v = freqtoval[maxfreq].top();
        valtofreq[v]--;
        freqtoval[maxfreq].pop();
        if (freqtoval[maxfreq].empty()) {
            maxfreq--;
        }
        return v;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
