#include "pch.h"
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int N;
	cout << "������� ���������� �����: ";
	cin >> N;
	int *arrx = new int[N];
	int *arry = new int[N];
	srand(time(NULL));
	for (int i{ 0 }; i < N; ++i) {//���������� �������
		*(arrx + i) = rand() % 11;
	}
	for (int i{ 0 }; i < N; ++i) {//���������� �������
		*(arry + i) = rand() % 11;
	}

	for (int i{ 0 }; i < N; ++i) {//������ �����
		cout << *(arrx + i) << " ";
	}
	cout << '\n';
	for (int i{ 0 }; i < N; ++i) {//������ �����
		cout << *(arry + i) << " ";
	}
	int a, b, c;
	cout << '\n' << "������� a, b, c ��� ��������� ������ ax+by+c=0:";
	cin >> a >> b >> c;
	cout << '\n';
	int *d = new int[N];
	for (int i{ 0 }; i < N; ++i) {
		*(d + i) = (abs(a*arrx[i] + b * arry[i] + c) / sqrt(a*a + b * b));
	}
	int i{ 0 }, buf, swap_cnt{ 0 };
	while (i < N)
	{
		if (i + 1 != N && d[i] > d[i + 1])
		{
			buf = d[i];
			d[i] = d[i + 1];
			d[i + 1] = buf;
			swap_cnt = 1;
			swap(arrx[i], arrx[i + 1]);
			swap(arry[i], arry[i + 1]);
		}
		i++;
		if (i == N && swap_cnt == 1)
		{
			swap_cnt = 0;
			i = 0;
		}
	}
	cout << '\n';
	for (int i{ 0 }; i < N; ++i) {//������ �����
		cout << *(arrx + i) << " ";
	}
	cout << '\n';
	for (int i{ 0 }; i < N; ++i) {//������ �����
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