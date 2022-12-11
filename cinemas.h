#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include "cinema.h"
using namespace std;

char continuar = 'S';
const char *arq = "cinemas.dat";
ifstream iffile;
ofstream offile;

void menu();
void post();
void readAll();
void update();
void deleteOne();
void readOne();

// void menu()
// {
// 	int opcao;

// 	do
// 	{
// 		system("clear||cls");
// 		std::cout << "=-=-=- C.R.U.D DE CINEMAS =-=-=-\n\n";
// 		std::cout << "[1] - Exibir um cinema\n";
// 		std::cout << "[2] - Exibir varios cinemas\n";
// 		std::cout << "[3] - Adicionar um cinema\n";
// 		std::cout << "[4] - Excluir um cinema\n";
// 		std::cout << "[5] - Editar um cinema\n";
// 		std::cout << "[0] - Sair do programa\n\n";

// 		cout << "Digite uma opcao... ";
// 		cin >> opcao;

// 		switch (opcao)
// 		{
// 		default:
// 			cout << "\nDigite corretamente uma opcao!\n";
// 			break;
// 		case 1:
// 			readOne();
// 			break;
// 		case 2:
// 			readAll();
// 			break;
// 		case 3:
// 			post();
// 			break;
// 		case 4:
// 			deleteOne();
// 			break;
// 		case 5:
// 			update();
// 			break;
// 		}

// 		cout << "Deseja continuar? (S/N) ";
// 		cin >> continuar;
// 	} while (toupper(continuar) == 'S');
// }

void update()
{
	FILE *arquivo = fopen(arq, "r+b");
	int id;
	Cinema cinema;
	string nome, sala, shopping;

	cout << "\nDigite o [ID] do cinema que queira editar:";
	cin >> id;

	fseek(arquivo, id * sizeof(Cinema), SEEK_SET);
	cout << "Digite o [NOME] do [CINEMA]: ";
	getline(cin, nome);
	strcpy(cinema.nome, nome.c_str());

	cout << "Digite o [NOME] do [SHOPPING]: ";
	getline(cin, shopping);
	strcpy(cinema.shopping, shopping.c_str());
	
	cout << "Digite a [SALA] do cinema: ";
	cin >> cinema.qtsSalas;

	cin.ignore();

	if (nome.length() < 15 && shopping.length() < 30)
	{
		fwrite(&cinema, sizeof(Cinema), 1, arquivo);
	}
	else
	{
		cout << "\n>> DIGITE CORRETAMENTE NOS PADROES! <<\n";
	}

	fclose(arquivo);
	readAll();
}

void post()
{
	system("clear||cls");
	char continuar;
	FILE *arquivo = fopen(arq, "ab");
	Cinema cinema;
	string nome, sala, shopping;
	char id;

	do
	{
		system("clear||cls");
		fflush(stdin);

		cout << "Digite o [NOME] do [CINEMA]: ";
		getline(cin, nome);
		strcpy(cinema.getNome(), nome.c_str());

		cout << "Digite o [NOME] do [SHOPPING]: ";
		getline(cin, shopping);
		strcpy(cinema.shopping, shopping.c_str());

		cout << "Digite a [SALA]: ";
		cin >> cinema.qtsSalas;

		cin.ignore();

		if (nome.length() < 15 && shopping.length() < 30)
		{
			fwrite(&cinema, sizeof(Cinema), 1, arquivo);
		}
		else
		{
			cout << "\n>> DIGITE CORRETAMENTE NOS PADROES! <<\n";
		}

		cout << "\nDeseja continuar adicionando? (S/N): ";
		cin >> continuar;
	} while (toupper(continuar) == 'S');

	fclose(arquivo);
}

void readOne()
{
	FILE *arquivo = fopen(arq, "rb");

	if (!arquivo)
	{
		arquivo = fopen(arq, "w+b");
	}

	int id;
	Cinema cinema;
	cout << "\nColoque o [ID] do cinema que queira ler: ";
	cin >> id;

	fseek(arquivo, id * sizeof(Cinema), SEEK_SET);
	fread(&cinema, sizeof(Cinema), 1, arquivo);
	cout << "\n";
	cout << "[CINEMA ENCONTRADO] :.    " << id << " " << cinema.nome << " " << cinema.shopping << " " << cinema.qtsSalas << endl;

	fclose(arquivo);
}

int get_size(const char* file_name)
{
	FILE *file = fopen(file_name, "r");

	if(file == NULL)
		return 0;

	fseek(file, 0, SEEK_END);
	int size = ftell(file);
	fclose(file);

	return size;
}

void readAll()
{
	FILE *arquivo = fopen(arq, "rb");

	if (!arquivo)
	{
		arquivo = fopen(arq, "w+b");
	}

	if(get_size("cinemas.dat") == 0)
	{
		cout << "vaziozao";
	}

	else{
		cout << "tem coiso";
	}

	int id = 0;
	Cinema cinema;
	system("clear||cls");
	fread(&cinema, sizeof(Cinema), 1, arquivo);

	cout << ".: Leitura de [CINEMAS] :. \n\n";
	cout << "CODIGO" << " | "
		 << "NOME DO CINEMA"
		 << " | "
		 << "NOME DO SHOPPING"
		 << " | "
		 << "SALA\n"
		 << endl;
	do
	{
		// if (cinema.qtsSalas != -1)
		//{
		cout << id /*<<" "<<cinema.id*/ << " " << cinema.nome << " " << cinema.shopping << " " << cinema.qtsSalas << endl;
		//}
		fread(&cinema, sizeof(Cinema), 1, arquivo);
		id += 1;
	} while (feof(arquivo) == 0);
	fclose(arquivo);
	cout << endl;
}

void deleteOne()
{
	iffile.open("cinemas.dat", ios::binary | ios::in);
	offile.open("temp.dat", ios::binary | ios::out);

	if (!offile || !offile)
	{
		cout << "O arquivo nao pode ser aberto!";
	}
	else
	{
		int id, linha;
		Cinema cinema;
		cout << "Coloque o [ID] do cinema que queira deletar: ";
		cin >> id;
		linha = 0;

		while (iffile.read((char *)&cinema, sizeof(cinema)))
		{
			if (id != linha)
			{
				offile.write((char *)&cinema, sizeof(cinema));
			}
			linha += 1;
		}
		iffile.close();
		offile.close();
		remove("cinemas.dat");
		rename("temp.dat", "cinemas.dat");
	}

	// FILE *arquivo = fopen(arq, "r+b");
	// readAll();

	// if (!arquivo)
	// {
	// 	arquivo = fopen(arq, "tempt");
	// }

	// int id;
	// Cinema cinema;
	// cout << "Coloque o [ID] do cinema que queira deletar: ";
	// cin >> id;
	// if (isdigit(id)){
	// 	cout << "\n[Digite corretamente um ID!]\n";
	// 	fclose(arquivo);
	// }
	// else{
	// 	fseek(arquivo, id * sizeof(Cinema), SEEK_SET);
	// 	fwrite(&cinema, sizeof(Cinema), 1, arquivo);
	// 	fclose(arquivo);
	// 	remove("r+b");
	// 	rename("tempt", "r+b");
	// }

}

