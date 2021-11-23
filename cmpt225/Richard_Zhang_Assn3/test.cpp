#include <iostream> // I/O library.
#include <algorithm> // Includes sort()
#include <ctime> // access to the system clock
#include <time.h> // access to "wall clock"
#include "Qsort.h" // our quicksort (and insertion sort)
using namespace std;

long double elapsed_time( clock_t start, clock_t finish){
   // returns elapsed time in milliseconds
   return (finish - start)/(double)(CLOCKS_PER_SEC/1000);
}

void printArray( char s[], int A[], int lo, int hi ){
  // call like this: printArray( "A1", A1, 0, SIZE-1 );
  // useful for debugging
  cout << s << " [ " ;
  for( int i = lo ; i < hi ; i++ ){
    cout << A[i] << ", " ;
  }
  cout << A[hi] << " ]" ;
  cout << endl;
}

int main (int argc, char * const argv[]) {
  int SIZE = 50000; // size of array to sort.
  long double TIMES = 10 ; // number of times to run - mean is reported.

  srand( time(NULL) ); // seed the random number generator.

  clock_t start, finish ;// used to time function calls.

  long double sort_time = 0;
  long double insertion_sort_time = 0;
  long double quicksorthi_time = 0;
  long double quicksortmid_time = 0;
  long double introsort_time = 0;

  int *A1 = new int[SIZE];
  int *A2 = new int[SIZE];
  int *A3 = new int[SIZE];
  int *A4 = new int[SIZE];
  int *A5 = new int[SIZE];

  //tracker variable for input type
  int a;

  for( int t = 0 ; t < TIMES ; t++ ){

    for(int i = 0 ; i < SIZE ; i++ ) {
      //int x = SIZE - i; a = 0; // reverse-ordered
      int x = i; a = 1; // ordered
      //int x = rand() % SIZE*10; a = 2; // random input
      A1[i] = x;
      A2[i] = x;
      A3[i] = x;
      A4[i] = x;
      A5[i] = x;
    }

    start = clock();
    sort(A1,A1+SIZE);
    finish = clock();
    sort_time += elapsed_time(start,finish);

    start = clock();
    InsertionSort(A2,0,SIZE-1);
    finish = clock();
    insertion_sort_time += elapsed_time(start,finish);

    start = clock();
    QuickSortHi(A3,0,SIZE-1);
    finish = clock();
    quicksorthi_time += elapsed_time(start,finish);

    start = clock();
    QuickSortMid(A4,0,SIZE-1);
    finish = clock();
    quicksortmid_time += elapsed_time(start,finish);

    start = clock();
    IntroSort(A5,0,SIZE-1);
    finish = clock();
    introsort_time += elapsed_time(start,finish);


  }

  if (a == 0) {
    cout << "Sorting on a reverse ordered input with size " << SIZE << endl;
  }
  if (a == 1) {
    cout << "Sorting on a ordered input with size " << SIZE << endl;
  }
  if (a == 2) {
    cout << "Sorting on a random input with size " << SIZE << endl;
  }
  cout << "C++ sort: " << sort_time / TIMES << endl;
  cout << "Insertion Sort: " << insertion_sort_time / TIMES << endl;
  cout << "Quicksort with A[hi] as pivot: " << quicksorthi_time / TIMES << endl;
  cout << "Quicksort with A[mid] as pivot: " << quicksortmid_time / TIMES << endl;
  cout << "Introsort with A[mid] as pivot: " << introsort_time / TIMES << endl;

  return 0;
}
