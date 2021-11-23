#include "dsexceptions.h"
#include "BinarySearchTree1.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

int main() {

  BinarySearchTree<int> t1;

  //creates a degenerate binary search tree
  for(int i = 0; i < 15; i++) {
    t1.insert( i );
  }

  cout << "Testing degenerate tree" << '\n' << "# of leaves = " << t1.leafCounter() << '\n';

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

  cout << "Testing balanced tree" << '\n' << "# of leaves = " << t2.leafCounter() << '\n';

  BinarySearchTree<int> t3;

  cout << "Testing empty tree" << '\n' << "# of leaves = " << t3.leafCounter() << '\n';

  return 0;
}
