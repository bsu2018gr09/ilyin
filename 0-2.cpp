//	В массиве размера N, заполненного случ.числами от 0 до 10, определить максимальную длину последовательности равных элементов.
#include <iostream>
#include <clocale>
#include <ctime>
using namespace std;

void initArrayRandom(int* Arr, int n, int min, int max) { //общая функция, в main указаны 0 и 10
  for (int i = 0; i < n; ++i) {
    *(Arr + i) = rand() % ((max - min + 1) + min);
  }
}
void printArray(int* Arr, int n) {
  for (int i = 0; i < n; ++i) {
    cout << *(Arr + i) << " ";
  }
  cout << "\n";
}
int maxLength(int* Arr, int n) {
  int cnt1{ 1 }, maxCnt{ 1 };
  for (int i{ 1 }; i < n; ++i) {//i от 1, так как сравниваем с предыдущими элементами
    if (*(Arr + i) == *(Arr + i - 1)) {
      while (*(Arr + i) == *(Arr + i - 1)) {
        ++cnt1;
        ++i;
      }
    }
    if (cnt1 > maxCnt) {
      maxCnt = cnt1;
    }
    cnt1 = 1;
  }
  return maxCnt;
}

int main() {
  setlocale(LC_ALL, "Russian");
  srand(time(0));
  int n;
  cout << "Введите размер массива: ";
  cin >> n;
  int* Arr = new (nothrow) int[n];
  if (!Arr) {
    cout << "error!" << "\n";
    system("pause");
    return 0;
  }
  int maxElem{ 10 }, minElem{ 0 };
  initArrayRandom(Arr, n, minElem,maxElem);
  printArray(Arr, n);
  cout<<maxLength(Arr, n)<<'\n';
  delete[]Arr;
  Arr = nullptr;
  system("pause");
}
