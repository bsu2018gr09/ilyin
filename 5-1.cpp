//Горизонтальный градиент
#include<iostream>
#include<fstream>  
#include<clocale>
using namespace std;
struct color { unsigned char b; unsigned char g; unsigned char r; } c;

int main() {
  setlocale(LC_ALL, "RUS");
  ifstream fff("C:\\file.bmp", ios::binary); //  ios::binary влияет ТОЛЬКО на endl.
  ofstream ggg("C:\\wrt.bmp", ios::binary);//сюда пишем (поток типа ofstream= output file stream)
  if (!fff) { cout << "No file d:\\1.bmp. Can't open\n"; exit(1); }
  if (!ggg) { cout << "No file d:\\rez.bmp. Can't create\n"; exit(1); }

  char buf[30];// куда читать байты
  color c;
  unsigned int w, h;//надеемся. что тут 4 байта
  fff.read((char *)&buf, 18);
  ggg.write((char *)&buf, 18);
  fff.read((char *)&w, 4);
  fff.read((char *)&h, 4);
  w = 1024; h = 400; //ввод ширины и высоты
  ggg.write((char *)&w, 4);
  ggg.write((char *)&h, 4);
  fff.read((char *)&buf, 28);
  ggg.write((char *)&buf, 28);
  float step = 100; //вовд шага
  if (step > w){
    step = w;
    cout << "Количество шагов больше ширины, поэтому произведена запись плавного градиента с количеством шагов, равным количеству пикселей по ширине.";
  }
  
  float begR = 255; //начальные значения цветов
  float begG = 0;
  float begB = 255;
  float rr = 255; //конечные значения цветов
  float gg = 0;
  float bb = 0;
  float stepR = (rr - begR) / step; //вычисление шагов для цветов
  float stepG = (gg - begG) / step;
  float stepB = (bb - begB) / step;
  int kk = 0;
  float tmpR = begR; //для присвоения в каждой строке
  float tmpG = begG;
  float tmpB = begB;
  int k = 0;
  for (int i = 1; i <= h; ++i) {
    for (int j = 1; j <= w; ++j) {
      if (k >= step) { //за step шагов цвет меняется, после этого пишется конечный цвет
        goto prod;
      }
      tmpR += stepR;
      tmpG += stepG;
      tmpB += stepB;
      k++;
   prod:
      c.r = tmpR;
      c.g = tmpG;
      c.b = tmpB;
      ggg.write((char *)&c, 3);
    }
    tmpR = begR;
    tmpG = begG;
    tmpB = begB;
    k = 0;
  }
  fff.close();
  ggg.close();
  system("pause");
}
