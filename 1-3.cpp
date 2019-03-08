#include "pch.h"
#include <iostream>
#include <ctime>
using namespace std;

bool isPrimeNumber(int number)
{
	if (number <= 1)
	{
		return false;
	}

	bool isPrime = true;
	for (int i = 2; i < sqrt(number); ++i)
	{
		if (!(number % i))
		{
			isPrime = false;
			break;
		}
	}

	return isPrime;
}
void initArrayRandom(int*arr, int N) {
	srand(time(NULL));
	for (int i{ 0 }; i < N; ++i) {
		arr[i] = rand() % 100 + 1;
	}
}
void giveMemory(int*&arr, int N) {
	arr = new int[N];
}
void freeMemory(int*&arr) {
	delete[]arr;
	arr=nullptr;
}
void printArray(int*arr, int N) {
	for (int i{ 0 }; i < N; ++i) {
		cout << arr[i] << " ";
	}
}
void sortPrimeNumbersInArray(int*&arr, int N) {
	int k{ 0 };
	for (int i{ 0 }; i < N; ++i) { //вывод и подсчет количества простых чисел
		cout << *(arr + i) << " ";
		if (isPrimeNumber(*(arr + i))) {
			++k;
		}
	}
	cout << '\n';
	k *= 2;
	int *prime;
	giveMemory(prime, k);
	int j{ 0 };
	for (int i{ 0 }; i < N; ++i) {
		if (isPrimeNumber(*(arr + i))) { //загонка в массив простых чисел на четные позиции и их номеров на нечетные позиции
			*(prime + j++) = *(arr + i);
			*(prime + j) = i;
			++j;
		}
	}

	int i{ 0 }, buf, swap_cnt{ 0 };
	while (i < k)
	{
		if (i + 2 != k && prime[i] > prime[i + 2]) //сортируются только четные элементы массива, хранящего простые числа и их номера на нечетных местах
													//таким образом элементы становятся перед своими будущими номерами в исходном массиве
		{
			buf = prime[i];
			prime[i] = prime[i + 2];
			prime[i + 2] = buf;
			swap_cnt = 1;
		}
		i += 2;
		if (i == k && swap_cnt == 1)
		{
			swap_cnt = 0;
			i = 0;
		}
	}

	for (int i{ 0 }; i + 1 < k; ++i) { //меняем в  исходном массиве элементы в соответствии с предыдущей сортировкой
		arr[prime[i + 1]] = prime[i];
		++i;
	}
	freeMemory(prime);

}
int main()
{
	setlocale(LC_ALL, "Russian");
	int N;
	cin >> N;
	int *arr;
	giveMemory(arr, N);
	initArrayRandom(arr, N);
	sortPrimeNumbersInArray(arr, N);
	printArray(arr, N);
	freeMemory(arr);
}
