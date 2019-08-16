#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 263. Ugly Number 2
// Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
// verify them!

// hint:
// iteration
class Solution {
 public:
  bool isUgly(int num) {
    if (num <= 0) return false;
    if (num == 1) return true;
    while (num % 2 == 0) num /= 2;
    while (num % 3 == 0) num /= 3;
    while (num % 5 == 0) num /= 5;
    return num == 1;
  }
};

// 264. Ugly Number II 3
// 改成了找到第n个ugly number

// hint
// 使用235指针按照顺序依次生成ugly number
// 从小到大生递推之
// 坑点：初始化；按顺序移动到下一个ugly number
class Solution {
 public:
  int nthUglyNumber(int n) {
    if (n == 0) return -1;
    if (n == 1) return 1;
    vector<int> nums(n);
    int t2 = 0, t3 = 0, t5 = 0;
    nums[0] = 1;
    for (int i = 1; i < n; ++i) {  // the length did not change
      nums[i] = min(nums[t2] * 2, min(nums[t3] * 3, nums[t5] * 5));
      if (nums[i] == 2 * nums[t2]) t2++;  // move next
      if (nums[i] == 3 * nums[t3]) t3++;
      if (nums[i] == 5 * nums[t5]) t5++;
    }
    return nums[n - 1];
  }
};

// 204. Count Primes 
// get the number of prime
// avoid use vector<bool>

// hint
// 不要一个个比较是否是prime（o(n^2))
// 正确的思考是使用表格进行筛选, 第二个数，从平方项，按照倍数置位
// 每用一位 count down1
// Eratosthenes O(n)
class Solution {
 public:
  int countPrimes(int n) {
    if (n <= 1) return false;
    bool* is_prime = new bool[n];
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < n; i++) is_prime[i] = true;
    int count = n - 2;
    for (int i = 2; i * i < n; ++i) {
      if (is_prime[i]) {
        for (int j = i * i; j < n; j += i) {  // avoid assignment repetition
          if (is_prime[j]) {
            is_prime[j] = false;
            count--;
          }
        }
      }
    }
    delete[] is_prime;
    return count;
  }
};
// 279. Perfect Squares
// 找到n的最少数量的square 之和

// hint
// dp opt[n]
// 按照 +平方数的方式填充数组

// pit
// 数组扩张+1 比较好表示第i个数
class Solution {
 public:
  const int LMT = 99999;
  int numSquares(int n) {
    vector<int> opt;
    opt.push_back(0);
    for (int i = 1; i < n + 1; ++i) {
      int step = LMT;
      for (int j = 1; j * j <= i; ++j) {
        step = min(step, opt[i - j * j] + 1);
      }
      opt.push_back(step);
    }
    return opt[n];
  }
};

// 633. Sum of Square Numbers
// 当前数是否拆分成平方之和

// hint
// 判断一个数是否平方数：sqrt * sqrt = row number
// i*i 开始遍历，不要搞square 
class Solution {
 public:
  bool judgeSquareSum(int c) {
    int max_sq = sqrt(c);
    map<int, int> square_table;
    for (int i = 0; i < max_sq + 1; i++) {
      square_table[i * i] = i;
    }
    bool find = false;
    int i = max_sq;
    while (i >= 0) {
      if (square_table.find(c - i * i) != square_table.end()) {
        find = true;
        break;
      }
      i--;
    }
    return find;
  }
};

class Solution {
 public:
  bool judgeSquareSum(int c) {
    int max_sqr = sqrt(c);
    for (int i = max_sqr; i >= 0; i--) {
      int t = sqrt(c - i * i);
      if (t * t == c - i * i) {
        return true;
      }
    }
    return false;
  }
};

// 367. Valid Perfect Square
// 不用sqrt 判断是否平方

// hint
// 二分查找第一个等于平方等于该数的数

class Solution {
 public:
  bool isPerfectSquare(int num) {
    int left = 0, right = num;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      long cur_sqrt = (long)mid * mid;  // consider integer overflow whenever *
      if (cur_sqrt > num) {
        right = mid - 1;
      } else if (cur_sqrt < num) {
        left = mid + 1;
      } else {
        return true;
      }
    }
    return false;
  }
};

// 69. Sqrt(x)
// when the loop end
// left must greater than sqrt(num) right must smaller than sqrt(num)
// left - right =1
class Solution {
 public:
  int mySqrt(int num) {
    int left = 0, right = num;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      long cur_sqrt = (long)mid * mid;  // consider integer overflow whenever *
      if (cur_sqrt > num) {
        right = mid - 1;
      } else if (cur_sqrt < num) {
        left = mid + 1;
      } else {
        return mid;
      }
    }
    return right;
  }
};

// 221. Maximal Square
class Solution {
 public:
  int maximalSquare(vector<vector<char>>& matrix) {
    if (matrix.empty()) {
      return 0;
    }

    int m = matrix.size();
    int n = matrix[0].size();
    int max_len = 0;
    for (int i = m - 1; i >= 0; i--) {
      for (int j = n - 1; j >= 0; j--) {
        int cur_len = min(i + 1, j + 1);
        if (cur_len <= max_len) {
          return max_len * max_len;
        }
        while (cur_len > 0) {
          if (verifySquare(matrix, i, j, cur_len)) {
            max_len = max(max_len, cur_len);
            break;
          } else {
            cur_len--;
          }
        }
      }
    }
    return max_len * max_len;
  }

  bool verifySquare(vector<vector<char>>& matrix, int x, int y, int len) {
    for (int i = x; i > x - len; i--) {
      for (int j = y; j > y - len; j--) {
        if (matrix[i][j] != '1') {
          return false;
        }
      }
    }
    return true;
  }
};

// dp version
class Solution {
 public:
  int maximalSquare(vector<vector<char>>& matrix) {
    if (matrix.empty()) {
      return 0;
    }

    int m = matrix.size();
    int n = matrix[0].size();
    int max_len = 0;
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (!i || !j || matrix[i][j] == '0') {
          dp[i][j] = matrix[i][j] - '0';  // notice that char to int
        } else {
          dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
        }
        max_len = max(max_len, dp[i][j]);
      }
    }
    return max_len * max_len;
  }
};
// 461. Hamming Distance
class Solution {
 public:
  int hammingDistance(int x, int y) {
    uint32_t a = x, b = y;
    uint32_t c = a ^ b;
    int count = 0;
    while (c != 0) {
      count += c & 0x1;
      c >>= 1;  // reassign to c
    }
    return count;
  }
};

// 477. Total Hamming Distance
class Solution {
 public:
  int totalHammingDistance(vector<int>& nums) {
    int sum = 0;
    vector<uint32_t> bit_nums(nums.begin(), nums.end());
    vector<int> bit1_count(32, 0);

    for (auto num : bit_nums) {
      for (int i = 0; i < bit1_count.size(); i++) {
        bit1_count[i] += num & 0x1;
        num >>= 1;
        if (num == 0) break;
      }
    }

    for (int i = 0; i < bit1_count.size(); i++) {
      sum += bit1_count[i] * (nums.size() - bit1_count[i]);
    }
    return sum;
  }
};

// 137. Single Number II
class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    uint32_t a, b;
    a = 0, b = 0;
    for (auto i : nums) {
      a = a ^ i & ~b;
      b = b ^ i & ~a;
    }
    return int(a);
  }
};

// 260. Single Number III
class Solution {
 public:
  vector<int> singleNumber(vector<int>& nums) {
    int diff = accumulate(nums.begin(), nums.end(), 0,
                          bit_xor<int>());  // give the initial value
    // get the last 1-bits
    diff &= -diff;

    vector<int> ret{0, 0};

    // pass2: divide a, b into two group by the sitted bit
    for (int num : nums) {
      if ((num & diff) == 0) {  // preference of bits operator less than ==
        ret[0] ^= num;
      } else {
        ret[1] ^= num;
      }
    }
    return ret;
  }
};
// corner case diff = INT_MIN; - diff = INT_MIN; not overflow
