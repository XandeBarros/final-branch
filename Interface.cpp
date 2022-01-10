#include"Interface.hpp"

using namespace std;

int Interface::menu() {
  int result;

  cout << "   _____ _____ _____ _____ " << endl;
  cout << "  |     |   __|   | |  |  |" << endl;
  cout << "  | | | |   __| | | |  |  |" << endl;
  cout << "  |_|_|_|_____|_|___|_____|" << endl;
                         
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

void Interface::interfaceInicio() {
  cout << "   _____ _____ _____    _____ _____ _____ ____  _____" << endl;
  cout << "  | __  |   __|     |  |  |  |     |   | |    \\|     |" << endl;
  cout << "  | __ -|   __| | | |  |  |  |-   -| | | |  |  |  |  |" << endl;
  cout << "  |_____|_____|_|_|_|   \\___/|_____|_|___|____/|_____|" << endl;                                                    
};

void Interface::interfaceFinal() {
  cout << "   _____  _____  _____ " << endl; 
  cout << "  |  |  ||   __||  _  |" << endl;
  cout << "  |  |  ||__   ||   __|" << endl;
  cout << "  |_____||_____||__|   " << endl;   

  cout << endl;
  cout << endl;

  cout << "   _____  _____  _____  ___  ___  ___  ___   " << endl;   
  cout << "  |   __||   __||     ||   ||  _|| . ||_  |  " << endl;  
  cout << "  |__   ||   __|| | | || | ||_  || . | _| |_ " << endl;
  cout << "  |_____||_____||_|_|_||___||___||___||_____|" << endl;

  cout << endl;
  cout << endl;

  system("pause");
};