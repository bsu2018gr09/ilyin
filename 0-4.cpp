//Расположить в порядке возрастания элементы массива А(N), начиная с k-го элемента.
#include <iostream>
#include<time.h>
using namespace std;

void init_array_random(int *arr, int n) { // рандомная иницилизация
  srand(time(0));
  int G = 100;
  for (int i = 0; i < n; i++)
  {
    *(arr + i) = rand() % G;
  }
}
void print_array(int*  arr, int n) {
  for (int i = 0; i < n; ++i) {
    cout << *(arr + i) << "   ";
  }
}
void give_memory(int*&arr, int N) {
  arr = new int[N]; if (!arr) { cout << "No memory"; exit(1); }
}
void free_memory(int* a) {
  delete[] a;
  a = nullptr;
}


void sort(int*arr,int n,int beg) {
  bool flag;
  do { //сортировка нужных строк, метод - пузырьком
    flag = false;
    for (int i = n - 1; i > beg; i--) { //начинаю идти по массиву с конца
      if (arr[i] < arr[i - 1]) {
        swap(arr[i - 1], arr[i]); //меняю строки местами
        flag = true;
      }
    }
  } while (flag);
}
int main()
{
  setlocale(LC_ALL, "Russian");
  int n;
  cin >> n;
  int*arr;
  give_memory(arr,n);
  init_array_random(arr, n);
  print_array(arr, n);
  int beg;
  cin >> beg;
  sort(arr, n, beg);
  print_array(arr, n);
  free_memory(arr);

  system("pause");
}
