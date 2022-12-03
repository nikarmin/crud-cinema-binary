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

  void post(){
  char continuar;
  Cinema cinema;
  int id;
  string nome, sala, shopping;

  do {
    fflush(stdin);
    cout<<"Digite o ID do cinema: ";
    cin>>cinema.id;
    cin.ignore();
    cout<<"Digite o NOME do cinema: ";
    getline(cin, nome);
    cin>>cinema.nome;
    cin.ignore();
    cout<<"Digite o NOME do shopping: ";
    getline(cin, shopping);
    cin>>cinema.shopping;
    cin.ignore();
    cout<<"Digite a SALA do shopping: ";
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
  std::cout << "[1] - Exibir um cinema\n";
  std::cout << "[2] - Exibir vários cinemas\n";
  std::cout << "[3] - Adicionar um cinema\n";
  std::cout << "[4] - Excluir um cinema\n";
  std::cout << "[5] - Editar um cinema\n";
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

  void Excluir()
  {
    for(int i=0;i<size;i++){
        if(todosCinemas[i].getid()==id){
            todosCinemas[i].setDetails(0,"","");
            return;
            }
    }
  }

  void EditarCinema(int id)
  {
    for(int i=0;i<size;i++){
    if(todosCinemas[i].getid()==id)
    {
        string nome=getString("Digite o nome\n");
        string shopping=getString("Digite o shopping\n");
        string sala=getString("Digite a sala\n");
        todosCinemas[i].setDetails(id,nome,shopping, sala);
        }
        return;
    }
  }

    void AdicionarCinema(){
    Cinema cinem;
    int id=getInteger("\nDigite o ID\t");
    string nome=getString("Digite o NOME\t");
    string shopping=getString("Digite o SHOPPING\t");
    string sala=getString("Digite a SALA\t");
    cinem.setDetails(id,nome,shopping, sala);
    AdicionarNovoCinema(cinem);
    print("\Cinema cadastrado!\n");
    }

    void AdicionarNovoCinema(Cinema cinem){
		for(int i=0;i<size;i++)
		{
		if(todosCinemas[i].getnome()==""){
			todosCinemas[i].setDetails(cinem.getid(),cinem.getnome(),cinem.getshopping(), cinem.getsala());
			return;
		}
		}
    }

    void ExcluirUmCinema(){
			int cinem=getInteger("Digite o ID \n");
			Excluir(cinem);
			print("Cinema excluido com sucesso!\n");

		}

  exit(1);
}
