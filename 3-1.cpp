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
  for (int i{ 0 }; i <= strlen(str); ++i) {
    if (str[i] == 32||!str[i]) {
      int c = (i - k);//в данный момент i = позиции конца слова
      if (c == a) {
        int d{ 0 };
        for (int j = k; j < i; ++j) {
            str[j] = inpstr[d];
            ++d;
        }
      }
      k = i+1;
    }
  }
  cout << str;
 
  return 0;
}
