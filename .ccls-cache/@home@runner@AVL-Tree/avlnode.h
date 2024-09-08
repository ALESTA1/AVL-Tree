#include <iostream>

template <typename T>
class node {

public:
  T val;
  node *left;
  node *right;
  int height;
  node(T val) {

    this->val = val;
    left = NULL;
    right = NULL;
    height = 0;
  }
};