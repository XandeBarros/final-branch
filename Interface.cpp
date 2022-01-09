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

void Interface::interfaceCompactar(string binario, int decimal, char simbolo, string line, int inicioLoop, int vetor) {
  if (!inicioLoop) {
    cout << endl << "#*#*#* Processo de Compactacao *#*#*#" << endl << endl;
  } 

  if (!vetor) {
    cout << "  -> Vetor lido: " << line << endl;
  }

  cout << "    -> Sequencia identificada: " << binario << endl;
  cout << "    -> Numero correspondente em decimal: " << decimal << endl;
  cout << "    -> Simbolo correspondente: " << simbolo << endl;
  cout << endl;
  
};

void Interface::interfaceDescompactar(string sequencia, string simbolo, int inicioLoop) {
  if (!inicioLoop){
    cout << endl << "*** Processo de Descompactacao ***" << endl << endl;
  }
  cout << "  -> Simbolo lido: " << simbolo << endl;
  cout << "    -> Sequencia correspondente: " << sequencia << endl;
  cout << endl;
};