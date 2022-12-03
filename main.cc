#include <fstream>
#include <iostream>
using namespace std;

ofstream fin("cinemas.dat", ios::ate);
//FILE *arquivo;
char continuar = 'S';

// dbo do cinema
struct Cinema {
    int id;
    string nome;
    string shopping;
    string sala;

    void setDetails(int id,string nome,string shopping, string sala){
        this->id=id;
        this->nome=nome;
        this->shopping=shopping;
        this->sala=sala;
    }

    void setUpdateDetails(string nome,string shopping){
        this->nome=nome;
        this->shopping=shopping;
    }

    int getid(){
        return id;
    }

    string getnome(){
        return nome;
    }

    string getshopping(){
        return shopping;
    }

    string getsala(){
        return sala;
    }
  };

  Cinema* todosCinemas;
  int size;

  void post() {
  // sobrescreve os itens do txt **arrumar
  Cinema cinema;
  int id;
  string nome, sala, shopping;

  do {
    // fflush(stdin);
    std::cout << "\nDigite o id do cinema: ";
    std::cin >> cinema.id;
    // cin.ignore();
    std::cout << "Digite o nome do cinema: ";
    // getline(cin, cinema.nome);
    std::cin >> cinema.nome;
    std::cin.ignore();
    std::cout << "Digite o nome do shopping: ";
    // getline(cin, cinema.shopping);
    std::cin >> cinema.shopping;
    std::cin.ignore();
    std::cout << "Digite a sala do shopping: ";
    // getline(cin, cinema.sala);
    std::cin >> cinema.sala;
    std::cin.ignore();

    fin.seekp((cinema.id - 1) * sizeof(cinema));

    // fwrite(&cinema, sizeof(Cinema), 1, fin);

    //std::fin << cinema.id << cinema.nome << cinema.sala << cinema.shopping << '\n';

    std::cout << "Deseja continuar? (S/N) ";
    std::cin >> continuar;
  } while (toupper(continuar) == 'S');
}

int main() {
int option = 0;

  if (!fin)
  {
    std::cerr << "O arquivo nao pode ser aberto!" << std::endl;
  }

  // lendo o arquivo
  // arquivo = fopen("cinemas.dat", "wb");
  // const string FILE_NAME = "cinemas.txt";

  // ifstream fin;
  // fin.open(FILE_NAME, ios::ate);

  // verifica se ele existe
  // if (arquivo == NULL) {
  //   std::cout << "O arquivo nao foi encontrado!\n";
  //   exit(0);
  // }

  // menu
  // colocar um while legal aqui pra sempre rodar

  while (toupper(continuar) == 'S') {
    system("clear||cls");
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
      case 0:
        exit(1);
        break;
      case 1:
        std::cout << "exibir 1";
        break;
      case 2:
        std::cout << "exibir varias ";
        break;
      case 3:
        // std::cout << "adicionar ";
        post();
        //fclose(arquivo);
        break;
      case 4:
        std::cout << "excluir ";
        break;
      case 5:
        std::cout << "editar ";
        break;
      }
    }
    std::cout << "\nDeseja continuar na aplicacao? (S/N) ";
    std::cin >> continuar;
  }

  exit(1);
}

// void Excluir()
//   {
//     for (int i=0;i<size;i++){
//         if(todosCinemas[i].getid()==id)
//         {
//             todosCinemas[i].setDetails(0,"","");
//             return;
//           }
//     }
//   }

//   void EditarCinema(int id)
//   {
//     for(int i=0;i<size;i++){
//     if(todosCinemas[i].getid()==id)
//     {
//         string nome=getString("Digite o nome\n");
//         string shopping=getString("Digite o shopping\n");
//         string sala=getString("Digite a sala\n");
//         todosCinemas[i].setDetails(id,nome,shopping, sala);
//         }
//         return;
//     }
//   }

//     void AdicionarCinema(){
//     Cinema cinem;
//     int id=getInteger("\nDigite o ID\t");
//     string nome=getString("Digite o NOME\t");
//     string shopping=getString("Digite o SHOPPING\t");
//     string sala=getString("Digite a SALA\t");
//     cinem.setDetails(id,nome,shopping, sala);
//     AdicionarNovoCinema(cinem);
//     print("\Cinema cadastrado!\n");
//     }

//     void AdicionarNovoCinema(Cinema cinem){
// 		for(int i=0;i<size;i++)
// 		{
// 		if(todosCinemas[i].getnome()==""){
// 			todosCinemas[i].setDetails(cinem.getid(),cinem.getnome(),cinem.getshopping(), cinem.getsala());
// 			return;
// 		}
// 		}
//     }

//     void ExcluirUmCinema(){
// 			int cinem=getInteger("Digite o ID \n");
// 			Excluir(cinem);
// 			print("Cinema excluido com sucesso!\n");

// 		}
