class Solution {
public:
    string reverseStr(string s, int k) {
        for (auto it = s.begin(); it < s.end(); it += 2*k) {
            auto last = (s.end() - it >= k) ? it + k : s.end();
            reverse(it, last);
        }
        return s;
    }
};
