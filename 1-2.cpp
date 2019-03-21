//1.2.Положительные элементы массива А(N) переставить в конец массива, сохраняя порядок следования. 
//Отрицательные элементы расположить в порядке убывания. Дополнительный массив не использовать.
#include<iostream>
#include<time.h>
using namespace std;
int* giveMemory(int N) {
	pA = new(nothrow) int[N];
	if (!pA) {
		cout << "error";
		return 0;
	}
	return pA;
}
void freeMemory(int *pA) {
	delete[] pA;
	pA = nullptr;
}
void initArr(int *arr, int n) {
	for (int i = 0; i < n; ++i) {
		*(arr + i) = i;
	}

}

void printArray(int *arr, int n) {
	for (int i = 0; i < n; ++i) {
		cout << *(arr + i) << " ";
	}

}void initArrayRandom(int *arr, int n) {
	srand(time(0));
	for (int i = 0; i <n; ++i)
	{
		*(arr + i) = rand() % (100 - (-100) + 1) + (-100);
	}
}
int main() {
  int * pA = nullptr;
	int N{0},cnt{0};
	cout << "Enter array dimension\n";
	cin >> N;
	giveMemory(N);
	initArrayRandom(pA, N);cout << endl;
	printArray(pA, N);cout << endl;
	for (int i = N-1; i >= 0; --i) {//положительные элементы идут в конец
		if (*(pA + i) > 0) {
			swap(*(pA + i),*(pA + N - 1 - cnt));
			cnt++;
		}
	}
	for (int j = 0; j < N ; ++j)	//сортировка отрицательных элементов
	for (int i = 0; i < N ; ++i) {
			if (*(pA + i) < *(pA + i + 1)) 
				if (*(pA + i + 1) <= 0)
				swap(*(pA + i), *(pA + i+ 1));	
}	
	cout<<endl;
	printArr(pA, N);cout << endl;
	freeMemory(pA);
	system("pause");
	return 0;
}
