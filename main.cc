#include <fstream>
#include <iostream>
using namespace std;

const string FILE_NAME = "cinemas.txt";
FILE* fin = fopen("cinemas.txt", "ab");
//ifstream fin;

// dbo do cinema
struct Cinema {
    int id;
    string nome;
    string shopping;
    string sala;
  };

  void post(){
  char continuar;
  Cinema cinema;
  int id;
  string nome, sala, shopping;

  do {
    fflush(stdin);
    cout<<"Digite o id do cinema: ";
    cin>>cinema.id;
    cin.ignore();
    cout<<"Digite o nome do cinema: ";
    getline(cin, nome);
    cin>>cinema.nome;
    cin.ignore();
    cout<<"Digite o nome do shopping: ";
    getline(cin, shopping);
    cin>>cinema.shopping;
    cin.ignore();
    cout<<"Digite a sala do shopping: ";
    getline(cin, sala);
    cin>>cinema.sala;
    cin.ignore();

    fwrite(&cinema, sizeof(Cinema), 1, fin);

    cout<<"Deseja adicionar outro cinema? (s/n)";
    cin>>continuar;
  }
  while(isupper(continuar) == 'S');
}

int main() {
  int option = 0;



  // lendo o arquivo
  // const string FILE_NAME = "cinemas.txt";

	// ifstream fin;
	// fin.open(FILE_NAME);

  // // verifica se ele existe
  // if (!fin.is_open()) 
	// {
	// 	cout << "O arquivo >" << FILE_NAME << "< nao foi encontrado!\n";
	// 	exit(0);
	// }

  // menu
  std::cout << "=-=-=- C.R.U.D DE CINEMAS =-=-=-\n\n";
  std::cout << "[1] - Exibir uma cidade\n";
  std::cout << "[2] - Exibir várias cidades\n";
  std::cout << "[3] - Adicionar uma cidade\n";
  std::cout << "[4] - Excluir uma cidade\n";
  std::cout << "[5] - Editar uma cidade\n";
  std::cout << "[0] - Sair do programa\n\n";

  std::cout << "Digite uma opcao... ";
  std::cin >> option;

  if (option != 0) {
    switch (option) {
    case 1:
      std::cout << "exibir 1";
      break;
    case 2:
      std::cout << "exibir varias ";
      break;
    case 3:
      //std::cout << "adicionar ";
      post();
      break;
    case 4:
      std::cout << "excluir ";
      break;
    case 5:
      std::cout << "editar ";
      break;
    }
  }

  exit(1);
}