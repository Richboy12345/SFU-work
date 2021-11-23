#include "dsexceptions.h"
#include "List.h"
#include "Vector.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

double elapsed_time(clock_t start, clock_t finish) {
   // returns elapsed time in milliseconds
   return (finish - start)/(double)(CLOCKS_PER_SEC/1000);
}

int main() {

  //max = 2147483647;
  clock_t start, end;
  const int N = 100000;
  double runtime;

  cout << "[Richard Zhang]" << endl;
  cout << "[301402349]" << endl;
  cout << "[rza69]" << endl;
  cout << "Program: [part1]" << endl;
  cout << "Type of Elements: [int]" << endl;
  cout << "Number of Elements: [" << N << "]" <<endl;
  cout << "Time units: [milliseconds]" << endl;

  Vector<int> vec1;
  start = clock();
  for (int i = 0; i < N; i++) {
    vec1.push_back(i);
  }
  end = clock();
  runtime = elapsed_time(start, end);
  cout << "Time for Vector Insertion: [" << runtime << "]" << endl;

  List<int> list1;
  for (int i = 0; i < N; i++) {
    list1.push_back(i);
  }
  end = clock();
  runtime = elapsed_time(start, end);
  cout << "Time for List Insertion: [" << runtime << "]" << endl;

  start = clock();
  vec1.visitAll();
  end = clock();
  runtime = elapsed_time(start, end);
  cout << "Time for Vector Visiting: [" << runtime << "]" << endl;

  start = clock();
  list1.visitAll();
  end = clock();
  runtime = elapsed_time(start, end);
  cout << "Time for List Visiting: [" << runtime << "]" << endl;
}
