#include "dsexceptions.h"
#include "BinarySearchTree2.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

int main() {
  int depth = 0;
  BinarySearchTree<int> t1;

  //creates a degenerate binary search tree
  for(int i = 1; i < 16; i++) {
    t1.insert( i );
  }
  depth = 7;
  cout << "Testing degenerate tree" << '\n' << "Depth > " << depth << " = " << t1.countDepth(depth) << '\n';

  BinarySearchTree<int> t2;

  //creates a balanced binary tree
  t2.insert(8);
  t2.insert(4);
  t2.insert(12);
  t2.insert(2);
  t2.insert(6);
  t2.insert(10);
  t2.insert(14);
  t2.insert(1);
  t2.insert(3);
  t2.insert(5);
  t2.insert(7);
  t2.insert(9);
  t2.insert(11);
  t2.insert(13);
  t2.insert(15);

  depth = 0;
  cout << "Testing balanced tree" << '\n' << "Depth > " << depth << " = " << t2.countDepth(depth) << '\n';

  BinarySearchTree<int> t3;

  depth = 1;
  cout << "Testing empty tree" << '\n' << "Depth > " << depth << " = " << t3.countDepth(depth) << '\n';

  return 0;
}
