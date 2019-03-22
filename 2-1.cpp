#include "pch.h" 
#include <iostream> 
#include <ctime>
using namespace std;

/*В массиве А(N,M) расположить строки, стоящие после строки с первым
максимальным элементом матрицы, в порядке возрастания количества
чётных элементов в строке.*/

void give_memory(int**&arr, int n, int m) {
	arr = new (nothrow) int*[n]; if(!arr) { cout << "No memory"; exit(1); }
	for (int i = 0; i < n; ++i)
		arr[i] = new int[m];
}
void free_array(int **&arr, int n) {
	for (int i = 0; i < n; ++i) {
		delete[] arr[i];
		arr[i] = nullptr;
	}
	delete[] arr;
	arr = nullptr;
}
void print_array(int **arr, int n, int m) {
	for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
			cout << arr[i][j]<<' ';
		}
		cout << '\n';
	}
}
void init_array_random(int **arr, int n, int m) {
	srand(time(NULL));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			arr[i][j] = rand() % 100 + 1;
		}
	}
}

void homework2(int**arr, int n, int m) {
	int k{ 0 }, max{ 0 };
	int *a2 = new int[n];
	for (int i{ 0 }; i < n; ++i) { //в этом цикле считается и записывается в массив a2 количество четных чисел в соответствующих строках исходного двумерного массива 
		for (int j = 0; j < m; ++j) {
			if (arr[i][j] % 2 == 0) ++k;
			if (arr[i][j] > max)max = arr[i][j]; //заодно ищем максимальный элемент в массиве
		}
		*(a2 + i) = k;
		k = 0;
	}
	cout << '\n';
	for (int i{ 0 }; i < n; ++i) cout << a2[i] << " "; //выводим количество четных элементов в строках
	cout << '\n' << max << '\n';

	int beg{ 0 };
	for (int i = 0; i < n; ++i) { //ищем начало
		for (int j = 0; j < m; ++j) {
			if (arr[i][j] == max) {
				beg = i;
				goto dalee;
			}
		}
	}
dalee:;
	cout << beg << '\n';

	++beg; //уточняю начало замен

	bool flag;
	do { //сортировка нужных строк, метод - пузырьком
		flag = false;
		for (int i = n - 1; i > beg; i--) { //начинаю идти по массиву с конца
			if (*(a2 + i) < *(a2 + i - 1)) {
				swap(*(arr + i - 1), *(arr + i)); //меняю строки местами
				swap(*(a2 + i - 1), *(a2 + i)); // меняю показатели в массиве a2[], который хранит количество четных элементов в строках
				flag = true;
				cout << "swap" << i - 1 << " " << i << '\n';
			}
		}
	} while (flag);

	cout << '\n';
	for (int i{ 0 }; i < n; ++i) cout << a2[i] << " "; //все выводы информации сделаны для удобства разработки и только.
	cout << '\n' << '\n';
}


int main()
{
	int n, m;
	cin >> n >> m;
	int **arr;
	give_memory(arr, n, m);
	init_array_random(arr, n, m);
	print_array(arr, n, m);
	homework2(arr, n, m);
	print_array(arr, n, m);
	free_array(arr, n);
	system("pause");
	}
