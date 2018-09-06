#include <stdlib.h>
#include <stdio.h>


#define MAXLEN 100

void quicksort(int *a[], start, end);
bool ispivot(int num, pivot);
void swap(int *num1, int *num2);

//global variable
int a[MAXLEN];

/*--------------------------------------------------------------------*/
void quicksort(int *a[], start, end) {
  int i,j,t,pivot;

  i = start; //for the whole array start is 0
  j = end;   // and the end is a.lenth()
  pivot = a[start]; //choose the leftmost one as pivot
  for (i; i < j; i++) {
    if (a[i] <= a[j]) {
      if (ispivot(a[i], pivot)) {
        j --;
      }else i++;
    }else{
      swap(&a[i], &a[j]);
      if (ispivot(a[i], pivot)) {
        j--;
      }else i++;
    }
  }
  if (start < i-1) {
    quicksort(start, i-1);
  }
  if (end > i+1) {
    quicksort(i+1, end);
  }
}
/*--------------------------------------------------------------------*/
bool ispivot(int num, pivot) {
  if (num == pivot) {
    return true;
  }
  return false;
}

void swap(int *num1, int *num2) {
  int tmp = *num1;
  *num1 = *num2;
  *num2 = tmp;
}
