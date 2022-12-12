#include "cinema.h"
#include <cstring>
using namespace std;

// Cinema::Cinema() { this->info = {"", "", -1}; }
Cinema::Cinema() {}

Cinema::~Cinema() {}

void Cinema::setNome(string nome) { strcpy(this->info.nome, nome.c_str()); }

void Cinema::setShopping(string shopping) {
  strcpy(this->info.shopping, shopping.c_str());
}

void Cinema::setQtsSalas(int qtd) { this->info.qtsSalas = qtd; }

char *Cinema::getNome() { return this->info.nome; }

char *Cinema::getShopping() { return this->info.shopping; }

int Cinema::getQtsSalas() { return this->info.qtsSalas; }

/*
void setNome(std::string);
  char *getNome();
  void setShopping(std::string);
  char *getShopping();
  void setQtsSalas(int);
  int getQtsSalas();
*/
