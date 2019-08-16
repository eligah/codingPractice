// 35. Search Insert Position
class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      // make use of the invariance;
      // reduce the branch
      if (target > nums[mid]) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return l;
  }
};