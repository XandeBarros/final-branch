#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<array>
#include<map>
using namespace std;

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
}

int main() {
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

  ifstream arq;
  ofstream arqCompactado;
  string line;
  arq.open("BancoDados.txt");
  arqCompactado.open("compText.txt");

  // Compacta o Arquivo ;)
  if(arq.is_open()) {
    while(getline(arq, line)) {
      if(line.empty()) break;
      for(int i = 0; i < line.length(); i++) {
        int init = 4 * i;
        if(init >= line.length()) break;

        string subString = line.substr(4*i, 4);

        if(subString.length() == 4) {
          int strToNumberBy = stoi(subString);

          int numberByToDec = binaryToDecimal(strToNumberBy);
          char letter = TranslateTable[numberByToDec + 13];

          arqCompactado << letter;
        } else {
          arqCompactado << subString;
        }
      }
      arqCompactado << "\n";
    }
  } else {
    cout << "xD deu errado!" << endl;
  }

  arq.close();
  arqCompactado.close();

  // Descompactar
  int key = -1;
  ifstream arqCompactadoLeitura;
  ofstream arqDescompactado;
  string lineComp;
  array<int, 4> numBinary = {0, 0, 0, 0};

  arqCompactadoLeitura.open("compText.txt");
  arqDescompactado.open("descompText.txt");

  if(arqCompactadoLeitura.is_open()) {
    int lines = 0;
    while(getline(arqCompactadoLeitura, lineComp)) {
      lines++;
      for(int i = 0; i < lineComp.length(); i++) {
        string subStringDesc = lineComp.substr(i, 1);
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
        cout << charToNumber << endl;
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
        arqDescompactado << resultado;
      }
      arqDescompactado << "\n";
    }
  } else {
    cout << "Deu moios." << endl;
  }

  arqCompactadoLeitura.close();
  arqDescompactado.close();
  
  return 0;
}