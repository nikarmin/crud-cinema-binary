#include <iostream>
#include <string>
#include "cinemas.h"
using namespace std;

int main(){
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

        cout<<"Digite uma opcao... "; 
        cin>>opcao;

        switch(opcao){
            case 1:
				readOne();
            break;
            case 2:
				readAll ();
				cout<<"\n";
            break;
            case 3:
				post ();
				cout<<"\n";
            break;
            case 4:
				deleteOne();
            break;
            case 5:
				update ();
            break;
        }

			cout << "Deseja continuar? (S/N) ";
    		cin >> continuar;
	}
    while (toupper(continuar) == 'S');
}