//класс - дата. функция - вывод дня недели в объекте.

#include <iostream>
using namespace std;

class Date {
public:
  Date() {  };
  Date(int day, int month, int year) { cout << "3 par constructor\n";
  r = true;
  if (month > 12) { r = false; goto create; }
  if (month == 2 && day > 29) { r = false; goto create; }
  if (month == 2 && day == 29) { if (year % 4 != 0) { r = false; goto create; } }
  if ((month == 4 || month == 6 || month == 9 || month == 11) && (day > 30)) { r = false; goto create; }
create:
  if (r==true) { d = day; m = month; y = year; }
  else cout << "is not this date\n";
  };
  //Date(const Date &t) { cout << "copy constructor" << t.d << '\n'; } //конструктор копирования для передачи в функцию переменных Date
  ~Date() {  };
  void setD(int day) { d = day; }
  void setM(int month) { m=month; }
  void setY(int year) { y=year; }
  int getD() const { return d; }
  int getM() const { return m; }
  int getY() const { return y; }
  void operator=(Date const &t) { d = t.d; m = t.m; y = t.y; r = t.r; }
  Date operator+(int t) { //пока что реализован переход только на следующий месяц, далее - в разработке
    Date f;
    int k;
    if (y % 4 == 0) k = 29; else k = 28;
    int c[] = {31,k,31,30,31,30,31,31,30,31,30,31};
    if (d + t > c[m - 1]) {
      if (m + 1 > 12) {
        f.m = 1;
        f.y = y + 1;;
        goto dal;
      }
      f.m = m + 1;
      f.y = y;
    dal:
      f.d = d+t-c[m-1];
     }
    return f;
  }
  int operator-(Date t) {
    int c[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    int dif{ 0 };
    Date max{ *this }, min{ t };
    if (min > max) { swap(min, max); }
    for (int i = min.y; i < max.y; ++i) {
      if ((min.y+1) % 4 == 0) { dif += 366; }
      else { dif += 365; }
      min.y += 1;
    }
    if (max.y % 4 == 0)c[1] = 29;
    if (max.m < min.m) {
      swap(min, max);
      for (int i = min.m; i < max.m; ++i) {
        dif -= c[i - 1]; min.m += 1;
      }
    }
    else {
      for (int i = min.m; i < max.m; ++i) {
        dif += c[i - 1]; min.m += 1;
      }
    }
    if (max.d > min.d) {
      dif += (max.d - min.d);
    }
    else {
      dif -= (max.d - min.d);
    }
    return dif;
  }
  bool operator<(Date t) {
    if((y<t.y)||((y==t.y)&&(m<t.m))||((y==t.y)&&(m==t.m)&&(d<t.d))) return true;
    else return false;
  }
  bool operator>(Date t) {
    if ((y > t.y) || ((y == t.y) && (m > t.m)) || ((y == t.y) && (m == t.m) && (d > t.d))) return true;
    else return false;
  }
  bool operator==(Date t) {
    if (y == t.y&&m == t.m&&d == t.m) return true;
    else return false;
  }
  void print() const { //для удобства, можно использовать для вывода как "cout<<", так и (Date).print()
    if (!r) { cout << "not corrected input\n"; return; }
    if (m > 9&&d>9) {
      cout << d << "." << m << "." << y << '\n';
    }
    if (m > 9 && d < 10) {
      cout <<"0"<< d << "." << m << "." << y << '\n';
    }
    if (m < 10 && d>9) {
      cout << d << "." <<"0"<< m << "." << y << '\n';
    }
    if (m < 10 && d < 10) {
      cout << "0" << d <<"."<< "0" << m << "." << y<<'\n';
    }
  }
  int dayOfWeek() const  { //реализация в отдельной функции высчитывания необходимого числа не имеет смысловой нагрузки, кроме той, что дни пронумерованы с 1 до 7 начиная с воскресенья
    if (!r)return -32000;
    int y1 = y / 100;
    int y2 = y % 100;
    int N;
    if (m > 2) {
      N=0;
    }
    else {
      if (y2 == 0) {
        if (y1 % 4 == 0) {
          N = 1;
        }
        else {
          N = 2;
        }
      }
      else {
        if (y2 % 4 == 0) {
          N = 1;
        }
        else {
          N = 2;
        }
      }
    }
    double c = (365.25*y2) + (30.56*m) + N + d + 2;
    int S = 1 + (int)c % 7;
    return S;
  }
  void printDayOfWeek() const  {
    int s = dayOfWeek();
    switch (s) {
    case 1: cout << "Sunday\n"; break;
    case 2: cout << "Monday\n"; break;
    case 3: cout << "Tuesday\n"; break;
    case 4: cout << "Wednesday\n"; break;
    case 5: cout << "Thursday\n"; break;
    case 6: cout << "Friday\n"; break;
    case 7: cout << "Saturday\n"; break;
    default: cout << "error\n"; break;
    }
  }
  int howManyDaysInThisMonth(Date &d) { 
    switch (d.m)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: return 31; break;
        case 2: if (y % 4 == 0)return 29; else return 28; break;
        default: return 30;
          break;
        }
  }
  void swap(Date d1, Date d2) { //почленная замена методом трех стаканов
    int tmp;
    tmp = d1.y;
    d1.y = d2.y;
    d2.y = tmp;
    tmp = d1.m;
    d1.m = d2.m;
    d2.m = tmp;
    tmp = d1.d;
    d1.d = d2.d;
    d2.d = tmp;
  }
  friend std::ostream& operator<< (std::ostream &out, const Date &d);
  friend std::istream& operator>> (std::istream &in, Date &d);
private:
  int d;
  int m;
  int y;
  bool r;
};
std::ostream& operator<< (std::ostream &out, const Date &d)
{
  // поскольку operator<< является другом класса Date, то мы имеем прямой доступ к членам d
  d.print();
  return out;
}
std::istream& operator>> (std::istream &in, Date &da)
{
begIn:
  da.r = true;
  in >> da.d;
  in >> da.m;
  in >> da.y;
  if (da.m > 12) { da.r = false; }
  if (da.m == 2 && da.d > 29) { da.r = false; }
  if (da.m == 2 && da.d == 29) { if (da.y % 4 != 0) { da.r = false;  } }
  if ((da.m == 4 || da.m == 6 || da.m || da.m == 11) && (da.d > 30)) { da.r = false; }
  if (da.r == false) { cout << "not corrected input, please, enter date again\n"; goto begIn; }
  return in;
}
int main() {
  Date me(20, 12, 2000), mo(23,11,2001), my;
  my = mo+30;
  cout << my << me;
  Date *no = new Date(15, 05, 1997);
  Date*fff = &my;
  cout << *fff;
  fff->printDayOfWeek();
  system("pause");
}
