/**
 * @author Nicoli (21689) e Danyelle (21232)
 * CRUD EM ARQUIVO BINÁRIO - CINEMAS
 * Professor: Maligno
 */

#include "cinemas.h"
#include "cinema.h"
#include <algorithm>
#include <cctype>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

Cinemas::Cinemas() {}

Cinemas::~Cinemas() {}

bool Cinemas::isNumber(const string &str)
{
  return str.find_first_not_of("0123456789") == string::npos;
}

int Cinemas::get_size(const char *file_name)
{
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

void Cinemas::update()
{
  // Se o arquivo não tiver nada, não é possível editar nenhum registro
  if (get_size("cinemas.dat") == 0)
  {
    cout << "\n[NAO HA NENHUM REGISTRO NO ARQUIVO!]\n";
  }
  // Se tiver algum registro
  else
  {
    // Abertura do arquivo
    ffile.open("cinemas.dat", ios::binary | ios::in | ios::out);
    ffile.seekg(0);

    // Declaração de variáveis
    int id, indice;
    Cinema cinema;
    string nome, sala, shopping, numero;
    char correto = 'F';

    cout << "\nDigite o [ID] do cinema que queira editar: ";
    cin >> numero;

    // Verificar se a pessoa realmente digitou um número
    if (isNumber(numero) && (stol(numero) >= 0))
    {
      id = stol(numero);

      // Char para verificar se encontrou ou não o registro
      char encontrou = 'F';

      iffile.seekg(0);

      // Lê o arquivo até achar o registro
      while (ffile.read((char *)&cinema, sizeof(cinema)) && encontrou == 'F')
      {
        indice = ffile.tellg();

        if (cinema.getId() == id)
        {

          system("clear||cls");
          cin.ignore();

          // Pegamos as informações
          cout << "Digite o [NOME] do [CINEMA]: ";
          getline(cin, nome);

          cout << "Digite o [NOME] do [SHOPPING]: ";
          getline(cin, shopping);

          cout << "Digite a [SALA] do [CINEMA]: ";
          cin >> numero;

          cin.ignore();
          encontrou = 'S';

          // Verifica se as string's estão no tamanho correto
          if (nome.length() < 15 && shopping.length() < 30 &&
              isNumber(numero))
          {
            id = stol(numero);
            cinema.setQtsSalas(id);
            cinema.setShopping(shopping);
            cinema.setNome(nome);
            correto = 'S';
            ffile.seekp(-sizeof(cinema), ios::cur);
            ffile.write((char *)&cinema, sizeof(cinema));
          }
          else
          {
            cout << "\n>> DIGITE CORRETAMENTE NOS PADROES! <<\n";
          }
        }
      }

      // Se não achou, atualizamos o usuário e fechamos os arquivos
      if (encontrou == 'F')
      {
        ffile.close();
        cout << "\n[CINEMA NAO ENCONTRADO!] \n";
      }

      ffile.close();

      // Se os dados estiverem corretos, mostra todos os cinemas
      if (correto == 'S')
      {
        readAll();
      }
    }
    else
    {
      cout << "\n[DIGITE CORRETAMENTE UM NUMERO]\n";
      ffile.close();
    }
  }
}

void Cinemas::post()
{
  system("clear||cls");
  char continuar;
  offile.open("cinemas.dat", ios::binary | ios::app);
  Cinema cinema;
  string nome, sala, shopping, numero, numeroId;

  do
  {
    system("clear||cls");
    fflush(stdin);

    cin.ignore();

    // Pegando informações
    cout << "Digite o [ID] do [CINEMA]: ";
    cin >> numeroId;
    cin.ignore();

    cout << "Digite o [NOME] do [CINEMA]: ";
    getline(cin, nome);

    cout << "Digite o [NOME] do [SHOPPING]: ";
    getline(cin, shopping);

    cout << "Digite a [SALA]: ";
    cin >> numero;

    cin.ignore();

    // Verifica se as string's estão no tamanho correto
    if (nome.length() < 15 && shopping.length() < 30 && isNumber(numero) &&
        (stol(numero) >= 0) && isNumber(numeroId) && (stol(numeroId) >= 0))
    {
      cinema.setId(stol(numeroId));
      cinema.setQtsSalas(stol(numero));
      cinema.setShopping(shopping);
      cinema.setNome(nome);
      offile.write((char *)&cinema, sizeof(cinema));
    }
    else
    {
      cout << "\n>> DIGITE CORRETAMENTE NOS PADROES! <<\n";
    }

    // Looping para caso o usuário deseje continuar adicionando cinemas
    cout << "\nDeseja continuar adicionando? (S/N): ";
    cin >> continuar;
  } while (toupper(continuar) == 'S');

  offile.close();
}

void Cinemas::readOne()
{
  // Abre o arquivo
  iffile.open("cinemas.dat", ios::binary);

  // Se o arquivo não existe
  if (!iffile)
  {
    cout << "\nO arquivo nao pode ser aberto!\n";
  }

  // Se não há nenhum registro, não tem como mostrar nenhum
  else if (get_size("cinemas.dat") == 0)
  {
    cout << "\n[NAO HA NENHUM REGISTRO NO ARQUIVO!]\n";
  }

  else
  {
    int id, linha;
    string numero;
    Cinema cinema;

    // O usuário digita o ID do cinema que ele gostaria de ver
    cout << "\nColoque o [ID] do cinema que queira encontrar: ";
    cin >> numero;

    if (isNumber(numero) && (stol(numero) >= 0))
    {
      id = stol(numero);
      linha = 0;
      char encontrou = 'F';

      // Percorre o arquivo, em busca do ID digitado
      while (iffile.read((char *)&cinema, sizeof(cinema)) && encontrou == 'F')
      {
        // Se for encontrado, escrevemos na tela
        if (cinema.getId() == id)
        {
          cout << '\n';
          cout << cinema.getId() << " " << cinema.getNome() << " "
               << cinema.getShopping() << " " << cinema.getQtsSalas() << endl;
          cout << '\n';
          encontrou = 'S';
        }
        linha += 1;
      }

      // Se não, avisamos o usuário
      if (encontrou == 'F')
      {
        cout << "\n[CINEMA NAO ENCONTRADO!] \n";
      }
    }
    else
    {
      cout << "\n[DIGITE CORRETAMENTE UM NUMERO]\n";
    }
  }

  iffile.close();
}

void Cinemas::readAll()
{
  // Verifica se tem algo no arquivo
  if (get_size("cinemas.dat") == 0)
  {
    cout << "\n[NAO HA NENHUM REGISTRO NO ARQUIVO!]\n";
  }

  // Se tiver
  else
  {
    iffile.open("cinemas.dat", ios::binary);

    if (!iffile)
    {
      cout << "\n[NAO FOI POSSIVEL ABRIR O ARQUIVO]\n";
      iffile.close();
    }

    else
    {
      int id = 0;
      Cinema cinema;
      system("clear||cls");

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
      while (iffile.read((char *)&cinema, sizeof(cinema)))
      {
        cout << cinema.getId() << " " << cinema.getNome() << " "
             << cinema.getShopping() << " " << cinema.getQtsSalas() << endl;
      }
    }

    iffile.close();
  }
}

void Cinemas::deleteOne()
{
  iffile.open("cinemas.dat", ios::binary | ios::in);
  offile.open("temp.dat", ios::binary | ios::out);

  // Se não conseguirem abrir os arquivo
  if (!iffile || !offile)
  {
    cout << "\nO arquivo nao pode ser aberto!\n";
    iffile.close();
    offile.close();
  }

  else
  {
    // Verifica se o arquivo é vazio, se não, não tem como deletar algum cinema
    if (get_size("cinemas.dat") == 0)
    {
      cout << "\n[NAO HA NENHUM REGISTRO NO ARQUIVO!]\n";
      iffile.close();
      offile.close();
    }

    else
    {
      // O usuário digita qual cinema ele quer deletar
      int id;
      Cinema cinema;
      string numero;
      char encontrou = 'F';
      cout << "\nColoque o [ID] do cinema que queira deletar: ";
      cin >> numero;

      if (isNumber(numero) && (stol(numero) >= 0))
      {
        id = stol(numero);

        // Reescrevemos o arquivo sem aquela linha
        while (iffile.read((char *)&cinema, sizeof(cinema)))
        {
          if (cinema.getId() != id)
          {
            offile.write((char *)&cinema, sizeof(cinema));
          }
          else
          {
            encontrou = 'V';
          }
        }

        if (encontrou == 'V')
        {
          cout << "\n[CINEMA DELETADO]\n";
          // Fechamos os dois arquivos, o original e o auxiliar
          iffile.close();
          offile.close();

          // Trocamos o arquivo temporário, e o renomeamos para o nome original
          remove("cinemas.dat");
          rename("temp.dat", "cinemas.dat");
        }
        else
        {
          cout << "\n[CINEMA NAO ENCONTRADO]\n";
        }
      }
      else
      {
        cout << "\n[DIGITE CORRETAMENTE UM NUMERO]\n";
        iffile.close();
        offile.close();
      }
    }
  }
}