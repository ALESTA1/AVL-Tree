#include <iostream>
#include "avl.h"

int main() {

  avl<int> tree;
  tree.insert(10);
  tree.insert(20);
  tree.insert(30);
  tree.remove(20);
  std::cout << (tree.check(30) ? "Found 20\n" : "20 not found\n");

}