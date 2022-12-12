#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include "cinema.h"
using namespace std;

// Char para repetição
char continuar = 'S';

// Arquivos para leitura/escrita
const char *arq = "cinemas.dat";
ifstream iffile;
ofstream offile;

// Declarações dos métodos
void post();
void readAll();
void update();
void deleteOne();
void readOne();

// Verifica se o arquivo está vazio
int get_size(const char *file_name)
{
	FILE *file = fopen(file_name, "r");

	if (file == NULL)
		return 0;

	fseek(file, 0, SEEK_END);
	int size = ftell(file);
	fclose(file);

	return size;
}

void update()
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
		FILE *arquivo = fopen(arq, "r+b");
		iffile.open("cinemas.dat", ios::binary | ios::in);

		// Declaração de variáveis
		int id, linha;
		Cinema cinema;
		string nome, sala, shopping;

		cout << "\nDigite o [ID] do cinema que queira editar: ";
		cin >> id;

		// Contador de linha
		linha = 0;
		// Char para verificar se encontrou ou não o registro
		char encontrou = 'F';

		// Lê o arquivo até achar o registro
		while (iffile.read((char *)&cinema, sizeof(cinema)) && encontrou == 'F')
		{
			if (id == linha)
			{
				encontrou = 'S';
			}
			linha += 1;
		}

		// Se não achou, atualizamos o usuário e fechamos os arquivos
		if (encontrou == 'F')
		{
			iffile.close();
			fclose(arquivo);
			cout << "\n [CINEMA NAO ENCONTRADO!] \n";
		}

		// Se achou, continuamos o processo
		else 
		{
			// Fechamos o arquivo que foi utilizado para procurar o registro
			iffile.close();
			// Colocamos o ponteiro no id que o usuário escreveu
			fseek(arquivo, id * sizeof(Cinema), SEEK_SET);

			system("clear||cls");
			fflush(stdin);

			// Pegamos as informações
			cout << "Digite o [NOME] do [CINEMA]: ";
			getline(cin, nome);
			strcpy(cinema.nome, nome.c_str());

			cout << "Digite o [NOME] do [SHOPPING]: ";
			getline(cin, shopping);
			strcpy(cinema.shopping, shopping.c_str());

			cout << "Digite a [SALA] do cinema: ";
			cin >> cinema.qtsSalas;

			cin.ignore();

			// Verifica se as string's estão no tamanho correto
			if (nome.length() < 15 && shopping.length() < 30)
			{
				fwrite(&cinema, sizeof(Cinema), 1, arquivo);
			}
			else
			{
				cout << "\n>> DIGITE CORRETAMENTE NOS PADROES! <<\n";
			}

			// Fecha o arquivo escrito e mostra os registros
			fclose(arquivo);
			readAll();
		}
	}

}

void post()
{
	system("clear||cls");
	char continuar;
	FILE *arquivo = fopen(arq, "ab");
	Cinema cinema;
	string nome, sala, shopping;

	do
	{
		system("clear||cls");
		fflush(stdin);

		// Pegando informações
		cout << "Digite o [NOME] do [CINEMA]: ";
		getline(cin, nome);
		strcpy(cinema.getNome(), nome.c_str());

		cout << "Digite o [NOME] do [SHOPPING]: ";
		getline(cin, shopping);
		strcpy(cinema.shopping, shopping.c_str());

		cout << "Digite a [SALA]: ";
		cin >> cinema.qtsSalas;

		cin.ignore();

		// Verifica se as string's estão no tamanho correto
		if (nome.length() < 15 && shopping.length() < 30)
		{
			fwrite(&cinema, sizeof(Cinema), 1, arquivo);
		}
		else
		{
			cout << "\n>> DIGITE CORRETAMENTE NOS PADROES! <<\n";
		}

		// Looping para caso o usuário deseje continuar adicionando cinemas
		cout << "\nDeseja continuar adicionando? (S/N): ";
		cin >> continuar;
	} while (toupper(continuar) == 'S');

	fclose(arquivo);
}

void readOne()
{
	// Abre o arquivo
	iffile.open("cinemas.dat", ios::binary | ios::in);

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
		Cinema cinema;

		// O usuário digita o ID do cinema que ele gostaria de ver
		cout << "\nColoque o [ID] do cinema que queira encontrar: ";
		cin >> id;
		linha = 0;
		char encontrou = 'F';

		// Percorre o arquivo, em busca do ID digitado
		while (iffile.read((char *)&cinema, sizeof(cinema)) && encontrou == 'F')
		{
			// Se for encontrado, escrevemos na tela
			if (id == linha)
			{
				cout << '\n';
				cout << id << " " << cinema.nome << " " << cinema.shopping << " " << cinema.qtsSalas << endl;
				cout << '\n';
				encontrou = 'S';
			}
			linha += 1;
		}

		// Se não, avisamos o usuário
		if (encontrou == 'F')
		{
			cout << "\n [CINEMA NAO ENCONTRADO!] \n";
		}
	}

	iffile.close();
}

void readAll()
{
	// Verifica se tem algo no arquivo
	if (get_size("cinemas.dat") == 0)
	{
		cout << "\n[NAO HA NENHUM REGISTRO NO ARQUIVO!]\n";
	}

	// Se tiver
	else
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
		cout << "CODIGO"
			 << " | "
			 << "NOME DO CINEMA"
			 << " | "
			 << "NOME DO SHOPPING"
			 << " | "
			 << "SALA\n"
			 << endl;
			 
		// Looping para ler todos os registros
		do
		{
			cout << id << " " << cinema.nome << " " << cinema.shopping << " " << cinema.qtsSalas << endl;

			fread(&cinema, sizeof(Cinema), 1, arquivo);
			id += 1;
		} while (feof(arquivo) == 0);
		fclose(arquivo);
		cout << endl;
	}
}

void deleteOne()
{
	iffile.open("cinemas.dat", ios::binary | ios::in);
	offile.open("temp.dat", ios::binary | ios::out);

	// Se não conseguirem abrir os arquivo
	if (!iffile || !offile)
	{
		cout << "O arquivo nao pode ser aberto!";
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
			int id, linha;
			Cinema cinema;
			cout << "\nColoque o [ID] do cinema que queira deletar: ";
			cin >> id;
			linha = 0;

			// Reescrevemos o arquivo sem aquela linha
			while (iffile.read((char *)&cinema, sizeof(cinema)))
			{
				if (id != linha)
				{
					offile.write((char *)&cinema, sizeof(cinema));
				}
				linha += 1;
			}

			// Fechamos os dois arquivos, o original e o auxiliar
			iffile.close();
			offile.close();

			// Trocamos o arquivo temporário, e o renomeamos para o nome original
			remove("cinemas.dat");
			rename("temp.dat", "cinemas.dat");
		}
	}
}
