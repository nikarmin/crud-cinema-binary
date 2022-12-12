#include "cinema.h"
#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class Cinemas {
public:
  // Char para repetição
  char continuar = 'S';

  // Arquivos para leitura/escrita
  const char *arq = "cinemas.dat";
  ifstream iffile;
  ofstream offile;

  // // Declarações dos métodos
  // void post();
  // void readAll();
  // void update();
  // void deleteOne();
  // void readOne();

  // Verifica se a string é número
  bool isNumber(const string &str) {
    return str.find_first_not_of("0123456789") == string::npos;
  }

  // Verifica se o arquivo está vazio
  int get_size(const char *file_name) {
    FILE *file = fopen(file_name, "r");
    Cinema cin;

    string shopping = cin.getShopping();

    if (file == NULL)
      return 0;

    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fclose(file);

    return size;
  }

  void update() {
    // Se o arquivo não tiver nada, não é possível editar nenhum registro
    if (get_size("cinemas.dat") == 0) {
      cout << "\n[NAO HA NENHUM REGISTRO NO ARQUIVO!]\n";
    }
    // Se tiver algum registro
    else {
      // Abertura do arquivo
      FILE *arquivo = fopen(arq, "r+b");
      iffile.open("cinemas.dat", ios::binary | ios::in);

      // Declaração de variáveis
      int id, linha;
      Cinema cinema;
      string nome, sala, shopping, numero;

      cout << "\nDigite o [ID] do cinema que queira editar: ";
      cin >> id;

      // Contador de linha
      linha = 0;
      // Char para verificar se encontrou ou não o registro
      char encontrou = 'F';

      // Lê o arquivo até achar o registro
      while (iffile.read((char *)&cinema, sizeof(cinema)) && encontrou == 'F') {
        if (id == linha) {
          encontrou = 'S';
        }
        linha += 1;
      }

      // Se não achou, atualizamos o usuário e fechamos os arquivos
      if (encontrou == 'F') {
        iffile.close();
        fclose(arquivo);
        cout << "\n[CINEMA NAO ENCONTRADO!] \n";
      }

      // Se achou, continuamos o processo
      else {
        // Fechamos o arquivo que foi utilizado para procurar o registro
        iffile.close();

        system("clear||cls");
        fflush(stdin);

        // Colocamos o ponteiro no id que o usuário escreveu
        fseek(arquivo, id * sizeof(Cinema), SEEK_SET);

        cin.ignore();

        // Pegamos as informações
        cout << "Digite o [NOME] do [CINEMA]: ";
        getline(cin, nome);
        // strcpy(cinema.nome, nome.c_str());

        cout << "Digite o [NOME] do [SHOPPING]: ";
        getline(cin, shopping);
        // strcpy(cinema.shopping, shopping.c_str());

        cout << "Digite a [SALA] do cinema: ";
        cin >> numero;

        cin.ignore();

        // Verifica se as string's estão no tamanho correto
        if (nome.length() < 15 && shopping.length() < 30 && isNumber(numero)) {
          id = stol(numero);
          cinema.setQtsSalas(id);
          cinema.setShopping(shopping);
          cinema.setNome(nome);
          // cinema.qtsSalas = id;
          // strcpy(cinema.shopping, shopping.c_str());
          // strcpy(cinema.nome, nome.c_str());
          fwrite(&cinema, sizeof(Cinema), 1, arquivo);
          readAll();
        } else {
          cout << "\n>> DIGITE CORRETAMENTE NOS PADROES! <<\n";
        }

        // Fecha o arquivo escrito e mostra os registros
        fclose(arquivo);
      }
    }
  }

  void post() {
    system("clear||cls");
    char continuar;
    FILE *arquivo = fopen(arq, "ab");
    Cinema cinema;
    string nome, sala, shopping, numero;

    do {
      system("clear||cls");
      fflush(stdin);

      cin.ignore();

      // Pegando informações
      cout << "Digite o [NOME] do [CINEMA]: ";
      getline(cin, nome);
      // strcpy(cinema.nome, nome.c_str());

      cout << "Digite o [NOME] do [SHOPPING]: ";
      getline(cin, shopping);
      // strcpy(cinema.shopping, shopping.c_str());

      cout << "Digite a [SALA]: ";
      cin >> numero;

      cin.ignore();

      // Verifica se as string's estão no tamanho correto
      if (nome.length() < 15 && shopping.length() < 30 && isNumber(numero)) {
        cinema.setQtsSalas(stol(numero));
        cinema.setShopping(shopping);
        // cinema.qtsSalas = stol(numero);
        cinema.setNome(nome);
        // cinema.set();
        // strcpy(cinema.getNome(), nome.c_str());
        // strcpy(cinema.getShopping(), shopping.c_str());
        fwrite(&cinema, sizeof(Cinema), 1, arquivo);
      } else {
        cout << "\n>> DIGITE CORRETAMENTE NOS PADROES! <<\n";
      }

      // Looping para caso o usuário deseje continuar adicionando cinemas
      cout << "\nDeseja continuar adicionando? (S/N): ";
      cin >> continuar;
    } while (toupper(continuar) == 'S');

    fclose(arquivo);
  }

  void readOne() {
    // Abre o arquivo
    iffile.open("cinemas.dat", ios::binary | ios::in);

    // Se o arquivo não existe
    if (!iffile) {
      cout << "\nO arquivo nao pode ser aberto!\n";
    }

    // Se não há nenhum registro, não tem como mostrar nenhum
    else if (get_size("cinemas.dat") == 0) {
      cout << "\n[NAO HA NENHUM REGISTRO NO ARQUIVO!]\n";
    }

    else {
      int id, linha;
      string numero;
      Cinema cinema;

      // O usuário digita o ID do cinema que ele gostaria de ver
      cout << "\nColoque o [ID] do cinema que queira encontrar: ";
      cin >> numero;

      if (isNumber(numero)) {
        id = stol(numero);
        linha = 0;
        char encontrou = 'F';

        // Percorre o arquivo, em busca do ID digitado
        while (iffile.read((char *)&cinema, sizeof(cinema)) &&
               encontrou == 'F') {
          // Se for encontrado, escrevemos na tela
          if (id == linha) {
            cout << '\n';
            cout << id << " " << cinema.getNome() << " " << cinema.getShopping()
                 << " " << cinema.getQtsSalas() << endl;
            cout << '\n';
            encontrou = 'S';
          }
          linha += 1;
        }

        // Se não, avisamos o usuário
        if (encontrou == 'F') {
          cout << "\n[CINEMA NAO ENCONTRADO!] \n";
        }
      } else {
        cout << "\n[DIGITE CORRETAMENTE UM NUMERO]\n";
      }
    }

    iffile.close();
  }

  void readAll() {
    // Verifica se tem algo no arquivo
    if (get_size("cinemas.dat") == 0) {
      cout << "\n[NAO HA NENHUM REGISTRO NO ARQUIVO!]\n";
    }

    // Se tiver
    else {
      FILE *arquivo = fopen(arq, "rb");

      if (!arquivo) {
        arquivo = fopen(arq, "w+b");
      }

      int id = 0;
      Cinema cinema;
      system("clear||cls");
      fread(&cinema, sizeof(Cinema), 1, arquivo);

      cout << ".: Leitura de [CINEMAS] :. \n\n";
      cout << "CODIGO"
           << " | "
           << "NOME DO CINEMA"
           << " | "
           << "NOME DO SHOPPING"
           << " | "
           << "QTD. SALA\n"
           << endl;

      // Looping para ler todos os registros
      do {
        cout << id << " " << cinema.getNome() << " " << cinema.getShopping()
             << " " << cinema.getQtsSalas() << endl;

        fread(&cinema, sizeof(Cinema), 1, arquivo);
        id += 1;
      } while (feof(arquivo) == 0);
      fclose(arquivo);
      cout << endl;
    }
  }

  void deleteOne() {
    iffile.open("cinemas.dat", ios::binary | ios::in);
    offile.open("temp.dat", ios::binary | ios::out);

    // Se não conseguirem abrir os arquivo
    if (!iffile || !offile) {
      cout << "O arquivo nao pode ser aberto!";
    }

    else {
      // Verifica se o arquivo é vazio, se não, não tem como deletar algum
      // cinema
      if (get_size("cinemas.dat") == 0) {
        cout << "\n[NAO HA NENHUM REGISTRO NO ARQUIVO!]\n";
        iffile.close();
        offile.close();
      }

      else {
        // O usuário digita qual cinema ele quer deletar
        int id, linha;
        Cinema cinema;
        string numero;
        cout << "\nColoque o [ID] do cinema que queira deletar: ";
        cin >> numero;
        linha = 0;

        if (isNumber(numero)) {
          id = stol(numero);

          // Reescrevemos o arquivo sem aquela linha
          while (iffile.read((char *)&cinema, sizeof(cinema))) {
            if (id != linha) {
              offile.write((char *)&cinema, sizeof(cinema));
            }
            linha += 1;
          }

          cout << "\n[CINEMA DELETADO]\n";
          // Fechamos os dois arquivos, o original e o auxiliar
          iffile.close();
          offile.close();

          // Trocamos o arquivo temporário, e o renomeamos para o nome original
          remove("cinemas.dat");
          rename("temp.dat", "cinemas.dat");
        } else {
          cout << "\n[DIGITE CORRETAMENTE UM NUMERO]\n";
          iffile.close();
          offile.close();
        }
      }
    }
  }
};