//Заменить все слова в строках заданной подстрокой, если длина слова совпадает с длиной подстроки и слово содержит хотя бы одну цифру.Отсортировать строки по количеству замен.

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
using namespace std;
const int MAX = 1000;
int zad(char*str, char*inpstr) { //Заменяет в str слова, размером как inpstr и с цифрами на inpstr
  int a = strlen(inpstr);
  int k{ 0 };
  int countSwap{ 0 };
  int y;
  for (int i{ 0 }; i <= strlen(str); ++i) {
    if (str[i] == 32 || !str[i] || str[i]==46) {
      int c = (i - k);//в данный момент i = позиции конца слова
      if (c == a) {
        y = 0;
        for (int w = k; w < i; ++w) {
          if (str[w] > 47 && str[w] < 58) ++y;//Здесь слово проверяется на наличие цифр
        }
        if (y) { 
          int d{ 0 };
          countSwap++;
          for (int j = k; j < i; ++j) {

            str[j] = inpstr[d];

            ++d;
          }
        }
      }
      k = i + 1;
    }
  }
  return countSwap;
}
void input(char*&s) {
  char buf[MAX];
  cin.getline(buf, MAX);
  s = new (nothrow) char[strlen(buf) + 1]; if (!s) { cout << "No memory"; exit(1); }
  strcpy(s, buf);
}
int main() {
  int N = 1000, M = 500;

  char **buff = new char*[M];
  for (int i = 0; i < N; ++i) {
    buff[i] = new char[M];
  }

  ifstream source("C:\\date1.txt"); 
  ofstream result("C:\\result.txt");
  if (!source) { cout << "No file d:\\date1.txt. Can't open\n"; exit(1); }
  if (!result) { cout << "No file d:\\result.txt. Can't create\n"; exit(1); }
  
  int i{ 0 };
  while (1) {
    source.getline(buff[i], N - 1);
    ++i;
    if (source.eof()) break;
  }
  
  int count = i;
  int *c = new int[count];
  
  i = 0;
  char*inpstr = nullptr;
  input(inpstr);
  for (int j{ 0 }; j < count; ++j) {
    c[j]=zad(buff[j],inpstr); //загонка в новый массив c[] количества замен
  }

  bool flag;
  do { //сортировка нужных строк пузырьком
    flag = false;
    for (int i = count - 1; i > 0; i--) { //начинает идти по массиву с конца
      if (c[i] < c[i - 1]) {
        swap(buff[i - 1], buff[i]); //строки меняются местами
        swap(c[i - 1], c[i]); // меняются показатели в массиве c[], который хранит количество замен в каждой строке
        flag = true;
      }
    }
  } while (flag);
  
  for (int i{ 0 }; i < count; ++i) {
    result << buff[i];
    result << '\n';
  }
  cout << "Done!";

  system("pause");
}
