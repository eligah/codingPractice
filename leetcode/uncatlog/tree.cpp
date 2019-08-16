#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
 public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() {}

  Node(int _val, Node* _left, Node* _right, Node* _next) {
    val = _val;
    left = _left;
    right = _right;
    next = _next;
  }
};

// 100. Same Tree
//Top down
class Solution {
 public:
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) return true;
    if (!p || !q) return false;
    return p->val == q->val && isSameTree(p->left, q->left) &&
           isSameTree(p->right, q->right);
  }
};

// Iteration
// pit: 按照顺序p，q的顺序依次push
class Solution {
 public:
  bool isSameTree(TreeNode* p, TreeNode* q) {
    stack<TreeNode*> s;
    s.push(p);
    s.push(q);
    // dfs
    while (!s.empty()) {
      p = s.top();
      s.pop();
      q = s.top();
      s.pop();
      if (!p && !q) continue;
      if (!p || !q) return false;
      if (p->val != q->val) return false;
      // order of p,q must be same of
      s.push(p->left);
      s.push(q->left);
      s.push(p->right);
      s.push(q->right);
    }
    return true;
  }
};

// 101. Symmetric Tree
// 类似刚刚那一题，左子树和右子树递归
class Solution {
 public:
  bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    return isSymmetric(root->left, root->right);
  }
  bool isSymmetric(Treenode* ltree, Treenode* rtree) {
    if (!ltree && !rtree) return true;
    if (!ltree || !rtree) return false;
    return ltree->val == rtree->val && isSymmetric(ltree->right, rtree->left) &&
           isSymmetric(ltree->left, rtree->right);
  }
};

// iteration
class Solution {
 public:
  bool isSymmetric(TreeNode* root) {
    if (!root) return true;

    TreeNode *p1, p2;
    stack<TreeNode*> s;
    s.push(root->left);
    s.push(root->right);

    while (!s.empty()) {
      p1 = s.top();
      s.pop();
      p2 = s.top();
      s.pop();

      if (!p1 && !p2) continue;
      if (!p1 || !p2) return false;

      if (p1->val != p2->val) return false;
      s.push(p1->left);
      s.push(p2->right);
      s.push(p1->right);
      s.push(p2->left);
    }
    return true;
  }
};

// 114. Flatten Binary Tree to Linked List
// in place 将二叉树化成串
// 递归将左右两个化为串，获得左子树最后一个节点（右），连接右子树，修正根节点

// recursive
class Solution {
 public:
  void flatten(TreeNode* root) {
    if (!root) return;

    flatten(root->left);
    flatten(root->right);

    // connect the flattened right list to the left and change the root;
    TreeNode* p = root->left;
    if (!root->left) return;
    while (p->right) p = p->right;
    p->right = root->right;
    root->right = root->left;
    root->left = nullptr;
  }
};

// iteration
class Solution {
 public:
  void flatten(TreeNode* root) {
    TreeNode *cur = root, *pre = root;
    stack<TreeNode*> s;
    if (cur) {
      s.push(cur->right);
      s.push(cur->left);
    }
    // remember the pre node and do DFS
    while (!s.empty()) {
      cur = s.top();
      s.pop();
      if (!cur) {
        continue;
      } else {
        // set and update the pre node
        pre->left = nullptr;
        pre->right = cur;
        pre = cur;
      }
      s.push(cur->right);
      s.push(cur->left);
    }
  }
};

// 116. Populating Next Right Pointers in Each Node
class Solution {
 public:
  Node* connect(Node* root) {
    Node* dummy = new Node(0, nullptr, nullptr, nullptr);
    Node *cur = root, *prev;

    while (cur) {
      for (prev = dummy; cur; cur = cur->next) {
        if (cur->left) {
          prev->next = cur->left;
          prev = prev->next;
        }
        if (cur->right) {
          prev->next = cur->right;
          prev = prev->next;
        }
      }
      cur = dummy->next;
      dummy->next = nullptr;
    }
    delete dummy;
    return root;
  }
};

// 117. Populating Next Right Pointers in Each Node II
class Solution {
 public:
  Node* connect(Node* root) {
    if (!root) return root;

    Node* dummy = new Node(0, NULL, NULL, NULL);
    Node *curr = root, *prev;
    while (curr) {
      for (prev = dummy; curr; curr = curr->next) {
        if (curr->left) {
          prev->next = curr->left;
          prev = prev->next;
        }
        if (curr->right) {
          prev->next = curr->right;
          prev = prev->next;
        }
      }
      curr = dummy->next;
      dummy->next = nullptr;
    }
    delete dummy;
    return root;
  }
};

// 105. Construct Binary Tree from Preorder and Inorder Traversal
class Solution {
 public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return buildTree(begin(preorder), end(preorder), begin(inorder),
                     end(inorder));
  }

  template <typename InputIterator>
  TreeNode* buildTree(InputIterator pre_first, InputIterator pre_end,
                      InputIterator in_first, InputIterator in_end) {
    if (pre_first == pre_end) return nullptr;
    if (in_first == in_end) return nullptr;

    auto root = TreeNode(*pre_first);

    auto in_first_l = in_first;
    auto in_end_l = find(in_first, in_end, root.val);
    auto in_first_r = in_end_l + 1;
    auto in_end_r = in_end;

    int l_length = distance(in_first, in_end_l);

    auto pre_first_l = pre_first + 1;
    auto pre_end_l = pre_first_l + l_length;
    auto pre_first_r = pre_end_l;
    auto pre_end_r = pre_end;

    root.left = buildTree(pre_first_l, pre_end_l, in_first_l, in_end_l);
    root.right = buildTree(pre_first_r, pre_end_r, in_first_r, in_end_r);
    return &root;
  }
};

// 889. Construct Binary Tree from Preorder and Postorder Traversal
class Solution {
 public:
  TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
    return buildTree(begin(pre), end(pre), begin(post), end(post));
  }

  template <typename InputIterator>
  TreeNode* buildTree(InputIterator pre_first, InputIterator pre_end,
                      InputIterator post_first, InputIterator post_end) {
    if (pre_first == pre_end) return nullptr;
    if (post_first == post_end) return nullptr;
    auto root = new TreeNode(*pre_first);

    int n = distance(pre_first, pre_end);
    int L = 0;
    for (int i = 0; i < n; i++) {
      if (post[i] = pre[1]) {
        L = i + 1;
        break;
      }
    }
    int R = n - L;
    root->left =
        buildTree(pre_first + 1, pre_first + 1 + L, post_first, post_first + L);
    root->right = buildTree(pre_first + 1 + L, pre_end, post_end - R, post_end);
    return root;
  }
};

class Solution {
 public:
  bool isValidBST(TreeNode* root) {
    if (root == nullptr) return true;
    bool flag = isValidBST(root->left) && isValidBST(root->right);
    if (!flag) return false;
    if (root->left && root->val < root->left->val) return false;
    if (root->right && root->val > root->right->val) return false;
    return true;
  }
};