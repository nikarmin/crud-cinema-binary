#include <iostream>
#include <string>
#include "cinemas.h"
using namespace std;

int main()
{
   char opcao;
   char sair = 'N';

   do
   {
      system("clear||cls");
      cout << "=-=-=- C.R.U.D DE CINEMAS =-=-=-\n\n";
      cout << "[1] - Exibir um cinema\n";
      cout << "[2] - Exibir varios cinemas\n";
      cout << "[3] - Adicionar um cinema\n";
      cout << "[4] - Excluir um cinema\n";
      cout << "[5] - Editar um cinema\n";
      cout << "[0] - Sair do programa\n\n";

      cout << "Digite uma opcao... ";
      cin >> opcao;

      switch (opcao)
      {
      default:
         cout << "\nDigite corretamente uma opcao!\n";
         sair = 'S';
         break;
      case '0':
         sair = 'S';
         break;
      case '1':
         readOne();
         break;
      case '2':
         readAll();
         break;
      case '3':
         post();
         break;
      case '4':
         deleteOne();
         break;
      case '5':
         update();
         break;
      }

      if (sair == 'N'){
         cout << "\nDeseja continuar? (S/N) ";
         cin >> continuar;
      }
   } while (toupper(continuar) == 'S' && sair == 'N');
}