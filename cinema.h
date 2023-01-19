/**
 * @author Nicoli (21689) e Danyelle (21232)
 * CRUD EM ARQUIVO BINÁRIO - CINEMAS
 * Professor: Maligno
 */

#ifndef CINEMA
#define CINEMA
#include <string>
using namespace std;

class Cinema {
private:
  struct Info {
    int id;
    char nome[15];
    char shopping[30];
    int qtsSalas;
  } info;

public:
  Cinema();
  ~Cinema();

  void setId(int);
  int getId();
  void setNome(std::string);
  char *getNome();
  void setShopping(std::string);
  char *getShopping();
  void setQtsSalas(int);
  int getQtsSalas();
};

#endif