#include <iostream>
#include <ctime>
using namespace std;
void sort(int* A, int N) {
  int temp = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      if (*(A + i) > *(A + j)) {
        temp = *(A + i);
        *(A + i) = *(A + j);
        *(A + j) = temp;
      }
    }
  }
}

int countCopies(int* A, int N) {
  sort(A, N);
  int j = 0, c = 0;
  for (int i = 0; i < N; ++i) {
    while (*(A+i) == *(A+i+1)) {
      ++j;
      ++i;
    }
    if (j > 0) {
      ++c;
      j = 0;
    }
  }
  return c;
}
int main() {
  srand(time(NULL));
  int N;
  cin >> N;
  int *Arr = new int[N];
  for (int i{ 0 }; i < N; ++i) {
    *(Arr + i) = rand() % 11 + 1;
  }
  for (int i{ 0 }; i < N; ++i) {
    cout<<*(Arr + i)<<" ";
  }
  cout<<'\n'<<countCopies(Arr, N);
  system("pause");
}
