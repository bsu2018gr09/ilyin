//горизонтальный градиент
#include<iostream>
#include<fstream> 		                 // подключение библиотеки файлового ввода/вывода через потоки
using namespace std;
struct color { unsigned char r; unsigned char g; unsigned char b; } c;

int main() {
  setlocale(LC_ALL, "Russian");
  float kkk;
  cout << sizeof(kkk);
  ifstream fff("C:\\file.bmp", ios::binary); // ios::binary влияет ТОЛЬКО на endl. 
  ofstream ggg("C:\\wrt.bmp", ios::binary);//сюда пишем (поток типа ofstream= output file stream) 
  if (!fff) { cout << "No file C:\\file.bmp. Can't open\n"; exit(1); }
  if (!ggg) { cout << "No file C:\\rez.bmp. Can't create\n"; exit(1); }

  char buf[30];// куда читать байты 
  unsigned char r, g, b;//компоненты цвета 
  color c;
  unsigned int w, h;//надеемся. что тут 4 байта 

  fff.read((char *)&buf, 18); //чтение 18 байт заголовка bmp 
  ggg.write((char *)&buf, 18); //запись 18 байт заголовка bmp 
  fff.read((char *)&w, 4); cout << "w=" << w; //чтение width из заголовка bmp 
  fff.read((char *)&w, 4); cout << ", h=" << w; //чтение height из заголовка bmp 
  w = 256; ggg.write((char *)&w, 4); //запись width в заголовок bmp ( w кратно 4, обязательно для нас, чтобы не делать выравнивание) 
  h = 128; ggg.write((char *)&h, 4); //запись height в заголовок bmp 
  fff.read((char *)&buf, 28); //чтение 28 байт заголовка bmp 
  ggg.write((char *)&buf, 28); //запись 28 байт заголовка bmp 
  
  c.r = 255;//при изменении чисел появляются слева и внизу странные зеленые полосы в bmp
  c.g = 255;
  c.b = 255;
  float rr = 0;
  float gg = 0;
  float bb = 0;
  float step = 200;
  float stepR = (rr - c.r) / step;
  float stepG = (gg - c.g) / step;
  float stepB = (bb - c.b) / step;
  int kk = 0;
  float tmpR = c.r;
  float tmpG = c.g;
  float tmpB = c.b;
  
  for (int i{ 0 }; i < h; ++i) { //горизонтальный градиент, от переменной step зависит, смещение градиента вправо при увеличении в влево при уменьшении
    for (int j{ 0 }; j < w; ++j) {
      if (kk < step) {
        tmpR += stepR;
        tmpG += stepG;
        tmpB += stepB;
        c.r = (unsigned char)tmpR;
        c.g = (unsigned char)tmpG;
        c.b = (unsigned char)tmpB;
        kk++;
      }
      ggg.write((char *)&c, 3);      
    }    
    tmpR = rr;
    tmpG = gg;
    tmpB = bb;
    kk = 0;
  }
 
