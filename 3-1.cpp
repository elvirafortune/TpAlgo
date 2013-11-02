#include <vector>
#include <iostream>
#include <cstdio>
#include <functional>

using std::swap;
using std::less;

void print(int *a, int n) {
  for (int i = 0; i < n; ++i) {
      printf("%d", a[i]);
  }
  printf("\n");
}


int partition(int *a, int n, int k) {
  swap(a[n-1], a[k]);
  int cnt = 0;
  int i = 0;
  int j = 0;

  for (; j < n - 1; ) {
      if (a[j] == a[n-1]) {
          if (cnt % 2) {
              swap(a[i], a[j]);
              ++i;
              ++j;
          } else {
            ++j;
          }
          ++cnt;
      }

      if (less<int>()(a[j], a[n-1])) {
      swap(a[i], a[j]);
      ++i;
      ++j;
    } else {
      ++j;
    }
  }

  swap(a[i], a[n-1]);

  return i;
}


int mediana(int * b, int left, int right) {
    int centre = right/2;
    int a[3];
    a[0]=b[left];
    a[1]=b[centre];
    a[2]=b[right];

    int i = 0;
    int j = 2;
    bool side = 0;
    while (i != j) {
        if ( a[i] > a[j] ) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            side =!side;
        }
        if (side) {
            ++i;
        } else {
            --j;
        }
    }

    if (a[1] == b[0])
        return 0;

    if (a[1] == b[right/2])
        return right/2;

    if (a[1] == a[right-1])
        return right-1;
}


int nth_element(int *a, int n, int k) {

    int med = mediana(a, 0, n-1);
    int pos = partition(a, n, med);
    if (pos < k) {
        return pos + 1 + nth_element(&a[pos + 1], n - (pos +1), k - (pos +1));
    } else if (pos > k ) {
        return nth_element(a, pos, k);
    } else {
        return pos;
    }
return pos;
}



int main() {

    int n = 0;
    int k = 0;
    int i = 0;
    scanf("%d %d", &n, &k);
    int data[n];
    for (i = 0; i < n; ++i) {
        scanf("%d", &data[i]);
    }
    int pos = nth_element(&data[0], n, k);
    printf("%d", data[pos]);

    return 0;
};
