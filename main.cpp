#include"Compressor.hpp"
using namespace std;

int main() {
  Compressor cmp;
  Interface interface;
  string arquivoCmp, arquivoDmp;
  bool loop = true;
  
  while(loop) {
    int menuOp = interface.menu();
    if (menuOp == 3) break;

    switch (menuOp) {
      case 1:
        cout << "  Digite o nome do arquivo que vai ser compactado: ";
        cin >> arquivoCmp;

        if(cmp.compactar(arquivoCmp)) {
          cout << "  -> Arquivo compactado com sucesso!" << endl;
        } else {
          cout << "  -> Erro ao compactar" << endl;
        }

        break;
      case 2:
        cout << "  Digite o nome do arquivo que vai ser descompactado: ";
        cin >> arquivoDmp;

        if(cmp.descompactar(arquivoDmp)) {
          cout << "  -> Arquivo descompactado com sucesso!" << endl;
        } else {
          cout << "  -> Erro ao descompactar" << endl;
        }
        break;
      default:
        break;
    }
  }

  return 0;
}