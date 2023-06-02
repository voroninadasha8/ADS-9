// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
template<typename T>
class BST {
 private:
  struct Node {
    T value;
    int k = 0;
    Node* left = nullptr;
    Node* right = nullptr;;
  };
  Node* root = nullptr;
  Node* addNode(Node* root, const T& val) {
    if (root == nullptr) {
      root = new Node;
      root->value = val;
      root->k = 1;
    } else if (root->value < val) {
      root->right = addNode(root->right, val);
    } else if (root->value > val) {
      root->left = addNode(root->left, val);
    } else {
      root->k++;
    }
    return root;
  }
  int searchNode(Node* root, const T& val) {
    if (root == nullptr) {
      return 0;
    } else if (root->value == val) {
      return root->k;
    } else if (root->value < val) {
      return searchNode(root->right, val);
    } else {
      return searchNode(root->left, val);
    }
  }
  int depth(Node* root) {
    if (root == nullptr) {
      return 0;
    } else {
      int l = depth(root->left);
      int r = depth(root->right);
      return (l > r) ? l + 1 : r + 1;
    }
  }

 public:
  BST() {}
  void Add(const T& val) {
    root = addNode(root, val);
  }
  int search(const T& val) {
    return searchNode(root, val);
  }
  int depth() {
    return depth(root) - 1;
  }
};
#endif  // INCLUDE_BST_H_
