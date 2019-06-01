#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <string>
using namespace std;

int charToInt(char a) {
  return (a - 48);
}
int charToInt(const char*a) {
  int p = strlen(a);
  int c{ 0 };
  for (int i{ 0 }; i < p; ++i) {
    c += pow(10, i)*charToInt(*(a + p - i - 1));
  }
  return c;
}

class Footballer {
private:
  char* name;
  char* team;
  short age;
  short games;
  short goals;
  short assists;
public:
  Footballer() : name(nullptr), team(nullptr), age(0), games(0), goals(0), assists(0) { };
  Footballer(const char Name[20], const char Team[20], short Age, short Games, short Goals, short Assists) : name(new (nothrow) char[strlen(Name) + 1]), team(new (nothrow) char[strlen(Team) + 1])
  {
    strcpy(name, Name);
    strcpy(team, Team);
    age = Age;
    games = Games;
    goals = Goals;
    assists = Assists;
    cout << "Constructor with params\n";
  }
  Footballer(const Footballer &footballer) : name(new (nothrow) char[strlen(footballer.name) + 1]), team(new (nothrow) char[strlen(footballer.team) + 1]), age(footballer.age), games(footballer.games), goals(footballer.goals), assists(footballer.assists) {
    cout << "copy constructor\n";
    strcpy(name, footballer.name);
    strcpy(team, footballer.team);
  }
  ~Footballer() {
    cout << "work destruktor\n";
    delete[]team;
    team = nullptr;
    delete[]name;
    name = nullptr;
  }

  char* getName() const {
    return name;
  }
  short getAge() const {
    return age;
  }
  char* getTeam() const {
    return team;
  }
  short getGames() const {
    return games;
  }
  short getGoals() const {
    return goals;
  }
  short getAssists() const {
    return assists;
  }

  void setName(const char newName[20]) {
    delete[]name;
    name = nullptr;
    name = new char[strlen(newName) + 1];
    strcpy(name, newName);
  }
  void setTeam(const char newTeam[20]) {
    delete[]team;
    team = nullptr;
    team = new char[strlen(newTeam) + 1];
    strcpy(team, newTeam);
  }

  void print() const {
    if (!name || !team) goto end;
    cout.setf(ios::left);
    cout << setw(20) << name << "|" << setw(20) << team << "|" << setw(5) << age << "|" << setw(5) << games << "|" << setw(5) << goals << "|" << setw(5) << assists << "|";
  end:;
  }

  Footballer& operator=(Footballer &footballer) {
    if (!name) delete[]name;
    if (!team) delete[]team;
    name = nullptr;
    team = nullptr;
    name = new (nothrow) char[strlen(footballer.name) + 1];
    team = new (nothrow) char[strlen(footballer.team) + 1];
    strcpy(name, footballer.name);
    strcpy(team, footballer.team);
    age = footballer.age;
    games = footballer.games;
    goals = footballer.goals;
    assists = footballer.assists;
    return *this;
  }


  friend std::ostream& operator<< (std::ostream &out, const Footballer &);
  friend std::istream& operator>> (std::istream &in, Footballer &);
  friend Footballer createFootballer(const char[20], const char[20], short, short, short, short);
  friend Footballer editName(Footballer&);
  friend Footballer editName(Footballer&, const char[20]);
  friend Footballer editTeam(Footballer&);
  friend Footballer editTeam(Footballer&, const char[20]);
  friend Footballer editAge(Footballer&);
  friend Footballer editAge(Footballer&, int);
  friend Footballer editGames(Footballer&);
  friend Footballer editGames(Footballer&, int);
  friend Footballer editGoals(Footballer&);
  friend Footballer editGoals(Footballer&, int);
  friend Footballer editAssists(Footballer&);
  friend Footballer editAssists(Footballer&, int);
  friend Footballer editFootballer(Footballer&, const char[7], int);
  friend Footballer editFootballer(Footballer&, const char[4], const char[20]);
  friend Footballer deleteFootballer(Footballer&);
  friend Footballer*writeToFile(const char[40], Footballer*, int);
  friend Footballer*getTeam(Footballer*, const char[20], int);
};

int sizeArr(Footballer*arr) {
  return *((size_t *)arr - 1);
}

bool operator==(Footballer&footballer1, Footballer&footballer2) {
  if ((!strcmp(footballer1.getName(), footballer2.getName())) && (!strcmp(footballer1.getTeam(), footballer2.getTeam())) && (footballer1.getAge() == footballer2.getAge()) && (footballer1.getGames() == footballer2.getGames()) && (footballer1.getGoals() == footballer2.getGoals()) && (footballer1.getAssists() == footballer2.getAssists())) {
    return true;
  }
  else {
    return false;
  }
}

std::ostream& operator<< (std::ostream &out, const Footballer &footballer)
{
  footballer.print();
  return out;
}
std::istream& operator>> (std::istream &in, Footballer &footballer)
{
  char Name[20];
  //cout << "Input name, please: ";
  in >> Name;
  delete[]footballer.name;
  footballer.name = nullptr;
  footballer.name = new (nothrow) char[strlen(Name) + 1];
  strcpy(footballer.name, Name);
  char Team[20];
  //cout << "Input team, please: ";
  in >> Team;
  delete[]footballer.team;
  footballer.team = nullptr;
  footballer.team = new (nothrow) char[strlen(Team) + 1];
  strcpy(footballer.team, Team);
  //cout << "Input age, please: ";
  char Age[3];
  in >> Age;
  footballer.age = charToInt(Age);
  //cout << "Input count of games, please: ";
  char Games[3];
  in >> Games;
  footballer.games = charToInt(Games);
  //cout << "Input count of goals, please: ";
  char Goals[3];
  in >> Goals;
  footballer.goals = charToInt(Goals);
  //cout << "Input count of assists, please: ";
  char Assists[3];
  in >> Assists;
  footballer.assists = charToInt(Assists);
  return in;
}
std::ostream& operator<< (std::ostream &out, Footballer*arr)
{
  int N = *((size_t *)arr - 1);
  for (int i{ 0 }; i < N; ++i) {
    arr[i].print();
    cout << '\n';
  }
  return out;
}

Footballer createFootballer() {
  Footballer New;
  cin >> New;
  return New;
}
Footballer createFootballer(const char Name[20], const char Team[20], short Age, short Games, short Goals, short Assists) {
  Footballer New;
  New.name = new (nothrow) char[strlen(Name) + 1];
  New.team = new (nothrow) char[strlen(Team) + 1];
  strcpy(New.name, Name);
  strcpy(New.team, Team);
  New.age = Age;
  New.games = Games;
  New.goals = Goals;
  New.assists = Assists;
  return New;
}
Footballer*createArrayFootballers(int N) {
  Footballer*arr = new Footballer[N];
  for (int i{ 0 }; i < N; ++i) {
    cin >> arr[i];
  }
  return arr;
}
Footballer editName(Footballer &footballer) {
  char newName[20];
  cout << "Input new name, please: ";
  cin >> newName;
  delete[]footballer.name;
  footballer.name = nullptr;
  footballer.name = new char[strlen(newName) + 1];
  strcpy(footballer.name, newName);
  return footballer;
}
Footballer editName(Footballer &footballer, const char newName[20]) {
  delete[]footballer.name;
  footballer.name = nullptr;
  footballer.name = new char[strlen(newName) + 1];
  strcpy(footballer.name, newName);
  return footballer;
}
Footballer editTeam(Footballer &footballer) {
  char newTeam[20];
  cout << "Input new team, please: ";
  cin >> newTeam;
  delete[]footballer.team;
  footballer.team = nullptr;
  footballer.team = new char[strlen(newTeam) + 1];
  strcpy(footballer.team, newTeam);
  return footballer;
}
Footballer editTeam(Footballer &footballer, const char newTeam[20]) {
  delete[]footballer.team;
  footballer.team = nullptr;
  footballer.team = new char[strlen(newTeam) + 1];
  strcpy(footballer.team, newTeam);
  return footballer;
}
Footballer editAge(Footballer &footballer) {
  int newAge;
  cout << "Input, please, new age: ";
  cin >> newAge;
  footballer.age = newAge;
  return footballer;
}
Footballer editAge(Footballer &footballer, int newAge) {
  footballer.age = newAge;
  return footballer;
}
Footballer editGames(Footballer &footballer) {
  int newGames;
  cout << "Input, please, new age: ";
  cin >> newGames;
  footballer.games = newGames;
  return footballer;
}
Footballer editGames(Footballer &footballer, int newGames) {
  footballer.games = newGames;
  return footballer;
}
Footballer editGoals(Footballer &footballer) {
  int newGoals;
  cout << "Input, please, new age: ";
  cin >> newGoals;
  footballer.goals = newGoals;
  return footballer;
}
Footballer editGoals(Footballer &footballer, int newGoals) {
  footballer.goals = newGoals;
  return footballer;
}
Footballer editAssists(Footballer &footballer) {
  int newAssists;
  cout << "Input, please, new age: ";
  cin >> newAssists;
  footballer.assists = newAssists;
  return footballer;
}
Footballer editAssists(Footballer &footballer, int newAssists) {
  footballer.assists = newAssists;
  return footballer;
}
Footballer editFootballer(Footballer &footballer, const char what[4], const char New[20]) {
  switch (what[0]) {
  case 'n': editName(footballer, New); break;
  case 't': editTeam(footballer, New); break;
  default: break;
  }
  return footballer;
}
Footballer editFootballer(Footballer &footballer, const char what[7], int New) {
  switch (what[0]) {
  case 'a': {
    if (what[1] == 'g') editAge(footballer, New);
    if (what[1] == 's') editAssists(footballer, New);
    break;
  }
  case 'g': {
    if (what[1] == 'o') editGoals(footballer, New);
    if (what[1] == 'a') editGames(footballer, New);
    break;
  }
  default: break;
  }
  return footballer;
}
Footballer deleteFootballer(Footballer &footballer) {
  delete[]footballer.name;
  delete[]footballer.team;
  footballer.name = nullptr;
  footballer.team = nullptr;
  footballer.age = 0;
  footballer.assists = 0;
  footballer.games = 0;
  footballer.goals = 0;
  return footballer;
}
Footballer*deleteFootballer(Footballer*arr, const char Name[20]) {
  int s = sizeArr(arr);
  int k{ 0 };
  for (int i{ 0 }; i < s; ++i) {
    if (!strcmp(arr[i].getName(), Name)) {
      deleteFootballer(arr[i]);
      ++k;
    }
  }
  Footballer*array = new Footballer[s - k];
  Footballer t;
  k = 0;
  for (int i{ 0 }; i < s; ++i) {
    if (arr[i] == t) continue;
    array[k] = arr[i];
    k++;
  }
  return array;
}

Footballer editFootballer(Footballer&footballer, const char Name[20], const char Team[20], short Age, short Games, short Goals, short Assists) {
  editName(footballer, Name);
  editTeam(footballer, Team);
  editAge(footballer, Age);
  editGames(footballer, Games);
  editGoals(footballer, Goals);
  editAssists(footballer, Assists);
  return footballer;
}

int howFromTeam(Footballer*arr, const char Team[20]) {
  int sizeArray = sizeArr(arr);
  int k{ 0 };
  for (int i{ 0 }; i < sizeArray; ++i) {
    if (!strcmp(Team, arr[i].getTeam())) {
      ++k;
    }
  }
  return k;
}
Footballer*addArr(Footballer*arr1, Footballer*arr2) {
  int sizeArr1 = sizeArr(arr1);
  int sizeArr2 = sizeArr(arr2);
  int sizeNewArray = sizeArr1 + sizeArr2;
  Footballer*newArray = new Footballer[sizeNewArray];
  for (int i{ 0 }; i < sizeArr1; ++i) {
    newArray[i] = arr1[i];
  }
  for (int i{ 0 }; i < sizeArr2; ++i) {
    newArray[sizeArr1] = arr2[i];
    sizeArr1++;
  }
  return newArray;
}

Footballer*readFromFile(const char way[40]) {
  ifstream file(way);
  Footballer*arr = nullptr;
  if (!file) { cout << "Can't open file from " << way << '\n'; exit(1); }
  size_t count = 0;
  while (file.ignore((numeric_limits<streamsize>::max)(), '\n')) count++; // пропускаем и считаем строки
  file.close();
  arr = new Footballer[count];
  ifstream file1(way);
  for (int i{ 0 }; i < count; ++i) {
    file1 >> arr[i];
  }
  return arr;
}
Footballer*readFromFile(const char way[40], int N) {
  ifstream file(way);
  Footballer*arr = nullptr;
  if (!file) { cout << "Can't open file from " << way << '\n'; exit(1); }
  size_t count = 0;
  while (file.ignore((numeric_limits<streamsize>::max)(), '\n')) count++; // пропускаем и считаем строки
  file.close();
  if (N > count) N = count;
  arr = new Footballer[N];
  ifstream file1(way);
  for (int i{ 0 }; i < N; ++i) {
    file1 >> arr[i];
  }
  return arr;
}
Footballer*writeToFile(const char way[40], Footballer*arr, int N) {
  ofstream file(way);
  if (!file) { cout << "Can't find file from " << way << '\n'; exit(1); }
  if (N > *((size_t *)arr - 1)) N = *((size_t *)arr - 1);
  for (int i{ 0 }; i < N; ++i) {
    file << arr[i].name << " " << arr[i].team << " " << arr[i].age << " " << arr[i].games << " " << arr[i].goals << " " << arr[i].assists << '\n';;
  }
  return arr;
}

Footballer*getTeam(Footballer*arr, const char Team[20], int c) {
  //arr - массив, откуда берется выборка игроков одной команды
  //Team - название команды
  //N - количество элементов исходного массива, которое проверяется на соответствие команде Team
  //c - необходимое количество игроков
  Footballer*arrTeam = new Footballer[c];
  int k{ 0 };
  int N = *((size_t *)arr - 1);
  for (int i{ 0 }; i < N; ++i) {
    if (!strcmp(Team, arr[i].team)) {
      arrTeam[k] = arr[i];
      k++;
      if (k == c) return arrTeam;
    }
  }
  if (c > k) {
    Footballer*newArrTeam = new Footballer[k];
    for (int i{ 0 }; i < k; ++i) {
      newArrTeam[i] = arrTeam[i];
    }
    delete[]arrTeam;
    arrTeam = nullptr;
    arrTeam = new Footballer[k];
    for (int i{ 0 }; i < k; ++i) {
      arrTeam[i] = newArrTeam[i];
    }
  }
  return arrTeam;
}
Footballer*getTeam(Footballer*arr, const char Team[20]) {
  int c{ 0 };
  int sizeArray = sizeArr(arr);
  int sizeTeamArr = howFromTeam(arr, Team);
  Footballer*newArr = new Footballer[sizeTeamArr];
  for (int i{ 0 }; i < sizeArray; ++i) {
    if (!strcmp(arr[i].getTeam(), Team)) {
      newArr[c] = arr[i];
      ++c;
    }
  }
  return newArr;
}

Footballer*sortByAssists(Footballer*arr) {
  int size = *((size_t *)arr - 1);
  Footballer tmp;
  for (int i = 0; i < size - 1; ++i) // i - номер прохода
  {
    for (int j = 0; j < size - 1; ++j) // внутренний цикл прохода
    {
      if (arr[j + 1].getAssists() > arr[j].getAssists())
      {
        tmp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = tmp;
      }
    }
  }
  return arr;
}
Footballer*sortByAge(Footballer*arr) { //важный момент: во всех остальных случаях сортировка происходит т.о., чтобы самый большой элемент стоял в начале, в случае возраста же уместно обратное
  int size = *((size_t *)arr - 1);
  Footballer tmp;
  for (int i = 0; i < size - 1; ++i) // i - номер прохода
  {
    for (int j = 0; j < size - 1; ++j) // внутренний цикл прохода
    {
      if (arr[j + 1].getAge() < arr[j].getAge())
      {
        tmp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = tmp;
      }
    }
  }
  return arr;
}
Footballer*sortByGames(Footballer*arr) {
  int size = *((size_t *)arr - 1);
  Footballer tmp;
  for (int i = 0; i < size - 1; ++i) // i - номер прохода
  {
    for (int j = 0; j < size - 1; ++j) // внутренний цикл прохода
    {
      if (arr[j + 1].getGames() > arr[j].getGames())
      {
        tmp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = tmp;
      }
    }
  }
  return arr;
}
Footballer*sortByGoals(Footballer*arr) {
  int size = *((size_t *)arr - 1);
  Footballer tmp;
  for (int i = 0; i < size - 1; ++i) // i - номер прохода
  {
    for (int j = 0; j < size - 1; ++j) // внутренний цикл прохода
    {
      if (arr[j + 1].getGoals() > arr[j].getGoals())
      {
        tmp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = tmp;
      }
    }
  }
  return arr;
}
Footballer*sortByName(Footballer*arr) {
  int size = *((size_t *)arr - 1);
  Footballer tmp;
  for (int i = 0; i < size - 1; ++i) // i - номер прохода
  {
    for (int j = 0; j < size - 1; ++j) // внутренний цикл прохода
    {
      if (strcmp(arr[j + 1].getName(), arr[j].getName()) < 0)
      {
        tmp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = tmp;
      }
    }
  }
  return arr;
}
Footballer*sortByTeam(Footballer*arr) {
  int size = *((size_t *)arr - 1);
  Footballer tmp;
  for (int i = 0; i < size - 1; ++i) // i - номер прохода
  {
    for (int j = 0; j < size - 1; ++j) // внутренний цикл прохода
    {
      if (strcmp(arr[j + 1].getTeam(), arr[j].getTeam()) < 0)
      {
        tmp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = tmp;
      }
    }
  }
  return arr;
}

Footballer*howJoung(Footballer*arr, int a) {
  int N = *((size_t *)arr - 1);
  Footballer*newArr = new Footballer[N];
  int k{ 0 };
  for (int i{ 0 }; i < N; ++i) {
    if (arr[i].getAge() < a) {
      newArr[k] = arr[i];
      ++k;
    }
  }
  Footballer*howJoung = new Footballer[k];
  for (int i{ 0 }; i < k; ++i) {
    howJoung[i] = newArr[i];
  }
  sortByAge(howJoung);
  return howJoung;
}
Footballer*howOld(Footballer*arr, int a) {
  int N = *((size_t *)arr - 1);
  Footballer*newArr = new Footballer[N];
  int k{ 0 };
  for (int i{ 0 }; i < N; ++i) {
    if (arr[i].getAge() > a) {
      newArr[k] = arr[i];
      ++k;
    }
  }
  Footballer*howOld = new Footballer[k];
  for (int i{ 0 }; i < k; ++i) {
    howOld[i] = newArr[i];
  }
  sortByAge(howOld);
  return howOld;
}

double averageGoalsInMatch(Footballer &footballer) {
  return ((double)(footballer.getGoals()) / (double)(footballer.getGames()));
}
double averageGoalsInMatch(Footballer*arr, const char Team[20]) {
  Footballer*newArr = getTeam(arr, Team);
  double sum{ 0 };
  int sizeNewArr = sizeArr(newArr);
  for (int i{ 0 }; i < sizeNewArr; ++i) {
    sum += averageGoalsInMatch(newArr[i]);
  }
  return sum;
}
double averageGoalsInMatch(Footballer*arr) {
  double sum{ 0 };
  int sizeArray = sizeArr(arr);
  for (int i{ 0 }; i < sizeArray; ++i) {
    sum += averageGoalsInMatch(arr[i]);
  }
  return sum;
}

int main()
{
  setlocale(LC_ALL, "Rus");
  Footballer*array = nullptr;
begin:
  cout << "ДОБРО ПОЖАЛОВАТЬ!\nДля продолжения работы выберите один из вариантов, представленных ниже.\n1.Взять массив из исходного файла\n2.Ввести свой путь к файлу";
  short a;
  cin >> a;
  switch (a) {
  case 1: {
    array = readFromFile("C:\\Users\\ilyin\\prog\\footballers.txt"); break;
  }
  case 2: {
    char way[40];
    cin >> way;
    array = readFromFile(way);
  }
  default: break;
  }
  while (1) {
    cout << "0.Вернуться к предыдущему шагу\n1.Вывести список футболистов в текущем списке\n2.Отсортировать список футболистов\n3.Выбрать игроков из введенной команды\n4.Посчитать среднее количество голов за матч\n";
    cin >> a;
    switch (a)
    {
    case 0: {
      goto begin;
      break;
    }
    case 1: {
      cout << array; break;
    }
    case 2: {
      cout << "По какому принципу отсортировать текущий список футболистов?\n1.По именам (в алфавитном порядке)\n2.По командам (в алфавитом порядке)\n3.По количеству забитых голов\n4. по количеству голевых передач\n5. По количеству сыгранных в текущем сезоне матчей\n6.По возрасту\n";
      short b;
      cin >> b;
      switch (b)
      {
      case 1:
        sortByName(array); break;
      case 2:
        sortByTeam(array); break;
      case 3:
        sortByGoals(array); break;
      case 4:
        sortByAssists(array); break;
      case 5:
        sortByGames(array); break;
      case 6:
        sortByAge(array); break;
      default:
        break;
      }
      break;
    case 3: {
      char Team[20];
      cin >> Team;
      cout<<getTeam(array, Team)<<'\n';
      break;
    }
    case 4: {
      cout << "1.В текущем списке\n2.В введенной команде из текущего списка\n";
      short d;
      cin >> d;
      switch (d)
      {
      case 1: {
        cout<<averageGoalsInMatch(array)<<'\n';
        break;
      }
      case 2: {
        char Team1[20];
        cin >> Team1;
        cout<<averageGoalsInMatch(array, Team1)<<'\n';
      }
      default:
        break;
      }
    } break;
    }
    default:
      break;
    }
  }
  system("pause");
}
