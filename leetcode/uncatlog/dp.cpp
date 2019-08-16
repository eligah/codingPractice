#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <tuple>
#include <unordered_map>
#include <vector>

using namespace std;

// 120. Triangle
// Define adjacent number in the triangle?
class Solution {
 public:
  // top down
  int minimumTotal(vector<vector<int>>& triangle) {
    int level = triangle.size();
    if (level == 0) return 0;
    vector<int> min_sum_path(level, 0);

    min_sum_path[0] = triangle[0][0];
    for (int i = 1; i < level; i++) {
      for (int j = i; j >= 0; j--) {
        if (j == i) {
          min_sum_path[j] = triangle[i][j] + min_sum_path[j - 1];
        } else if (j == 0) {
          min_sum_path[j] = triangle[i][j] + min_sum_path[j];
        } else {
          min_sum_path[j] =
              triangle[i][j] + min(min_sum_path[j - 1], min_sum_path[j]);
        }
      }
    }
    return *min_element(
        min_sum_path.begin(),
        min_sum_path.end());  // find the extremum value in collection
  }
};

// bottom up
class Solution {
 public:
  int minimumTotal(vector<vector<int>>& triangle) {
    int level = triangle.size();
    if (level == 0) return 0;
    vector<int> min_sum_path(triangle[level - 1]);
    // pay attentation to the corner case
    for (int i = level - 2; i >= 0; i--) {
      for (int j = 0; j <= i; j++)
        min_sum_path[j] =
            min(min_sum_path[j], min_sum_path[j + 1]) + triangle[i][j];
    }
    return min_sum_path[0];
  }
};

// 53. Maximum Subarray
class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int result = INT_MIN, curr = 0;  // use buffer to store the result
    for (auto i : nums) {
      curr = max(i, i + curr);
      result = max(result, curr);
    }
    return result;
  }
};

// 152. Maximum Product Subarray
class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    int result = INT_MIN, curr = 1;
    for (auto i : nums) {
    }
  }
};

// 121. Best Time to Buy and Sell Stock
// use another vector to store the highest price
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int days = prices.size();
    if (days == 0) return 0;
    int result = 0;
    vector<int> highest(days, 0);
    highest[days - 1] = prices[days - 1];

    for (int i = prices.size() - 2; i >= 0; i--) {
      highest[i] = max(prices[i], highest[i + 1]);
    }

    for (int i = 0; i < prices.size(); i++) {
      result = max(highest[i] - prices[i], result);
    }
    return result;
  }
};

// 697. Degree of an Array
// try to traverse the nums for one time
// remember and update the result, max_degree and the first index

class Solution {
 public:
  int findShortestSubArray(vector<int>& nums) {
    unordered_map<int, int> first, counter;
    int res = 1, degree = 0;  // output>=1

    for (int i = 0; i < nums.size(); i++) {
      if (first.count(nums[i]) == 0)
        first[nums[i]] = i;
      else if (++counter[nums[i]] > degree) {
        degree = counter[nums[i]];
        res = i - first[nums[i]] + 1;
      } else if (counter[nums[i]] == degree) {
        res = min(res, i - first[nums[i]] + 1);
      }
    }
    return res;
  }
};

// 91. Decode Ways
// !substr（begin, length)
// stoi is the convertion from string to integer
// string::to_str(int i) another direction

class Solution {
 public:
  int numDecodings(string s) {
    int n = s.size();
    vector<int> opt(n, 0);
    // n<=1
    if (n == 0 || n == 1 && s[0] == '0') return 0;
    if (n == 1) return 1;
    // initialization for the first two element
    if (s[n - 1] != '0') opt[n - 1] = 1;

    if (s[n - 2] != '0') {
      if (stoi(s.substr(n - 2, 2)) <= 26)
        opt[n - 2] = 1 + opt[n - 1];
      else
        opt[n - 2] = opt[n - 1];
    }

    // iteration from n-3 position
    for (int i = n - 3; i >= 0; i--) {
      if (s[i] == '0') continue;
      if (stoi(s.substr(i, 2)) <= 26) {
        opt[i] = opt[i + 1] + opt[i + 2];
      } else {
        opt[i] = opt[i + 1];
      }
    }

    return opt[0];
  }
};