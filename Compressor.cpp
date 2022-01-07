#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<array>
#include<map>

using namespace std;

class Compressor {
private:
  map<int, char> TranslateTable = {
    {13, 'A'},
    {14, 'B'},
    {15, 'C'},
    {16, 'D'},
    {17, 'E'},
    {18, 'F'},
    {19, 'G'},
    {20, 'H'},
    {21, 'I'},
    {22, 'J'},
    {23, 'K'},
    {24, 'L'},
    {25, 'M'},
    {26, 'N'},
    {27, 'O'},
    {28, 'P'},
  };

  // Atributos da Compactação

  ifstream arqInicial;
  ofstream arqCompactado;
  string line;

  // Atributos da Descompactação

  ifstream arqCompactadoLeitura;
  ofstream arqDescompactado;
  string lineComp;
  array<int, 4> numBinary = {0, 0, 0, 0};
  int key = -1;
  int aux = 1, aux2; // Auxiliar na interface

  // Métodos

  int binaryToDecimal(int numberBinary) {
    int numberDecimal = 0;
    int base = 1;

    int temp = numberBinary;
    while (temp) {
      int lastDigit = temp % 10;
      temp = temp / 10;

      numberDecimal += lastDigit * base;

      base = base * 2;
    }

    return numberDecimal;
  }

  array<int, 4> decimalToBinary(int numberDecimal, array<int, 4> arr) {
    int handleNumber;

    handleNumber = numberDecimal;

    int i = 4;
    while (numberDecimal > 0) {
      i--;
      arr[i] = numberDecimal % 2;
      numberDecimal = numberDecimal / 2;
    }

    while (i != 0) {
      i--;
      arr[i] = 0;
    }

    return arr;
  };

  void interfaceCompactar(string binario, int decimal, char simbolo){
    if (aux==1){
      cout << endl << "*** Processo de compactacao ***" << endl << endl;
      aux = 0;
    }
    if (aux2==1){
      cout << "Vetor lido: " << line << endl;
    }
    cout << "   Sequencia identificada: " << binario << endl;
    cout << "   Numero correspondente em decimal: " << decimal << endl;
    cout << "   Simbolo correspondente: " << simbolo << endl;
    cout << endl;
  };

  void interfaceDescompactar(string sequencia, string simbolo){
    if (aux==1){
      cout << endl << "*** Processo de descompactacao ***" << endl << endl;
      aux = 0;
    }
    cout << "Simbolo lido: " << simbolo << endl;
    cout << "   Sequencia correspondente: " << sequencia << endl;
    cout << endl;
  };
public:
  bool compactar(string arq) {
    arqInicial.open(arq);
    int len = arq.size() - 4;
    string arqComp = arq.substr(0, len) + "Compactado.txt";
    arqCompactado.open(arqComp);

    if(arqInicial.is_open()) {
      while(getline(arqInicial, line)) {
        if(line.empty()) break;
        aux2 = 1;
        for(int i = 0; i < line.length(); i++) {
          int init = 4 * i;
          if(init >= line.length()) break;

          string subString = line.substr(4*i, 4);

          if(subString.length() == 4) {
            int strToNumberBy = stoi(subString);

            int numberByToDec = binaryToDecimal(strToNumberBy);
            char letter = TranslateTable[numberByToDec + 13];

            interfaceCompactar(subString, numberByToDec, letter);
            aux2 = 0;
            arqCompactado << letter;
          } else {
            arqCompactado << subString;
          }
        }
        arqCompactado << "\n";
      }
    } else {
      return false;
    }

    arqInicial.close();
    arqCompactado.close();

    return true;
  };

  bool descompactar(string arq) {
    int len = arq.size() - 4;
    string arqComp = arq.substr(0, len) + "Compactado.txt";
    string arqDesc = arq.substr(0, len) + "Descompactado.txt";
    arqCompactadoLeitura.open(arqComp);
    arqDescompactado.open(arqDesc);
    aux = 1; //Auxiliar da interface com usuário
    if(arqCompactadoLeitura.is_open()) {
      while(getline(arqCompactadoLeitura, lineComp)) {
        for(int i = 0; i < lineComp.length(); i++) {
          string subStringDesc = lineComp.substr(i, 1); //Lê um elemento por vez do arquivo compactado
          stringstream ss;
          for (auto &i : TranslateTable) {
            if (i.second == subStringDesc[0]) {
              key = i.first;
              break; // to stop searching
            } else if (subStringDesc[0] != '1' && subStringDesc[0] != '0') {
              key = 0;
            } else {
              key = -1;
            }
          }
          int charToNumber = key - 13;
          if(charToNumber < 0) {
            if (charToNumber == -13) continue;
            stringstream transform(subStringDesc);
            transform >> charToNumber;
            arqDescompactado << charToNumber;
            continue;
          }

          array<int, 4> result = decimalToBinary(charToNumber, numBinary);

          for(int i : result)
            ss << i;

          string resultado;
          ss >> resultado;

          interfaceDescompactar(resultado, subStringDesc);

          arqDescompactado << resultado;
        }
        arqDescompactado << "\n";
      }
    } else {
      return false;
    }

    arqCompactadoLeitura.close();
    arqDescompactado.close();

    return true;
  };
};

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
