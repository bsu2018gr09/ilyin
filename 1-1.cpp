#include "pch.h"
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int N;
	cout << "Введите количество точек: ";
	cin >> N;
	int *arrx = new int[N];if(!arrx) { cout << "No memory"; exit(1); }
	int *arry = new int[N];if(!arry) { cout << "No memory"; exit(1); }
	srand(time(NULL));
	for (int i{ 0 }; i < N; ++i) {//присвоение абсцисс
		*(arrx + i) = rand() % 11;
	}
	for (int i{ 0 }; i < N; ++i) {//присвоение ординат
		*(arry + i) = rand() % 11;
	}

	for (int i{ 0 }; i < N; ++i) {//просто вывод
		cout << *(arrx + i) << " ";
	}
	cout << '\n';
	for (int i{ 0 }; i < N; ++i) {//просто вывод
		cout << *(arry + i) << " ";
	}
	int a, b, c;
	cout << '\n' << "Введите a,b,c, задающие уравнение прямой ax+by+c=0:";
	cin >> a >> b >> c;
	cout << '\n';
	int *d = new int[N];if(!d) { cout << "No memory"; exit(1); }
	for (int i{ 0 }; i < N; ++i) {
		*(d + i) = (abs(a*arrx[i] + b * arry[i] + c) / sqrt(a*a + b * b)); //вычисление расстояния от точек до прямой
	}
	int i{ 0 }, buf, swap_cnt{ 0 };
	while (i < N)
	{
		if (i + 1 != N && d[i] > d[i + 1])
		{
			buf = d[i];	//замена элементов в массиве, хранящем расстояния до прямой
			d[i] = d[i + 1];
			d[i + 1] = buf;
			swap_cnt = 1;
			swap(arrx[i], arrx[i + 1]); //замена координат по х
			swap(arry[i], arry[i + 1]); //замена координат по у
		}
		i++;
		if (i == N && swap_cnt == 1) //проверка, были ли замены
		{
			swap_cnt = 0;
			i = 0;
		}
	}
	cout << '\n';
	for (int i{ 0 }; i < N; ++i) {//вывод
		cout << *(arrx + i) << " ";
	}
	cout << '\n';
	for (int i{ 0 }; i < N; ++i) {//вывод
		cout << *(arry + i) << " ";
	}

	delete[]arrx;
	arrx = nullptr;
	delete[]arry;
	arry = nullptr;
	delete[]d;
	d = nullptr;
	system("pause");
}
