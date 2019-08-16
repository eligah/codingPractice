// 88. Merge Sorted Array
// O(1) space

// hint: compare from tail to head
// if have extra nums2, copy them back to nums1
class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int cur = m + n - 1;
    for (n = n - 1, m = m - 1; m >= 0 && n >= 0;) {
      nums1[cur--] = nums1[m] < nums2[n] ? nums2[n--] : nums1[m--];
    }
    while (n >= 0) {
      nums1[cur--] = nums2[n--];
    }
  }
};

// 21. Merge Two Sorted Lists
// pit: the rest linked list should only be connect once.
class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    // no need to process the trival situation
    ListNode dummy(-1);
    ListNode* new_l = &dummy;
    while (l1 != nullptr && l2 != nullptr) {
      if (l1->val > l2->val) {
        new_l->next = l2;
        l2 = l2->next;
      } else {
        new_l->next = l1;
        l1 = l1->next;
      }
      new_l = new_l->next;
    }
    if (!l1) new_l->next = l2;
    if (!l2) new_l->next = l1;
    return dummy.next;
  }
};

// 23. Merge k Sorted Lists

// hint: bulid a priority queue(min heap)
// use vector to store it
class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode *root = nullptr, *p = nullptr;
    // use priory_queue, put the key at the first element, and use the default
    // comparasion to // bulid a min heap
    priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>,
                   greater<pair<int, ListNode*>>>
        q;
    // add the first node in each list
    for (auto node : lists) {
      if (node) q.push(make_pair(node->val, node));
    }
    // pop one and push one
    while (!q.empty()) {
      if (root == nullptr) {
        root = p = q.top().second;
      } else {
        p = p->next = q.top().second;
      }
      q.pop();
      if (p->next) q.push(make_pair(p->next->val, p->next));
    }
    return root;
  }
};

// 41. First Missing Positive
class Solution {
 public:
  int firstMissingPositive(vector<int>& nums) {
    bucket_sort(nums);
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] != i + 1) {
        return i + 1;
      }
    }
    return nums.size() + 1;  // if all number is sorted, return next integer
  }

  void bucket_sort(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      while (nums[i] != i + 1) {
        // in case the infinaty loop for the same number
        if (nums[i] <= 0 || nums[i] > n || nums[i] == nums[nums[i] - 1]) {
          break;
        }
        swap(nums[i], nums[nums[i] - 1]);
      }
    }
  }
};

// 268. Missing Number
// hint: use in-place swap
// add -1 as the fill in number
class Solution {
 public:
  int missingNumber(vector<int>& nums) {
    nums.push_back(-1);
    for (int i = 0; i < nums.size(); ++i) {
      while (nums[i] != i) {
        if (nums[i] == -1) {
          ++i;
        }
        swap(nums[i], nums[nums[i]]);
      }
    }
    return distance(nums.begin(), find(nums.begin(), nums.end(), -1));
  }
};

// using bit manipulation
class Solution {
 public:
  int missingNumber(vector<int>& nums) {
    int result = nums.size();
    int i = 0;
    for (int num : nums) {
      result ^= num;
      result ^= i++;
    }
    return result;
  }
};

// 136. Single Number
class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int num : nums) {
      result ^= num;
    }
    return result;
  }
};

// 147. Insertion Sort List
// insertion the sort list
// 创建一个空链表，通过pre, cur,next pointer 将value 依次插入这个链表
// pit: 如果不创建新链表，原来链表构成环，陷入死循环
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
      ListNode dummy(-1);
      ListNode* pre, *cur, *next;
      cur = head;
      while(cur){
        pre = &dummy;
        next = cur->next;
        while(pre->next && pre->next->val < cur->val) pre = pre->next;
        cur ->next = pre->next;
        pre ->next = cur;
        cur = next;
      }
      return dummy.next;
    }
};

// 75. Sort Colors
// sort three number in place
// hint: use three pointer lo,mi,hi satisfy:p0<=p1<p2
// pit: 右边换回来的有可能为0， 因此mi不能++
class Solution {
 public:
  void sortColors(vector<int>& nums) {
    if (nums.empty()) return;
    int lo = 0, mi = 0;
    int hi = nums.size() - 1;
    // lo<=mi; mi < hi
    // check the final element!
    while (mi <= hi) {
      if (nums[mi] == 0) {
        swap(nums[mi++], nums[lo++]);
      } else if (nums[mi] == 2) {
        swap(nums[mi], nums[hi--]);
      } else {
        mi++;
      }
    }
  }
};

// 148. Sort List
// use merge sort to sort list
// hint: find the place to cut the list in the middle, use the slow and fast
// pointer

class Solution {
 public:
  ListNode* sortList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;
    // cut the list
    ListNode *pre = head, *fast = head->next;
    while (fast != nullptr && fast->next != nullptr) {
      fast = fast->next->next;
      pre = pre->next;
    }
    // make two list
    ListNode* head2 = pre->next;
    pre->next = nullptr;
    // sort and update the head pointer
    head = sortList(head);
    head2 = sortList(head2);
    // merge
    return merge(head, head2);
  }

  // the same as the problem: merge the list
  ListNode* merge(ListNode* h1, ListNode* h2) {
    if (h1 == nullptr) return h2;
    if (h2 == nullptr) return h1;
    ListNode dummy(-1);
    ListNode* cur = &dummy;
    while (h1 && h2) {
      if (h1->val > h2->val) {
        cur->next = h2;
        h2 = h2->next;
      } else {
        cur->next = h1;
        h1 = h1->next;
      }
      cur = cur->next;
    }
    if (!h1) cur->next = h2;
    if (!h2) cur->next = h1;
    return dummy.next;
  }
};
