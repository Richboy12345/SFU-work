#include "dsexceptions.h"
#include "AvlTreeB.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

int main() {

  printf("Testing Insert\n");
  AvlTree<int> t1;

  //create a degenerate tree to check balance
  for(int i = 1; i < 255; i++) {
    t1.insert( i );
  }

  printf("Printing Tree 1\n");
  t1.printTree();

  AvlTree<int> t2;

  //creates a balanced tree
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

  printf("Printing Tree 2\n");
  t2.printTree();

  printf("Testing Remove\n");

  //removing from least to greatest
  printf("Tree 1\n");
  for(int i = 1; i < 16; i++) {
    t1.remove( i );
  }


  return 0;
}
