#include <string>
#include <cstring>
using namespace std;

// Struct do Cinema

struct Cinema
{
    // Variáveis

    int id;
    char nome[15];
    char shopping[30];
    int qtsSalas;

    // Getters e Setters (que não servem pra nada)

    void setId(int otherId) { id = otherId; }

    void setNome(char *otherNome) { strcpy(nome, otherNome); }

    void setShopping(char *otherShopping) { strcpy(shopping, otherShopping); }

    void setSalas(int otherQts) { qtsSalas = otherQts; }

    int getId() { return id; }

    char *getNome() { return nome; }

    char *getShopping() { return shopping; }

    int getSala() { return qtsSalas; }
};