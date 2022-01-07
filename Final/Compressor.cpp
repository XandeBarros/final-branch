#include"Compressor.hpp"

using namespace std;

int Compressor::binaryToDecimal(int numberBinary) {
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

array<int, 4> Compressor::decimalToBinary(int numberDecimal, array<int, 4> arr) {
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

void Compressor::interfaceCompactar(string binario, int decimal, char simbolo) {
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

void Compressor::interfaceDescompactar(string sequencia, string simbolo) {
  if (aux==1){
    cout << endl << "*** Processo de descompactacao ***" << endl << endl;
    aux = 0;
  }
  cout << "Simbolo lido: " << simbolo << endl;
  cout << "   Sequencia correspondente: " << sequencia << endl;
  cout << endl;
};

bool Compressor::compactar(string arq) {
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

bool Compressor::descompactar(string arq) {
  int len = arq.size() - 4;
    string arqComp = arq.substr(0, len) + "Compactado.txt";
    string arqDesc = arq.substr(0, len) + "Descompactado.txt";
    arqCompactadoLeitura.open(arqComp);
    arqDescompactado.open(arqDesc);
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