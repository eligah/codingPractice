#include <iostream>
#include <vector>

#include "myUtil.h"

using namespace std;

/* recursive with vector
space: O(2^n)
time: O(2^n) */
void search(int n, int k, const vector<int> &s) {
  if (k == n) {
    vectorOut(s);
    return;
  } else {  // create new space for different set--add current elememt
    vector<int> s_copy(s);
    s_copy.push_back(k);
    search(n, k + 1, s);
    search(n, k + 1, s_copy);
  }
}

/* interation
- O(n * 2^n)
- no more vector space
*/
void search(int n) {
  // for every combination of n element: 1 = contain; 0 = not contain
  for (int i = 0; i < (1 << n); i++) {
    vector<int> subset;
    for (int j = 0; j < n; j++) {
      // check the jth bit of number i equals to 1
      if (i & (1 << j)) {
        subset.push_back(j);
      }
    }
    vectorOut(subset);
  }
}

// recursive with vector
void search(int n, int k, const vector<int> &s) {
  if (k == n) {
    vectorOut(s);
    return;
  } else {  // create new space for different set--add current elememt
    vector<int> s_copy(s);
    s_copy.push_back(k);
    search(n, k + 1, s);
    search(n, k + 1, s_copy);
  }
}

/* iternation does not need to keep its temperate variables invariant
However, recuration need to keep its temperate variables invariant  */
void perm(int start, int end, vector<int> &permutation) {
  if (start == end) {
    vectorOut(permutation);
  } else {
    for (int i = start; i < end; i++) {
      swap(permutation[start], permutation[i]);
      perm(start + 1, end, permutation);
      swap(permutation[start], permutation[i]);
    }
  }
}

int main(int argc, char const *argv[]) {
  int n = 3;
  search(n);

  return 0;
}
