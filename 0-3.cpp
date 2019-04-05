//Массив чисел размера N проинициализировать случайными числами из промежутка от -N до N.
//Написать функцию циклического сдвига элементов массива вправо на k элементов.
#include <iostream>
#include<ctime>
using namespace std;

void init_array_random(int *arr, int n, int max, int min) { // рандомная иницилизация
  srand(time(0));
  max++;
  int tmp = max - min;
  for (int i = 0; i < n; i++)
  {
    *(arr++) = rand() % tmp + min;
  }
}
void reverse(int *arr, int beg, int end) { //переворот массива для самой простой реализации сдвига

  while (beg < end) {
    swap(*(arr + beg), *(arr + end));
    ++beg;
    --end;
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
void shift(int *arr, int k, int n) { //собственно сдвиг 
  reverse(arr, n - k, n - 1);
  reverse(arr, 0, n - 1 - k);
  reverse(arr, 0, n - 1);
}
int main()
{
  setlocale(LC_ALL, "Russian");
  int n;
  cin >> n;
  int*arr;
  give_memory(arr,n);
  init_array_random(arr, n, n, -n);
  print_array(arr, n);
  int k;
  cout << '\n' << "Введите, на сколько вправо сдвигать: ";
  cin >> k;
  shift(arr, k, n);
  print_array(arr, n);
  free_memory(arr);

  system("pause");
}
