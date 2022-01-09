#include"Interface.hpp"
using namespace std;

int Interface::menu() {
  int result;
  cout << endl << "*#*#*#*#*#*#*#*#*#*#*#*#*#*# Menu Principal #*#*#*#*#*#*#*#*#*#*#*#*#*#*" << endl;
  cout << endl << "  Escolha uma opcao do menu abaixo: " << endl << endl;

  cout << "  1) Comprimir" << endl;
  cout << "  2) Descomprimir" << endl;
  cout << "  3) Sair" << endl;
  cout << endl;
  cout << "  Opcao numero: ";
  cin >> result;

  return result;
}