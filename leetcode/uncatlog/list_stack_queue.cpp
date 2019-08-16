// 150. Evaluate Reverse Polish Notation
// do not over-optimize
class Solution {
 public:
  int evalRPN(vector<string>& tokens) {
    stack<int> s;
    for (string c : tokens) {
      if (!(c == "+" || c == "-" || c == "*" || c == "/")) {
        s.push(stoi(c));
      } else {
        int b = s.top();
        s.pop();
        int a = s.top();
        s.pop();
        if (c == "+")
          s.push(a + b);
        else if (c == "-")
          s.push(a - b);
        else if (c == "*")
          s.push(a * b);
        else if (c == "/")
          s.push(a / b);
      }
    }
    return s.top();
  }
};

// 32. Longest Valid Parentheses
class Solution {
 public:
  int longestValidParentheses(string s) {
    int start = -1, max_len = 0;
    stack<int> stk;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(') {
        stk.push(i);
      } else {
        if (stk.empty()) {
          start = i;  // new begining only current parentheses is invaild
        } else {
          stk.pop();
          if (stk.empty())
            max_len = max(max_len, i - start);  // final length
          else
            max_len = max(max_len, i - stk.top());  // temp length
        }
      }
    }
    return max_len;
  }
};

class Solution {
 public:
  int largestRectangleArea(vector<int>& heights) {
    stack<int> s;
    int result = 0, width = 1;
    for (int height : heights) {
      if (s.empty() || s.top() <= heights) {
        s.push(height);
      } else {
        int h = s.top();
        while (!s.empty() || s.top() >= height) {
          s.pop();
        }
        result = max(result, cur);
        cur = 0;
        s.push(height);
      }
    }
    if (!s.empty()) {
      result = max(result, s.top());
    }
    return result;
  }
};

// 20. Valid Parentheses
class Solution {
 public:
  bool isleftParentheses(char c) { return c == '{' || c == '[' || c == '('; }
  bool isMatch(char c, char rhs) {
    if (c == '}') return rhs == '{';
    if (c == ')') return rhs == '(';
    if (c == ']') return rhs == '[';
    return false;
  }

  bool isValid(string s) {
    stack<char> stk;
    for (char c : s) {
      if (isleftParentheses(c)) {
        stk.push(c);
      } else {
        if (stk.empty() || !isMatch(c, stk.top())) {
          return false;
        } else {
          stk.pop();
        }
      }
    }
    return s.empty();
  }
};
