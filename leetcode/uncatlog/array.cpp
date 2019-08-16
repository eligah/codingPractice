#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// 31. Next Permutation
// hint: use dfs to get the next sequence
class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    if (nums.size() <= 1) return;

    int i, j;
    for (i = nums.size() - 2; i > 0; i--) {
      if (nums[i] < nums[i + 1]) break;
    }

    int cur = INT_MAX;
    j = nums.size() - 1;

    while (nums[j] <= nums[i] && j > i) {
      j--;
    }

    if (i == j && i == 0) {
      reverse(nums.begin(), nums.end());
      return;
    }

    swap(nums[i], nums[j]);
    //[i+1, end) must be decreasing order
    reverse(nums.begin() + i + 1, nums.end());
  }
};

// 46. Permutations
class Solution {
 public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    calPermuation(result, 0, nums);
    return result;
  }
  void calPermuation(vector<vector<int>>& result, int left, vector<int>& nums) {
    if (left == nums.size() - 1) {
      result.push_back(nums);
      return;
    }
    for (int i = left; i < nums.size(); i++) {
      swap(nums[i], nums[left]);
      calPermuation(result, left + 1, nums);
      swap(nums[i], nums[left]);
    }
  }
};

// 47. Permutations II
class Solution {
 public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> result;
    result.push_back(nums);
    if (!isReversedSorted(nums)) nextPermutation();
  }
};

class Solution {
 public:
  string getPermutation(int n, int k) {
    string s;
    int i = n - 1;
    while (i--) s.append(n - i);
    kthPermutation(s, k);
    return s;
  }

  void kthPermutation(string& s, int& k, int left) {
    if (left == s.size() - 1) {
      return;
    }

    for (int i = left; i < s.size(); i++) {
      swap(s[i], s[left]);
      kthPermutation(s, k, left + 1);
      swap(s[i], s[left]);
      if (k == 1) {
        return;
      }
    }
  }
};

// 11. Container With Most Water
class Solution {
 public:
  int maxArea(vector<int>& height) {
    vector<int> left;
    for (int i = 0; i < height.size(); i++) {
      left.push_back(i);
    }
    vector<int> right(left);

    for (int i = 0; i < height.size(); i++) {
      int leftmost = i;
      for (int j = i; j >= 0; j--) {
        if (height[j] >= height[i]) leftmost = j;
      }
      left[i] = leftmost;
    }

    for (int i = height.size() - 1; i >= 0; i--) {
      int rightmost = i;
      for (int j = i; j < height.size(); j++) {
        if (height[j] >= height[i]) rightmost = j;
      }
      right[i] = rightmost;
    }

    int ans = 0;
    for (int i = 0; i < height.size(); i++) {
      ans = max(ans, height[i] * (right[i] - left[i]));
    }
    return ans;
  }
};

// use 2 bound
class Solution {
 public:
  int maxArea(vector<int>& height) {
    int i = 0, j = height.size() - 1;
    int water = 0;
    while (i < j) {
      int h = min(height[i], height[j]);
      water = max(water, h * (j - i));
      while (i < j && height[i] <= h)
        i++;  // always move the pointer to reduction
      while (i < j && height[j] <= h) j--;
    }
    return water;
  }
};

// 34 Find First and Last Position of Element in Sorted Array
class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    if (nums.empty()) return {-1, -1};
    int l1 = 0, r1 = nums.size();
    while (l1 + 1 != r1) {
      int mid = (l1 + r1) / 2;
      if (nums[mid] <= target) {
        l1 = mid;
      } else {
        r1 = mid;
      }
    }

    if (nums[l1] != target) {
      return {-1, -1};
    }

    int l2 = -1, r2 = nums.size() - 1;
    while (l2 + 1 != r2) {
      int mid = (l2 + r2) / 2;
      if (nums[mid] < target) {
        l2 = mid;
      } else {
        r2 = mid;
      }
    }
    return {r2, l1};
  }
};

// 74. Search a 2D Matrix
class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;
    int col = distance(matrix[0].begin(),
                       upper_bound(matrix[0].begin(), matrix[0].end(), target));
    if (col == 0) return false;

    if (matrix[0][--col] == target) return true;
    int row;
    for (row = 0; col >= 0 && row < matrix.size(); row++) {
      if (matrix[row][col] == target) {
        return true;
      }
      if (matrix[row][col] > target) {
        col--;
        row = 0;
      }
    }
    return false;
  }
};

// 73. Set Matrix Zeroes
class Solution {
 public:
  void setZeroes(vector<vector<int>>& matrix) {
    if (matrix.empty()) return;
    int m = matrix.size();
    int n = matrix[0].size();
    vector<bool> rows(m, false), cols(n, false);

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == 0) rows[i] = cols[j] = true;
      }
    }

    for (int i = 0; i < m; i++) {
      if (rows[i]) {
        matrix[i] = vector<int>(n, 0);
      }
    }

    for (int j = 0; j < n; j++) {
      if (cols[j]) {
        for (int i = 0; i < m; i++) matrix[i][j] = 0;
      }
    }
  }
};

// 55. Jump Game
class Solution {
 public:
  bool canJump(vector<int>& nums) {
    if (nums.empty()) return false;
    vector<bool> dp(nums.size(), false);
    dp[0] = true;
    for (int i = 0; i < nums.size(); i++) {
      if (!dp[i]) return false;
      int step = nums[i];
      while (step != 0) {
        if (i + step >= dp.size()) return true;
        if (dp[i + step]) break;
        dp[i + step] = true;
        step--;
      }
    }
    return dp[dp.size() - 1];
  }
};

// O(1) use the farest reach place
class Solution {
 public:
  bool canJump(vector<int>& nums) {
    int i = 0;
    for (int reach = 0; i < nums.size() && i <= reach; ++i) {
      reach = max(reach, i + nums[i]);
    }
    return i == nums.size();
  }
};

class LRUCache {
 public:
  LRUCache(int capacity) { this->capacity = capacity; }

  int get(int key) {
    if (cache_map.find(key) == cache_map.end()) return -1;
    cache_list.splice(cache_list.begin(), cache_list, cache_map[key]);
    cache_map[key] = cache_list.begin();
    return cache_map[key]->value;
  }

  void put(int key, int value) {
    if (cache_map.find(key) == cache_map.end()) {
      if (cache_list.size() == capacity) {
        cache_map.erase(cache_list.back().key
      }
    }
  }

 private:
  struct CacheNode {
    int key;
    int value;
    CacheNode(int k, int v) : key(k), value(v) {}
  };
  list<CacheNode> cache_list;
  unordered_map<int, list<CacheNode>::iterator> cache_map;
  int capacity;
};

// 89. Gray Code
// no need to make string convertion
// use pow rather than 2^i
// transform need to initialize the space
// capture the arguement in lambda function[]

class Solution {
 public:
  vector<int> grayCode(int n) {
    if (n < 1) return {0};
    vector<int> code{0, 1};
    for (int i = 1; i < n; i++) {
      vector<int> new_code;
      new_code.resize(code.size());
      transform(code.begin(), code.end(), new_code.begin(),
                [i](int num) { return pow(2, i) + num; }); 
      reverse(new_code.begin(), new_code.end());
      code.insert(code.end(), new_code.begin(), new_code.end());
    }
    return code;
  }
};