#include <iostream>
#include <string.h>
#include <fstream>
#include "cinema.h"
using namespace std;

char continuar = 'S';
const char *arq = "cinemas.dat";
ifstream file;

void menu();
void post();
void readAll();
void update();
void deleteOne();
void readOne();

void menu()
{
	int opcao;

	do
	{
		system("clear||cls");
		std::cout << "=-=-=- C.R.U.D DE CINEMAS =-=-=-\n\n";
		std::cout << "[1] - Exibir um cinema\n";
		std::cout << "[2] - Exibir varios cinemas\n";
		std::cout << "[3] - Adicionar um cinema\n";
		std::cout << "[4] - Excluir um cinema\n";
		std::cout << "[5] - Editar um cinema\n";
		std::cout << "[0] - Sair do programa\n\n";

		cout << "Digite uma opcao... ";
		cin >> opcao;

		switch (opcao)
		{
		case 1:
			readOne();
			break;
		case 2:
			readAll();
			break;
		case 3:
			post();
			break;
		case 4:
			deleteOne();
			break;
		case 5:
			update();
			break;
		}

		cout << "Deseja continuar? (S/N) ";
		cin >> continuar;
	} while (toupper(continuar) == 'S');
}

void update()
{
	FILE *arquivo = fopen(arq, "r+b");
	int id;
	Cinema cinema;
	string nome, sala, shopping;

	cout << "\nDigite o [ID] do cinema que queira editar:";
	cin >> id;

	fseek(arquivo, id * sizeof(Cinema), SEEK_SET);
	cout << "Digite o [ID] do cinema: ";
	cin >> cinema.id;
	cin.ignore();
	cout << "Digite o [NOME] do [CINEMA]: ";
	getline(cin, nome);
	strcpy(cinema.nome, nome.c_str());
	cout << "Digite o [NOME] do [SHOPPING]: ";
	getline(cin, shopping);
	strcpy(cinema.shopping, shopping.c_str());
	cout << "Digite a [SALA] do cinema: ";
	cin >> cinema.qtsSalas;
	cin.ignore();

	fwrite(&cinema, sizeof(Cinema), 1, arquivo);
	fclose(arquivo);
	readAll();
}

void post()
{
	char continuar;
	FILE *arquivo = fopen(arq, "ab");
	Cinema cinema;
	string nome, sala, shopping;

	do
	{
		fflush(stdin);
		// cout << "\nDigite o [ID]: ";
		// cin >> cinema.id;
		// cin.ignore();
		cout << "Digite o [NOME] do [CINEMA]: ";
		getline(cin, nome);
		strcpy(cinema.nome, nome.c_str());
		cout << "Digite o [NOME] do [SHOPPING]: ";
		getline(cin, shopping);
		strcpy(cinema.shopping, shopping.c_str());
		cout << "Digite a [SALA]: ";
		cin >> cinema.qtsSalas;
		cin.ignore();

		fwrite(&cinema, sizeof(Cinema), 1, arquivo);

		cout << "Deseja continuar adicionando? (S/N): ";
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

	int id = 0;
	Cinema cinema;
	cout << "\nColoque o [ID] do cinema que queira ler: ";
	cin >> id;

	//if (isdigit(id)){
		fseek(arquivo, id * sizeof(Cinema), SEEK_SET);
		fread(&cinema, sizeof(Cinema), 1, arquivo);
		cout << "\n";
		cout << id << " " << cinema.id << " " << cinema.nome << " " << cinema.shopping << " " << cinema.qtsSalas << endl;
	// }
	// else{
	// 	cout << "IIIIIIIIIIIIIh";
	// }

	fclose(arquivo);
}

void readAll()
{
	FILE *arquivo = fopen(arq, "rb");

	if (!arquivo)
	{
		arquivo = fopen(arq, "w+b");
	}

	int id = 0;
	Cinema cinema;
	system("clear||cls");
	fread(&cinema, sizeof(Cinema), 1, arquivo);

	cout << ".: Leitura de [CINEMAS] :. \n\n";
	cout << "CODIGO" /*<<" | "<<"ID"*/ << " | "
		 << "NOME DO CINEMA"
		 << " | "
		 << "NOME DO SHOPPING"
		 << " | "
		 << "SALA\n"
		 << endl;
	do
	{
		if (cinema.qtsSalas != -1)
		{
			cout << id /*<<" "<<cinema.id*/ << " " << cinema.nome << " " << cinema.shopping << " " << cinema.qtsSalas << endl;
		}
		fread(&cinema, sizeof(Cinema), 1, arquivo);
		id += 1;
	} while (feof(arquivo) == 0);
	fclose(arquivo);
	cout << endl;
}

void deleteOne()
{
	FILE *arquivo = fopen(arq, "r+b");
	readAll();
	// file.open("cinemas.dat", std::ios::app | std::ios::binary);

	// if(!file.is_open())
	// {
	// 	cout << "\nArquivo nao encontrado!";
	// }
	// else{
	// 	int id;
	// 	Cinema cinema;
	// 	cout<<"Coloque o [ID] do cinema que queira deletar: ";
	// 	cin>>id;
	// 	file.remove(id.c_str());
	// }

	if (!arquivo)
	{
		arquivo = fopen(arq, "tempt");
	}

	int id;
	Cinema cinema;
	cout << "Coloque o [ID] do cinema que queira deletar: ";
	cin >> id;
	if (isdigit(id)){
		cout << "\n[Digite corretamente um ID!]\n";
		fclose(arquivo);
	}
	else{
		fseek(arquivo, id * sizeof(Cinema), SEEK_SET);
		fwrite(&cinema, sizeof(Cinema), 1, arquivo);
		fclose(arquivo);
		remove("r+b");
		rename("tempt", "r+b");
	}
}