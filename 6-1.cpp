//класс - дата. функция - вывод дня недели в объекте.

#include <iostream>
using namespace std;

class Date {
public:// не вижу great 4!!!!! только 3 - теперь 4
  Date() {  };
  Date(int day, int month, int year) { cout << "3 par constructor\n";
  bool r{ true };                                    
  if (month > 12) { r = false; }
  if (month == 2 && day > 29) { r = false; }
  if (month == 2 && day == 29 && (year % 4 != 0||y%100==0)&&y%400!=0)  { r = false; }
  if ((month == 4 || month == 6 || month == 9 || month == 11) && (day > 30)) { r = false; }
  if (r==true) { d = day; m = month; y = year; }
  else {
    cerr << "it's not corrected date. All data swap to 0\n"; d = 0; m = 0; y = 0;
  }
  };
  Date(const Date &t) {
    //cout << "copy constructor for " << t.d << '\n';
    this->d = t.d;
    this->m = t.m;
    this->y = t.y;
  };
  ~Date() {  };
  void setD(int day) {
    bool r = isOrNot(day, m, y);
    if (r) {
      d = day; return;
    }
    else { cout << "date is not edit\n"; return; }
  }
  void setM(int month) { bool r = isOrNot(d, month, y);
  if (r) { m = month; return; }
  else { cout << "date is not edit\n"; return; }
  }
  void setY(int year) { bool r = isOrNot(d, m, year);
  if (r) { y = year; return; }
  else{ cout << "date is not edit\n"; return; }
  }
  int getD() const { return d; }
  int getM() const { return m; }
  int getY() const { return y; }
  void operator=(Date const &t) { d = t.d; m = t.m; y = t.y; }
  Date operator+(int t) { //разработан усовершенствованный алгоритм для функции добавления некоторого заданного пользователем количества дней к текущей дате (левому операнду)
    Date f = *this;// не волнуешься как это работает? Кто делал это присваивание? Разве ты???? - не понял вопроса
    int i{ 0 };
    while (i < t)
    {
      if (i + f.howManyDaysInThisMonth() < t)
      {
        i += f.howManyDaysInThisMonth();
        f.m++;
        if (f.m > 12)
        {
          f.m = 1; f.y++;
        }
      }
      else
      {
        i++; f.d++;
        if (f.d > f.howManyDaysInThisMonth())
        {
          f.m++;
          if (f.m > 12)
          {
            f.m = 1; f.y++;
          }
          f.d = 1;
        }
      }
    }
    return f;
  }
  int operator-(Date t) { 
    Date f,g; int i{ 0 };
    if (*this < t) {
      f = *this; g = t;
    }
    else {
      f = t; g = *this;
    }
    if (*this == t)return 0;
    while (f < g) {
      i++;
      f = f + 1;
    }
    return i;
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
    if (!isOrNot()) { cout << "not corrected input\n"; return; }
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
    if (!isOrNot())return -32000;
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
  bool isOrNot(int da,int mo,int ye)  {
  bool r{ true };
  if (da > 31) { r = false; }
  if (mo > 12) { r = false; }
  if (mo == 2 && da > 29) { r = false; }
  if (mo == 2 && da == 29 && (ye % 4 != 0 || ye % 100 == 0) && ye % 400 != 0) { r = false; }
  if ((mo == 4 || mo == 6 || mo == 9 || mo == 11) && (da > 30)) { r = false; }
  return r;
}
  friend std::ostream& operator<< (std::ostream &out, const Date &d);
  friend std::istream& operator>> (std::istream &in, Date &d);
private:
  int d;
  int m;
  int y; 
  int howManyDaysInThisMonth() { 
    switch (m)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: return 31; break;
        case 2: if ((y % 4 == 0&&y%100!=0)||y%400==0)return 29; else return 28; break;
        default: return 30;
          break;
        }
  }
  bool isOrNot() const {
    bool r{ true };
    if (d > 31) { r = false; }
    if (m > 12) { r = false; }
    if (m == 2 && d > 29) { r = false; }
    if (m == 2 && d == 29 && (y % 4 != 0 || y % 100 == 0) && y % 400 != 0) { r = false; }
    if ((m == 4 || m == 6 || m==9 || m == 11) && (d > 30)) { r = false; }
    return r;
  }
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
  bool r{ true };//вынес код проверки на существование в отдельную функцию
  in >> da.d;
  in >> da.m;
  in >> da.y;
  if (!da.isOrNot()) { cout << "not corrected input, please, enter date again\n"; goto begIn; }
  return in;
}
int main() {
  Date me(20, 12, 2000), mo(23,11,2001), my;
  my = mo+3000;
  cout<<my-mo<<'\n';
  cout << my << me<<'\n';
  Date *no = new Date(15, 05, 1997);
  Date*fff = &my;
  cout << *fff;
  fff->printDayOfWeek();
  system("pause");
}
