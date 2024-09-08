#include "avlnode.h"
#include <iostream>

template <typename T>
class avl {
private:
  node<T> *root;

  int getHeight(node<T> *root) {

    if (root == NULL)
      return 0;
    return root->height;
  }
  node<T> *rightRotate(node<T> *x) {
    node<T> *y = x->left->right;
    node<T> *temp = x->left;
    x->left = y;
    temp->right = x;
    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
    temp->height = std::max(getHeight(temp->left), getHeight(temp->right)) + 1;
    return temp;
  }
  node<T> *leftRotate(node<T> *x) {
    node<T> *y = x->right->left;
    node<T> *temp = x->right;
    x->right = y;
    temp->left = x;
    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
    temp->height = std::max(getHeight(temp->left), getHeight(temp->right)) + 1;
    return temp;
  }
  node<T> *rotate(node<T> *root) {

    if (getHeight(root->left) - getHeight(root->right) > 1) {
      // left left
      if (getHeight(root->left->left) - getHeight(root->left->right) > 0) {
        return rightRotate(root);
      } else {
        root->left = leftRotate(root->left);
        return rightRotate(root);
      }
      // left right
    }
    if (getHeight(root->left) - getHeight(root->right) < -1) {
      // right right
      if (getHeight(root->right->right) - getHeight(root->right->left) > 0) {
        return leftRotate(root);
      } else {
        root->right = rightRotate(root->right);
        return leftRotate(root);
      }
      // right left
    }
    return root;
  }

  node<T> *insert(node<T> *root, T val) {
    if (root == NULL) {
      root = new node<T>(val);
      return root;
    }
    if (root->val > val)
      root->left = insert(root->left, val);
    if (root->val < val)
      root->right = insert(root->right, val);
    root->height = std::max(getHeight(root->left), getHeight(root->right)) + 1;
    return rotate(root);
  }

  node<T> *remove(node<T> *root, T val) {

    if (root == NULL)
      return NULL;
    if (root->val == val) {

      if (root->left == NULL && root->right == NULL)
        return NULL;
      if (root->left == NULL)
        return root->right;
      if (root->right == NULL)
        return root->left;
      node<T> *temp = root->right;
      while (temp->left != NULL)
        temp = temp->left;
      root->val = temp->val;
      root->right = remove(root->right, temp->val);
    } else {
      if (root->val > val)
        root->left = remove(root->left, val);
      if (root->val < val)
        root->right = remove(root->right, val);
    }
    root->height = std::max(getHeight(root->left), getHeight(root->right)) + 1;
    return rotate(root);
  }
  bool check(node<T> *root, T val) {

    if (root == NULL)
      return false;
    if (root->val == val)
      return true;
    if (root->val > val)
      return check(root->left, val);
    else
      return check(root->right, val);
  }

public:
  avl() { root = NULL; }
  void insert(int val) { root = insert(root, val); }

  void remove(int val) { root = remove(root, val); }

  bool check(int val) { return check(root, val); }
};