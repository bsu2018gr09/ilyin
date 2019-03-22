//1.2.Положительные элементы массива А(N) переставить в конец массива, сохраняя порядок следования. 
//Отрицательные элементы расположить в порядке убывания. Дополнительный массив не использовать.
#include<iostream>
#include<time.h>
using namespace std;
int* giveMemory(int N) {
	int * pA = nullptr;
	pA = new(nothrow) int[N];
	if (!pA) {
		cout << "error";
		exit(1);
	}
	cout<<'\n';
	return pA;
}
void freeMemory(int *pA) {
	delete[] pA;
	pA = nullptr;
}
void printArray(int *arr, int n) {
	for (int i = 0; i < n; ++i) {
		cout << *(arr + i) << " ";
	}
	cout<<'\n';
}
void initArrayRandom(int *arr, int n) {
	srand(time(0));
	for (int i = 0; i <n; ++i)
	{
		*(arr + i) = rand() % (10 - (-10) + 1) + (-10);
	}
	cout<<'\n';
}
void positivNumbersToEnd(int *pA, int N) {
	int cnt  = 0;
	for (int i = N - 1; i >= 0; --i) {            //переставляет положительные элементы в конец не меняя порядок
		if (*(pA + i) > 0) {
			swap(*(pA + i), *(pA + N - 1 - cnt));
			cnt++;
		}
	}
}
void sortNegativNumbers(int *pA, int N) {
	for (int j = 0; j < N; ++j)				//расставляет отрицательные элементы в порядке убывания
		for (int i = 0; i < N; ++i) {
			if (*(pA + i) < *(pA + i + 1))
				if (*(pA + i + 1) <= 0)
					swap(*(pA + i), *(pA + i + 1));
		}
	cout<<'\n';
}
int main() {
	setlocale(LC_ALL, "Russian");
	int N{ 0 };
	cout << "Введите размер массива\n";
	cin >> N;
	int * pA = nullptr;
	pA = giveMemory(N);
	initArrayRandom(pA, N);
	printArray(pA, N);
	positivNumbersToEnd(pA,N);
	sortNegativNumbers(pA, N);
	printArray(pA, N);
	freeMemory(pA);
	system("pause");
	return 0;
}
