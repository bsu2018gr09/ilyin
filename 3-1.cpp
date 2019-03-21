//Заменить все слова в строке заданной подстрокой, если длина слова совпадает с длиной подстроки и слово содержит хотя бы одну цифру.

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;
const int MAX = 1000;

//zad - функция, которая ищет в введенной изначально строке слова, которые содержат цифры и совпадают по длине с введенной после подстрокой
void zad(char*str, char*inpstr) {
  int a = strlen(inpstr);
  int k{ 0 };
  int y;
  for (int i{ 0 }; i <= strlen(str); ++i) {
    if (str[i] == 32 || !str[i]) {
      int c = (i - k);//в данный момент i = позиции конца слова
      if (c == a) {
        y = 0;
        for (int w = k; w < i; ++w) {
          if (str[w] > 47 && str[w] < 58) ++y;
        }
        if (y) { //Здесь необходимо проверить слово на наличие цифр
          int d{ 0 };
          for (int j = k; j < i; ++j) {


            str[j] = inpstr[d];

            ++d;
          }
        }
      }
      k = i + 1;
    }
  }
}
void input(char*&s) {
   char buf[MAX];
   cin.getline(buf, MAX);
      s = new (nothrow) char[strlen(buf) + 1]; if (!s) { cout << "No memory"; exit(1); }
      strcpy(s, buf);
 }
int main()
{
  setlocale(LC_ALL, "Russian");
  
  char *str=nullptr;
  char *inpstr= nullptr;
  input(str);
  input(inpstr);
  zad(str, inpstr);
  cout << str;
  delete[] str;
  delete[] inpstr;
  return 0;
}
