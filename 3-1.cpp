//Заменить все слова в строке заданной подстрокой, если длина слова совпадает с длиной подстроки и слово содержит хотя бы одну цифру.

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;
const int MAX = 1000;

int main()
{
  setlocale(LC_ALL, "Russian");
  char buf[MAX];
  char *str;
  char *inpstr;
  cin.getline(buf, MAX);
    str = new (nothrow) char[strlen(buf) + 1]; if (!str) { cout << "No memory"; exit(1); }
    strcpy(str, buf);

  cin.getline(buf, MAX);
  inpstr = new (nothrow) char[strlen(buf) + 1]; if (!str) { cout << "No memory"; exit(1); }
  strcpy(inpstr, buf);

  int a = strlen(inpstr);
  int k{ 0 };
  int y;
  for (int i{ 0 }; i <= strlen(str); ++i) {
    if (str[i] == 32||!str[i]) { //ищем пробелы или конец строки
      int c = (i - k); //в данный момент i - позиция конца слова
      if (c == a) { //проверка на совпадение длины текущего слова начальной строки с длиной введенной подстроки
        y = 0;
        for (int w = k; w < i; ++w) {
          if (str[w] > 47 && str[w] < 58) ++y; //y - счетчик количества цифр в слове
        }
        if (y) { //Здесь слово проверется на наличие цифр
          int d{ 0 };
          for (int j = k; j < i; ++j) {


            str[j] = inpstr[d];

            ++d;
          }
        }
      }
      k = i+1; //k становится началом следующего слова
    }
  }
  cout << str;
 
  return 0;
}
