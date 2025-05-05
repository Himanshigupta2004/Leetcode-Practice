class Solution {
public:
    int calculate(string s) {
        unordered_map<char, int> priority = {
            {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
        stack<int> st;
        stack<char> op;
        int num = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (isspace(s[i]))
                continue;
            else if (isdigit(c)) {
                num = num * 10 + (c - '0');
                if (i == s.size() - 1 || !isdigit(s[i + 1])) {
                    st.push(num);
                    num = 0;
                }
            } else if (s[i] == '+' || s[i] == '-' || s[i] == '*' ||
                       s[i] == '/') {
                while (!op.empty() && priority[op.top()] >= priority[s[i]]) {
                    int b = st.top();
                    st.pop();
                    int a = st.top();
                    st.pop();
                    char ope = op.top();
                    op.pop();
                    switch (ope) {
                    case '+':
                        st.push(a + b);
                        break;
                    case '-':
                        st.push(a - b);
                        break;
                    case '*':
                        st.push(a * b);
                        break;
                    case '/':
                        st.push(a / b);
                        break;
                    }
                }
                op.push(s[i]);
            }
        }
        while (!op.empty()) {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            char ope = op.top();
            op.pop();
            switch (ope) {
            case '+':
                st.push(a + b);
                break;
            case '-':
                st.push(a - b);
                break;
            case '*':
                st.push(a * b);
                break;
            case '/':
                st.push(a / b);
                break;
            }
        }

        return st.top();
    }
};