#ifndef CINEMA
#define CINEMA
#include <string>
using namespace std;

class Cinema {
private:
  struct Info {
    char nome[15];
    char shopping[30];
    int qtsSalas;
  } info;

public:
  Cinema();
  ~Cinema();

  void setNome(std::string);
  char *getNome();
  void setShopping(std::string);
  char *getShopping();
  void setQtsSalas(int);
  int getQtsSalas();
};

#endif