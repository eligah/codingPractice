template <typename T>
void BubbleSort(T first, T last) {
  /* 如果在迭代器的范围里面没有至少两个数字的话，那可以直接返回，不需要排序 */
  if (first == last || next(first) == last) return;

  /* 请在这里完成冒泡排序 */
  for (auto i = first; i != prev(last); i++) {
    for (auto j = prev(last); j != i; j--) {
      auto k = prev(j);
      if (*k > *j) {
        auto t = *j;
        *j = *k;
        *k = t;
      }
    }
  }
}

// remove duplicates from sorted array
// T: O(n), S: O(n);
// two index and copy one by one
int removeDuplicates(vector<int>& nums) {
  if (nums.empty()) return 0;
  int k = 0;
  for (int i = 1; i < nums.size(); i++) {
    if (nums[k] != nums[i]) {
      nums[++k] = nums[i];
    }
  }
  return k + 1;
}

// stl unique
int removeDuplicates(vector<int>& nums) {
  return distance(nums.begin(), unique(nums.begin(), nums.end()));
}

// stl
int removeDuplicates(vector<int>& nums) {
  return distance(nums.begin(),
                  removeDuplicates(nums.begin(), nums.end(), nums.begin()));
}

template <typename InIt, typename OutIt>
OutIt removeDuplicates(InIt first, InIt last,
                       OutIt output) {  // overload the original problem
  while (first != last) {
    *output++ = *first;
    first = upper_bound(first, last, *first);  // make sure first is ascending
  }
  return output;
}

// remove duplicate in sorted array 2
// index denotes the end of the feasible array
int removeDuplicates(vector<int>& nums) {
  if (nums.size() <= 2) {
    return nums.size();
  }
  int index = 2;
  for (int i = 2; i < nums.size(); i++) {
    if (nums[i] != nums[index - 2]) {
      nums[index++] = nums[i];
    }
  }
  return index;
}

// search in rotate sorted array
int search(vector<int>& nums, int target) {
  int first = 0, last = nums.size();
  while (first != last) {
    const int mid = (first + last) / 2;
    if (nums[mid] == target) return mid;
    if (nums[first] <= nums[mid]) {  // equal: nums.size() = 1
      if (nums[first] <= target && target <= nums[mid]) {
        last = mid;
      } else {
        first = mid + 1;
      }
    } else {
      if (nums[mid] < target && target <= nums[last - 1]) {
        first = mid + 1;
      } else {
        last = mid;
      }
    }
  }
  return -1;
}

// search in rotate array 2(duplicate)

bool search(vector<int>& nums, int target) {
  int first = 0, last = nums.size();
  while (first != last) {
    const int mid = (first + last) / 2;
    if (nums[mid] == target) return true;

    if (nums[first] < nums[mid]) {
      if (nums[first] <= target && target < nums[mid]) {
        last = mid;
      } else {
        first = mid + 1;
      }
    } else if (nums[first] > nums[mid]) {
      if (nums[mid] < target && target <= nums[last - 1]) {
        first = mid + 1;
      } else {
        last = mid;
      }
    } else {  // nums[first] = nums[mid] [1,2,3,1,1,1,1]
      first++;
    }
  }
  return false;
}

//  remove the neighbor duplicate
bool search(vector<int>& nums, int target) {
  int l = 0, r = nums.size() - 1;
  while (l <= r) {
    while (l < r && nums[l] == nums[l + 1]) l++;
    while (l < r && nums[r] == nums[r - 1]) r--;

    const int mid = (l + r) / 2;
    if (nums[mid] == target) return true;
    if (nums[mid] > nums[r]) {
      if (nums[l] <= target && target < nums[mid]) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    } else if (nums[mid] < nums[l]) {
      if (nums[mid] < target && target <= nums[r]) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    } else {
      if (nums[mid] > target) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
  }
  return false;
}

// find median
class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    const int m = nums1.size();
    const int n = nums2.size();
    int total = m + n;
    if (total % 2 == 1)
      return findK(nums1.begin(), m, nums2.begin(), n, total / 2 + 1);
    else
      return (findK(nums1.begin(), m, nums2.begin(), n, total / 2) +
              findK(nums1.begin(), m, nums2.begin(), n, total / 2 + 1)) /
             2.0;  // keep double
  }

  int findK(vector<int>::const_iterator A, int m, vector<int>::const_iterator B,
            int n, int k) {
    if (m > n) return findK(B, n, A, m, k);
    if (m == 0) return *(B + k - 1);
    if (k == 1) return min(*A, *B);

    int ia = min(m, k / 2), ib = k - ia;
    if (*(A + ia - 1) < *(B + ib - 1))
      return findK(A + ia, m - ia, B, n, k - ia);
    else if (*(A + ia - 1) > *(B + ib - 1))
      return findK(A, m, B + ib, n - ib, k - ib);
    else
      return *(A + ia - 1);
  }
};

// longest conse
class Solution {
 public:
  int longestConsecutive(const vector<int>& nums) {
    unordered_map<int, bool> used;

    for (auto i : nums) used[i] = false;

    int longest = 0;
    for (auto i : nums) {
      if (used[i]) continue;

      int length = 1;
      used[i] = true;

      for (int j = i + 1; used.find(j) != used.end(); ++j) {
        used[j] = true;
        length++;
      }
      for (int j = i - 1; used.find(j) != used.end(); --j) {
        used[j] = true;
        length++;
      }

      longest = max(longest, length);
    }
    return longest;
  }
};

class Solution {
 public:
  int longestConsecutive(const vector<int>& nums) {
    unordered_map<int, int> map;
    int size = nums.size();
    int l = 1;
    for (int i = 0; i < size; i++) {
      if (map.find(nums[i]) != map.end()) continue;
      map[nums[i]] = 1;
      if (map.find(nums[i] - 1) != map.end())
        l = max(l, mergeCluster(map, nums[i] - 1, nums[i]));
      if (map.find(nums[i] + 1) != map.end())
        l = max(l, mergeCluster(map, nums[i], nums[i] + 1));
    }
    return size == 0 ? 0 : l;
  }

  int mergeCluster(unordered_map<int, int>& map, int left, int right) {
    int upper = right + map[right] - 1;
    int lower = left - map[left] + 1;
    int length = upper - lower + 1;
    map[lower] = length;
    map[upper] = length;
    return length;
  }
};

// two sum
class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> result;
    int div = target / 2;
    if (target % 2 == 0 && count(nums.begin(), nums.end(), div) == 2) {
      auto first = find(nums.begin(), nums.end(), div);
      auto second = find(first + 1, nums.end(), div);
      result.push_back(first - nums.begin());
      result.push_back(second - nums.begin());
      return result;
    }
    unordered_map<int, int> map;

    for (int i = 0; i < nums.size(); i++) {
      map[nums[i]] = i;
    }
    for (int i = 0; i < nums.size(); i++) {
      const int gap = target - nums[i];
      if (map.find(gap) != map.end() && map[gap] > i) {
        result.push_back(map[nums[i]]);
        result.push_back(map[gap]);
        break;
      }
    }
    return result;
  }
};

// 3sum
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> result;
    if (nums.size() < 3)
      return result;
    sort(nums.begin(), nums.end());
    const int target = 0;

    for (auto i = nums.begin(); i < nums.end() - 2; i++) {
      if (i > nums.begin() && *i == *(i - 1)) {
        continue;
      }

      auto j = i + 1;
      auto k = nums.end() - 1;

      while (j < k) {
        if (*i + *j + *k < target) {
          ++j;
          while (*j == *(j - 1) && j < k) {
            ++j;
          }
        } else if (*i + *j + *k > target) {
          --k;
          while (*k == *(k + 1) && j < k) {
            --k;
          }
        } else {
          result.push_back({*i, *j, *k});
          ++j, --k;
          while (*j == *(j - 1) && j < k) {
            ++j;
          }
        }
      }
    }

    return result;
  }
};

// 3-sum closet
class Solution {
public:
  int threeSumClosest(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    int result{};
    int min_gap = INT32_MAX;

    for (auto a = nums.begin(); a != nums.end() - 2; a++) {
      auto b = next(a);
      auto c = prev(nums.end());

      while (b < c) {
        const int sum = *a + *b + *c;
        const int gap = abs(sum - target);

        if (gap < min_gap) {
          result = sum;
          min_gap = gap;
        }
        if (sum < target) {
          ++b;
        } else {
          --c;
        }
      }
    }
    return result;
  }
};

//remove element
//no necessary to sort the array
class Solution {
public:
  int removeElement(vector<int> &nums, int val) {
    sort(nums.begin(), nums.end());
    auto i = find(nums.begin(), nums.end(), val);
    if(i == nums.end()){
      return nums.size();
    }
    auto j = upper_bound(nums.begin(), nums.end(), val);

    for (; j != nums.end(); ++j) {
      *(i++) = *j;
    }
    return i - nums.begin();
  }
};

// stl
  int removeElement(vector<int> &nums, int val) {
    return distance(nums.begin(), remove(nums.begin(), nums.end(), val));
  }
// 
class Solution {
public:
  int removeElement(vector<int> &nums, int val) {
    int index = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != val) {
        nums[index++] = nums[i];
      }
    }
    return index;
  }
};

//vaild sudoku
class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    bool used[9]{};

    for (int i = 0; i < 9; i++) {
      fill(used, used + 9, false);
      for (int j = 0; j < 9; j++) {
        if (!check(board[i][j], used)) {
          return false;
        }
      }
      fill(used, used + 9, false);
      for (int j = 0; j < 9; j++) {
        if (!check(board[j][i], used)) {
          return false;
        }
      }
    }

    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        fill(used, used + 9, false);
        for (int p = 0; p < 3; p++) {
          for (int q = 0; q < 3; q++) {
            if (!check(board[i * 3 + p][j * 3 + q], used)) {
              return false;
            }
          }
        }
      }
    }

    return true;
  }

  bool check(char ch, bool used[9]) {
    if (ch == '.') {
      return true;
    }
    if (used[ch - '1']) {
      return false;
    }
    return used[ch - '1'] = true;
  }
};

// trapping rain water
class Solution {
public:
  int trap(vector<int> &height) {
    if (height.size() < 3) {
      return 0;
    }
    vector<int> l_height(height.size(), 0);
    vector<int> r_height(height.size(), 0);

    for (int i = 1; i < height.size(); ++i) {
      int curr = height[i - 1];
      for (int l = i - 1; l >= 0; --l) {
        l_height[i] = max(l_height[i], height[l]);
      }
    }

    for (int j = 0; j < height.size() - 1; ++j) {
      int curr = height[j + 1];
      for (int r = j + 1; r < height.size(); ++r) {
        r_height[j] = max(r_height[j], height[r]);
      }
    }

    vector<int> storage(height.size(), 0);
    for (int i = 0; i < height.size(); i++) {
      int valid_height = min(l_height[i], r_height[i]) - height[i];
      if (valid_height > 0) {
        storage[i] = valid_height;
      }
    }
    return accumulate(storage.begin(), storage.end(), 0);
  }
};

//rotate image
class Solution {
public:
  void rotate(vector<vector<int>> &matrix) {
    int n = matrix.size();
    for (auto &row : matrix) { // reference to change the vector in container
      cout << endl;
      reverse(row.begin(), row.end());
      cout << endl;
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n - 1 - i; j++) {
        swap(matrix[i][j], matrix[n - 1 - j][n - i - 1]);
      }
    }
  }
};

// plus one 
class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    add(digits, 1);
    return digits;
  }

  void add(vector<int> &digits, int digit) {
    int c = digit;
    for (auto it = digits.rbegin(); it != digits.rend(); it++) {
      if (c == 0)
        break;
      *it += c;
      c = *it / 10;
      *it %= 10;
    }
    if (c > 0)
      digits.insert(digits.begin(), c);
  }
};

// climb stair
class Solution {
public:
  int climbStairs(int n) {
    if (n < 2) {
      return n;
    }
    vector<int> ways(n+1, 0);
    ways[0] = 0;
    ways[1] = 1;
    ways[2] = 2;
    for (auto i = next(ways.begin(),3); i!= ways.end();i++)
    {
      *i = *prev(i) + *prev(i, 2);
    }
    return ways[n];
  }
};

// gas station
class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int total = 0;
    int j = -1;
    for (int i = 0, sum = 0; i < gas.size(); i++) {
      sum += gas[i] - cost[i];
      total += gas[i] - cost[i];

      if (sum < 0) {
        j = i;
        sum = 0;
      }
    }
    return total >= 0 ? j + 1 : -1;
  }
};

// add two numbers
class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    int c = 0;
    ListNode dummy(-1); // avoid the case of one node
    ListNode *prev = &dummy;
    for (ListNode *pa = l1, *pb = l2; pa != nullptr || pb != nullptr;
         pa = pa == nullptr ? nullptr : pa->next, pb = pb == nullptr ? nullptr : pb->next,
                  prev = prev->next) {
      const int ai = pa == nullptr ? 0 : pa->val;
      const int bi = pb == nullptr ? 0 : pb->val;
      prev->next = new ListNode((ai + bi + c) % 10);
      c = (ai + bi + c) / 10;
    }
    if (c > 0) {
      prev->next = new ListNode(c);
    }
    return dummy.next;
  }
};
// reverse linked list1
class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    if (head == nullptr) {
      return nullptr;
    }

    ListNode dummy = ListNode(-1);
    dummy.next = head;
    ListNode *prev = head;
    ListNode *curr = head->next;
    while (curr != nullptr) {
      prev->next = curr->next;
      curr->next = dummy.next;
      dummy.next = curr;
      curr = prev->next;
    }
    return dummy.next;
  }
};

// reverse linked list2
class Solution {
public:
  ListNode *reverseBetween(ListNode *head, int m, int n) {
    ListNode dummy(-1);
    dummy.next = head;

    ListNode *prev = &dummy;
    for (int i = 0; i < m - 1; ++i) {
      prev = prev->next;
    }

    ListNode *const head2 = prev;
    prev = head2->next;
    ListNode *cur = prev->next;

    for (int j = 0; j < n - m; ++j) {
      prev->next = cur->next;
      cur->next = head2->next;
      head2->next = cur;
      cur = prev->next;
    }
    return dummy.next;
  }
};

//partition list
class Solution {
public:
  ListNode *partition(ListNode *head, int x) {
    ListNode left_dummy(-1);
    ListNode right_dummy(-1);
    auto left_cur = &left_dummy;
    auto right_cur = &right_dummy;

    for (ListNode *cur = head; cur != nullptr; cur=cur->next) {
      if (cur->val < x) {
        left_cur->next = cur;
        left_cur = cur;
      } else {
        right_cur->next = cur;
        right_cur = cur;
      }
    }
    left_cur->next = right_dummy.next;
    right_cur->next = nullptr;
    return left_dummy.next;
  }
};

// remove duplicates from sorted list
class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    if (head == nullptr) {
      return nullptr;
    }
    ListNode *prev = head;
    ListNode *cur = head->next;
    while (cur != nullptr) {
      if (prev->val == cur->val) {
        prev->next = cur->next;
        delete cur;
        cur = prev->next;
      } else {
        cur = cur->next;
        prev = prev->next;
      }
    }
    return head;
  }
};

//remove duplicate from sorted list 2
class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    if (!head || !head->next) {
      return head;
    }

    ListNode *p = head->next;
    if (head->val == p->val) {
      while (p && head->val == p->val) {
        ListNode *tmp = p;
        p = p->next;
        delete tmp;
      }
      delete head;
      return deleteDuplicates(p);
    } else {
      head->next = deleteDuplicates(head->next);
      return head;
    }
  }
};

//
class Solution {
public:
  ListNode *rotateRight(ListNode *head, int k) {
    if (head == nullptr || k == 0) {
      return head;
    }

    int length = 1;
    ListNode *last = head;
    for (; last->next != nullptr; last = last->next) {
      ++length;
    }

    k = length - k % length; // list_left -> next = move list

    ListNode *list_left = head;
    int idx = length - k - 1; //
    last->next = head;
    for (int step = 0; step < k; ++step) {
      list_left = list_left->next;
    }
    ListNode *new_head = list_left->next;
    list_left->next = nullptr;
    return new_head;
  }
};
//Remove Nth Node From End of List
class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    if (head == nullptr) {
      return head;
    }
    ListNode dummy(INT_MIN);
    dummy.next = head;
    int length = 0;
    ListNode *cur1 = &dummy, *cur2 = &dummy;
    for (int i = 0; i < n; ++i) {
      cur2 = cur2->next;
    }

    while (cur2->next != nullptr) {
      cur2 = cur2->next;
      cur1 = cur1->next;
    }

    ListNode *tmp = cur1->next;
    cur1->next = cur1->next->next;
    delete tmp;
    return dummy.next;
  }
};

//24. Swap Nodes in Pairs
class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    ListNode dummy(INT_MIN);
    dummy.next = head;
    ListNode *prev = &dummy;
    ListNode *curr1 = prev->next;
    ListNode *curr2 = curr1->next;

    for (ListNode *prev = &dummy, *curr1 = prev->next, *curr2 = curr1->next;
         curr2 != nullptr; prev = curr1, curr1 = curr1->next,
                  curr2 = curr1 ? curr1->next:nullptr) {
      curr1->next = curr2->next;
      prev->next = curr2;
      curr2->next = curr1;
    }
    return dummy.next;
  }
};

//141. Linked List Cycle
class Solution {
public:
  bool hasCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
      if (slow == fast)
        return true;
    }
    return false;
  }
};

//7. Reverse Integer
class Solution {
public:
  int reverse(int x) {
    long long r = 0;
    long long t = x;

    t = t > 0 ? t : -t;
    for (; t > 0; t /= 10) {
      r = r * 10 + t % 10;
    }

    bool sign = x < 0 ? true: false;
    if ((sign && r > 2147483648) || (!sign && r > INT_MAX)) {
      return 0;
    }

    if (sign) {
      return -r;
    } else {
      return r;
    }
  }
};

//reverse bits
class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t r = 0;
    int i = 0;
    while (n != 0) {
      r <<= 1;
      r |= (n & 0x1); // bits operation
      ++i;
      n >>= 1; // divide by 2
    }
    return r == 0 ? 0 : r << (32 - i);
  }
};

//191. Number of 1 Bits
class Solution {
public:
  int hammingWeight(uint32_t n) {
    int cnt = 0;
    while (n) { // much faster
      cnt += n & 0x1; // no need to use 0,1 if
      n >>= 1;
    }
    return cnt;
  }
};
 
//231. Power of Two
class Solution {
public:
  bool isPowerOfTwo(int n) {
    if (n < 1) {
      return false;
    }
    uint32_t r = n;
    int cnt = 0;
    while (n) {
      cnt += n & 0x1;
      n>>=1;
      if (cnt > 1) {
        return false;
      }
    }
    return true;
  }
};

class Solution {
public:
  bool isPowerOfThree(int n) {
    if (n <= 0)
      return false;
// notice the bits of max positive int and the convertion from double to int
    int max_power_of_3 = pow(3, (int)(log(0x7fffffff) / log(3))); 
    return (max_power_of_3 % n) == 0;
  }
};

//342. Power of Four
class Solution {
public:
  bool isPowerOfFour(int num) {
    int cnt = 0;
    while (num != 0) {
      cnt += num & 0x1;
      if ((num & 0x2) != 0) {
        return false;
      }
      num >>= 2;
    }
    return cnt == 1;
  }
};


// 322. Coin Change
class Solution {
public:
  const int MAX_NUM = 999999;

  int coinChange(vector<int> &coins, int amount) {
    if (amount < 0) {
      return -1;
    }

    sort(coins.begin(), coins.end());// assert the coins are ordered so the array will be filled in a right sequence
      
    vector<int> opt(amount + 1, MAX_NUM);
    opt[0] = 0;
    for (int i = 1; i < opt.size(); i++) {
      for (int j = 0; j < coins.size(); j++) {
        if (coins[j] > i) {
          break;
        }
        opt[i] = min(opt[i], opt[i - coins[j]] + 1);
      }
    }
    return opt[amount] == MAX_NUM ? -1 : opt[amount];
  }
};

// 9. Palindrome Number
class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0)
      return false;
    long long reverse_num = 0, num = x; // if there is multiply, use long long in case of overflow
    while (num != 0) {
      reverse_num = 10 * reverse_num + num % 10;
      num /= 10;
    }
    return x == reverse_num;
  }
};

//57. Insert Interval
class Solution {
 public:
  vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)
  {
    auto it = intervals.begin();

    while (it != intervals.end()) {
      if (newInterval.end < it->start) {
        intervals.insert(it, newInterval);
        return intervals;
      } else if (newInterval.start > it->end) {
        ++it;
        continue;
      } else {  // update the interval with no over-lapping
        newInterval.start = min(newInterval.start, it->start);
        newInterval.end = max(newInterval.end, it->end);
        it = intervals.erase(it);
      }
    }
    return intervals;
  }
};
// merge intervals
class Solution {
 public:
  vector<Interval> merge(vector<Interval>& intervals) {
    if (intervals.empty()) {
      return intervals;
    }

    auto order = [](const Interval& lhs, const Interval& rhs) {
      return lhs.start < rhs.start;
    };

    sort(intervals.begin(), intervals.end(), order);
    for (auto cur = intervals.begin(), incoming = next(cur);
         incoming != intervals.end();) {
      if (cur->end >= incoming->start) {
        incoming->start = min(incoming->start, cur->start);
        incoming->end = max(incoming->end, cur->end);
        cur = intervals.erase(cur);
        incoming = next(cur);
      } else {
        ++cur;
        ++incoming;
      }
    }
    return intervals;
  }
};


//Multiply Strings
typedef vector<int> bigint;

bigint make_bigint(const string& repr) {
  bigint n;
  transform(repr.rbegin(), repr.rend(), back_inserter(n),
            [](char c) { return c - '0'; });
  return n;
}

string to_string(const bigint& n) {
  string str;
  auto start =  // int -> char of c; int c = 0 -> c = '\0'; leave the last 0 and remove the rest
      find_if(n.rbegin(), prev(n.rend()), [](char c) { return c > '\0'; });  
  transform(start, n.rend(), back_inserter(str),
            [](char c) { return c + '0'; });
  return str;
}

bigint operator*(const bigint& x, const bigint& y) {
  bigint z(x.size() + y.size());
  for (size_t i = 0; i < x.size(); ++i) {
    for (size_t j = 0; j < y.size(); ++j) {
      z[i + j] += x[i] * y[j];
      z[i + j + 1] += z[i + j] / 10;
      z[i + j] %= 10;
    }
  }
  return z;
}

class Solution {
 public:
  string multiply(string num1, string num2) {
    return to_string(make_bigint(num1) * make_bigint(num2));
  }
};

//118. Pascal's Triangle
class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> pascal_tri;
    if (numRows <= 0) {
      return pascal_tri;
    }

    pascal_tri.push_back({1});

    for (int j = 2; j <= numRows; j++) {
      vector<int> current(j, 1); // initialize and substitute rather than insert it.
      const vector<int>& prev = pascal_tri[j - 2]; // difference of the index num of row to the index in tri.

      for (int k = 1; k < j - 1; ++k) {
        current[k] = prev[k] + prev[k - 1];
      }
      pascal_tri.push_back(current);
    }
    return pascal_tri;
  }
};

//119. Pascal's Triangle II
class Solution {
 public:
  vector<int> getRow(int rowIndex)
  { 
    vector<int> result;
    if (rowIndex < 0) {
      return result;
    }

    vector<int> prev = {1};
    if (rowIndex == 0) {
      return prev;
    }

    for (int i = 2; i <= rowIndex + 1; i++) {
      result = vector<int>(i, 1);
      for (int j = 1; j < i - 1; j++) {
        result[j] = prev[j] + prev[j - 1];
      }
      prev = result;
    }
    return result;
  }
};

// 54. Spiral Matrix
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {  
      vector<int> result;
      if(matrix.empty()) return result;
      int begin_x = 0, end_x = matrix[0].size() - 1;
      int begin_y = 0, end_y = matrix.size() - 1;
      
      while(true) {
        for(int j = begin_x; j <= end_x; j++) result.push_back(matrix[begin_y][j]);
        if(++begin_y > end_y) break;

        for(int i = begin_y; i <= end_y; i++) result.push_back(matrix[i][end_x]);
        if(--end_x < begin_x) break;
        
        for(int j = end_x; j >= begin_x; j--) result.push_back(matrix[end_y][j]);
        if(--end_y < begin_y) break;
        
        for(int i = end_y; i >= begin_y; i--) result.push_back(matrix[i][begin_x]);
        if(++begin_x > end_x) break;
      }
      return result;
    }
};
// 59. Spiral Matrix II
class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {

    vector<vector<int>> spiral_mat(n, vector<int>(n, 1));
    int cnt = 1;

    int begin_x = 0, begin_y = 0;
    int end_x = n - 1, end_y = n - 1;
    while (true) {
      for (int j = begin_x; j <= end_x; j++) {
        spiral_mat[begin_y][j] = cnt++;
      }
      if (++begin_y > end_y) break;

      for (int i = begin_y; i <= end_y; i++) {
        spiral_mat[i][end_x] = cnt++;
      }
      if (--end_x < begin_x) break;

      for (int j = end_x; j >= begin_x; j--) {
        spiral_mat[end_y][j] = cnt++;
      }
      if (--end_y < begin_y) break;

      for (int i = end_y; i >= begin_y; i--) {
        spiral_mat[i][begin_x] = cnt++;
      }
      if (++begin_x > end_x) break;
    }
    return spiral_mat;
  }
};

//144. Binary Tree Preorder Traversal
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
      stack<TreeNode*> stk;
      vector<int> result;
      
      if(root!=nullptr) stk.push(root);
      
      while(!stk.empty()) {
        TreeNode temp(*stk.top());
        stk.pop();
        result.push_back(temp.val);
        if(temp.right != nullptr) stk.push(temp.right);
        if(temp.left != nullptr) stk.push(temp.left);
      }
      return result;
    }
};
//144. Binary Tree inorder Traversal
class Solution {
 public:
  vector<int> inorderTraversal(TreeNode* root) {
    stack<TreeNode*> stk;
    vector<int> result;

    TreeNode* p = root;
    while (!stk.empty() || p != nullptr) { // combine the root step. always push the non-empty pointer
      if (p != nullptr) {
        stk.push(p);
        p = p->left;
      } else {
        p = stk.top();
        stk.pop();
        result.push_back(p->val);
        p = p->right;
      }
    }
    return result;
  }
};

class Solution {
 public:
  vector<int> inorderTraversal(TreeNode* root) {
    stack<pair<bool, TreeNode*>> s;
    vector<int> result;
    
    if(!root){
      return result;
    }
    pair<bool, TreeNode*> p(false, root);
    s.push(p);
    while (!s.empty()) {
      p = s.top();
      s.pop();
      if (!p.first) {
        if (p.second->right != nullptr)
          s.push(make_pair(false, p.second->right));
        s.push(make_pair(true, p.second));
        if (p.second->left != nullptr) 
          s.push(make_pair(false, p.second->left));
      } else {
        result.push_back(p.second->val);
      }
    }
    return result;
  }
};

//145. Binary Tree Postorder Traversal
class Solution {
 public:
  vector<int> postorderTraversal(TreeNode* root) {
    stack<pair<bool, TreeNode*>> s; // use stack
    vector<int> result;
    if(!root){
      return result;
    }
    pair<bool, TreeNode*> p(false, root);
    s.push(p);
    while (!s.empty()) {
      p = s.top();
      s.pop();
      if (!p.first) {
        s.push(make_pair(true, p.second));
        if (p.second->right != nullptr)
          s.push(make_pair(false, p.second->right));
        if (p.second->left != nullptr) 
          s.push(make_pair(false, p.second->left));
      } else {
        result.push_back(p.second->val);
      }
    }
    return result;
  }

//102. Binary Tree Level Order Traversal;107. Binary Tree Level Order Traversal II
  class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    traverse(root, 1, result);
    return result;
  }

  void traverse(TreeNode* root, int level, vector<vector<int>>& result) {
    if (root == nullptr) return;
    if (level > result.size()) {
      result.push_back({});
    }

    result[level - 1].push_back(root->val);
    if (root->left != nullptr) traverse(root->left, level + 1, result);
    if (root->right != nullptr) traverse(root->right, level + 1, result);
  }
};

class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    queue<TreeNode *> curr, next;
    if (!root) {
      return result;
    }
    TreeNode* n = root;
    curr.push(n);
    while (!curr.empty()) {
      vector<int> level;
      while (!curr.empty()) {
        n = curr.front();
        curr.pop();
        level.push_back(n->val);
        if (n->left) next.push(n->left);
        if (n->right) next.push(n->right);
      }
      swap(curr, next);
      result.push_back(level);
    }
    return result;
  }
};

//111. Minimum Depth of Binary Tree
class Solution {
 public:
  int minDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    return getMinDepth(root, 1);
  }
  const int MAX_DEPTH = 99999;
  int getMinDepth(TreeNode* root, int level) {
    if (root->left == nullptr && root->right == nullptr) return level;
    int l_depth = MAX_DEPTH, r_depth = MAX_DEPTH;
    if (root->left != nullptr) {
      l_depth = getMinDepth(root->left, level + 1);
    }
    if (root->right != nullptr) {
      r_depth = getMinDepth(root->right, level + 1);
    }
    return min(l_depth, r_depth);
  }
};

//104. Maximum Depth of Binary Tree
class Solution {
 public:
  int maxDepth(TreeNode* root)
  { 
    if (root == nullptr) return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
  }
};

//110. Balanced Binary Tree
class Solution {
 public:
  bool isBalanced(TreeNode* root) {
    if (!root) return true;
    return abs(maxDepth(root->left) - maxDepth(root->right)) <= 1 &&
           isBalanced(root->right) && isBalanced(root->left); 
  }

  int maxDepth(TreeNode* root) {
    return root ? max(maxDepth(root->left), maxDepth(root->right)) + 1 : 0;
  }
};
// bottom up DFS O(N), bottom-up(why?) calculate the height need bottom-up
// use -1 as the flag of imbalance
// 
class Solution {
 public:
  bool isBalanced(TreeNode* root) {
    int height = 0;
    return getheight(root) != -1;
  }
  int getheight(TreeNode* root) {
    if (!root) return 0;
    int left = getheight(root->left);
    if (left == -1) return -1;

    int right = getheight(root->right);
    if (right == -1) return -1;

    if (abs(left - right) > 1) return -1;

    return max(left, right) + 1;
  }
};
//559. Maximum Depth of N-ary Tree
class Solution {
 public:
  int maxDepth(Node* root) {
    if (!root) return 0;
    if (root->children.empty()) return 1; // combine the trival case

    int cur_max = 0;
    for (auto i = root->children.begin(); i != root->children.end(); ++i) { //use for-each
      cur_max = max(cur_max, maxDepth(*i));
    }
    return cur_max + 1;
  }
};

class Solution {
 public:
  int maxDepth(Node* root) {
    if (!root) return 0;
    int cur_max = 0;
    for (auto i: root->children) {
      cur_max = max(cur_max, maxDepth(i));
    }
    return cur_max + 1;
  }
};

// 103. Binary Tree Zigzag Level Order Traversal
// use one queue for bfs
class Solution {
 public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    queue<TreeNode*> cur;
    vector<vector<int>> result;
    if (root == nullptr) {
      return result;
    }
    bool r = false; // reverse flag
    cur.push(root);
    while (!cur.empty()) {
      int sz = cur.size();
      vector<int> row(sz,0);
      while (sz--) { //for every level
        TreeNode* p = cur.front();
        cur.pop();
        row[row.size() - sz - 1] = p->val;
        if (p->left != nullptr) cur.push(p->left);
        if (p->right != nullptr) cur.push(p->right);
      }
      if (r) reverse(row.begin(), row.end());
      r = !r;
      result.push_back(row);
    }
    return result;
  }
};


//99. Recover Binary Search Tree
class Solution {
 public:
  void recoverTree(TreeNode* root) {
    if (root == nullptr) return;
    vector<TreeNode*> tree;
    stack<pair<bool, TreeNode*>> s;
    pair<bool, TreeNode*> p = {false, root};
    s.push(p);
    while (!s.empty()) {
      p = s.top();
      s.pop();
      if (!p.first) {
        if (p.second->right != nullptr) s.push({false, p.second->right});
        s.push({true, p.second});
        if (p.second->left != nullptr) s.push({false, p.second->left});

      } else {
        tree.push_back(p.second);
      }
    }

    int left = 0, right = tree.size() - 1;
    while (left + 1 < tree.size() && tree[left]->val < tree[left + 1]->val) {
      left++;
    }
    while (right - 1 >= 0 && tree[right]->val > tree[right - 1]->val) {
      right--;
    }
    swap(tree[left]->val, tree[right]->val);
    cout << endl;
  }
};