#include"Compressor.hpp"
using namespace std;

int main() {
  Compressor cmp;
  string arquivo;

  cout << "Digite o nome do arquivo que vai ser compactado: " << endl;
  cin >> arquivo;

  if(cmp.compactar(arquivo)) {
    cout << "Arquivo compactado com sucesso!" << endl;
  } else {
    cout << "Erro ao compactar" << endl;
  }

  if(cmp.descompactar(arquivo)) {
    cout << "Arquivo descompactado com sucesso!" << endl;
  } else {
    cout << "Erro ao descompactar" << endl;
  }

  return 0;
}