class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& a) {
        int ind = max_element(a.begin(), a.end()) - a.begin();
        int n = a.size();
        stack<int> st;
        vector<int> ans(n);
        for (int i = ind; i >= 0; i--) {
            while (!st.empty() && st.top() <= a[i]) {
                st.pop();
            }
            if (st.empty())
                ans[i] = -1;
            else
                ans[i] = st.top();
            st.push(a[i]);
        }

        for (int i = n-1; i >ind; i--) {
            while (!st.empty() && st.top() <= a[i]) {
                st.pop();
            }
            if (st.empty())
                ans[i] = -1;
            else
                ans[i] = st.top();
            st.push(a[i]);
        }
        return ans;
    }
};