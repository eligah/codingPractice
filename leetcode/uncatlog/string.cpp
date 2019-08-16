#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <tuple>
#include <unordered_map>
#include <vector>

using namespace std;

// 58. Length of Last Word
class Solution {
 public:
  int lengthOfLastWord(string s) {
    istringstream iss(s);
    vector<string> tokens;
    copy(istream_iterator<string>(iss), istream_iterator<string>(),
         back_inserter(tokens));
    if (tokens.empty()) return 0;
    return rbegin(tokens)->size();
  }
};
// 13. Roman to Integer
class Solution {
 public:
  int romanToInt(string s) {
    unordered_map<char, int> code_map = {{'I', 1},   {'V', 5},   {'X', 10},
                                         {'L', 50},  {'C', 100}, {'D', 500},
                                         {'M', 1000}};
    int result = code_map[s[s.size() - 1]];
    for (int i = s.size() - 2; i >= 0; --i) {
      if (code_map[s[i]] >= code_map[s[i + 1]]) {
        result += code_map[s[i]];
      } else {
        result -= code_map[s[i]];
      }
    }
    return result;
  }
};

// 97. Interleaving String
class Solution {
 public:
  bool isInterleave(string s1, string s2, string s3) {
    int m = s1.size();
    int n = s2.size();
    int l = s3.size();
    if (m + n != l) return false;

    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;  // initialization
    for (int i = 1; i <= m; i++)
      dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];  // s2 = empty; s1 = s3
    for (int j = 1; j <= n; j++)
      dp[0][j] =
          dp[0][j - 1] && s2[j - 1] == s3[j - 1];  // s1 = empty; s2 = s3;

    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        // any way from s1 and s2; if they are true -> get next
        dp[i][j] = (dp[i - 1][j] && s3[i + j - 1] == s1[i - 1]) ||
                   (dp[i][j - 1] && s3[i + j - 1] == s2[j - 1]);
      }
    }
    return dp[m][n];
  }
};

// 97. Interleaving String
// path compressed
class Solution {
 public:
  bool isInterleave(string s1, string s2, string s3) {
    int m = s1.size();
    int n = s2.size();
    int l = s3.size();
    if (m + n != l) return false;
    if (m < n) return isInterleave(s2, s1, s3);

    vector<bool> dp(n + 1, false);
    dp[0] = true;  // initialization
    for (int j = 1; j <= n; j++)
      dp[j] = dp[j - 1] && s2[j - 1] == s3[j - 1];  // s1 = empty; s2 = s3;

    int i, j;
    for (int i = 1; i <= m; i++) {
      dp[0] = dp[0] && s1[i - 1] == s3[i - 1];
      for (int j = 1; j <= n; j++) {
        // any way from s1 and s2; if they are true -> get next
        dp[j] = (dp[j - 1] && s3[i + j - 1] == s2[j - 1]) ||
                (dp[j] && s3[i + j - 1] == s1[i - 1]);
      }
    }
    return dp[n];
  }
};

// 14. Longest Common Prefix
// do not use the range based for
class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    int idx = 0;
    if (strs.empty()) return "";
    while (idx < strs[0].size()) {
      for (int i = 1; i < strs.size(); i++) {
        if (idx < strs[i].size() && strs[0][idx] == strs[i][idx]) {
          continue;
        } else {
          return strs[0].substr(0, idx);
        }
      }
      idx++;
    }
    return strs[0].substr(0, idx);
  }
};

// 49. Group Anagrams
// use dictionary store the keys of the group
class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> res;
    unordered_map<string, vector<string>> str_map;
    for (string s : strs) {
      string t = s;
      sort(t.begin(), t.end());
      if (str_map.count(t) == 0)
        str_map.insert({t, vector<string>(1, s)});
      else
        str_map[t].push_back(s);
    }

    for (auto p : str_map) {
      res.push_back(p.second);
    }
    return res;
  }
};

// 38. Count and Say
// pay attention to the while if loop, don't forget increment
class Solution {
 public:
  string countAndSay(int n) {
    string temp = "1";
    string next;
    for (int i = 1; i < n; i++) {
      string next;
      for (int j = 0; j < temp.size(); j++) {
        int counter = 1;
        while (j + 1 < temp.size() && temp[j] == temp[j + 1]) {
          counter++;
          j++;
        }
        next += to_string(counter);
        next.push_back(temp[j]);
      }
      temp = next;
    }
    return temp;
  }
};

// 67. Add Binary
// swap to make the code concise
// add result
class Solution {
 public:
  string addBinary(string a, string b) {
    // swap a and b
    if (a.size() > b.size()) return addBinary(b, a);

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    a += string(b.size() - a.size(), '0');
    string ans;
    // add bit by bit
    int c_0 = 0;
    int i;
    for (int i = 0; i < a.size() && i < b.size(); i++) {
      int a_0 = a[i] - '0', b_0 = b[i] - '0';
      int bit = c_0 + a_0 + b_0;
      c_0 = bit >= 2 ? 1 : 0;
      bit = bit >= 2 ? bit - 2 : bit;
      ans.push_back((bit + '0'));
    }
    if (c_0 == 1) ans.push_back('1');
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
//22. Generate Parentheses 
//use dfs and number of ) and (  as backtracking
class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    vector<string> res;
    addParaenthesis(res, "", n, 0);
    return res;
  }
  void addParaenthesis(vector<string> res, string s, int l, int r) {
    if (l == 0 && r == 0) {
      res.push_back(s);
    }
    if (l > 0) addParaenthesis(res, s + "(", l - 1, r + 1);
    if (r > 0) addParaenthesis(res, s + ")", l - 1, r - 1);
  }
};
