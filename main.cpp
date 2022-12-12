#include "cinemas.h"
#include <stdio.h>
#include <string>
using namespace std;

/**
 * @author Nicoli (21689) e Danyelle (21232)
 * CRUD EM ARQUIVO BINÁRIO - CINEMAS
 * Professor: Maligno
 */

int main() {
  char opcao;
  char sair = 'N';
  Cinemas cinemas;

  do {
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

    switch (opcao) {
    default:
      cout << "\nDigite corretamente uma opcao!\n";
      break;
    case '0':
      sair = 'S';
      break;
    case '1':
      cinemas.readOne();
      break;
    case '2':
      cinemas.readAll();
      break;
    case '3':
      cinemas.post();
      break;
    case '4':
      cinemas.deleteOne();
      break;
    case '5':
      cinemas.update();
      break;
    }

    if (sair == 'N') {
      cout << "\nDeseja continuar? (S/N) ";
      cin >> cinemas.continuar;
    }
  } while (toupper(cinemas.continuar) == 'S' && sair == 'N');
}