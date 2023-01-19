/**
 * @author Nicoli (21689) e Danyelle (21232)
 * CRUD EM ARQUIVO BINÁRIO - CINEMAS
 * Professor: Maligno
 */

#ifndef CINEMAS
#define CINEMAS
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class Cinemas {
private:
  // Arquivos para leitura/escrita
  const char *arq = "cinemas.dat";
  ifstream iffile;
  ofstream offile;
  fstream ffile;

public:
  // Char para repetição
  char continuar = 'S';

  Cinemas();
  ~Cinemas();

  bool isNumber(const string &str);
  int get_size(const char *file_name);
  void update();
  void post();
  void readOne();
  void readAll();
  void deleteOne();
};

#endif