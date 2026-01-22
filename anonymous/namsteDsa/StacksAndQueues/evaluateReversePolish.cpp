class Solution {
public:
    int evaluate(int a, int b, char op) {
        switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return b != 0 ? a / b : 0;
        default:
            throw invalid_argument("Invalid operator");
        }
    }
    int evalRPN(vector<string>& t) {
        stack<int> st;
        int n = t.size();
        for (int i = 0; i < n; i++) {
          if (t[i] == "+" || t[i] == "-" || t[i] == "*" || t[i] == "/"){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(evaluate(a, b, t[i][0]));
            } else {
                st.push(stoi(t[i]));
            }
        }
        return st.top();
    }
};