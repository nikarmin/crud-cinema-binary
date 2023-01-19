/**
 * @author Nicoli (21689) e Danyelle (21232)
 * CRUD EM ARQUIVO BINÁRIO - CINEMAS
 * Professor: Maligno
 */

#include "cinema.h"
#include <cstring>

Cinema::Cinema() {}

Cinema::~Cinema() {}

void Cinema::setNome(string nome) { strcpy(this->info.nome, nome.c_str()); }

void Cinema::setShopping(string shopping) {
  strcpy(this->info.shopping, shopping.c_str());
}

void Cinema::setQtsSalas(int qtd) { this->info.qtsSalas = qtd; }

void Cinema::setId(int id) { this->info.id = id; }

char *Cinema::getNome() { return this->info.nome; }

char *Cinema::getShopping() { return this->info.shopping; }

int Cinema::getQtsSalas() { return this->info.qtsSalas; }

int Cinema::getId() { return this->info.id; }