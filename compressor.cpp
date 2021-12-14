#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<array>
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
          char letter = (char)(numberByToDec + 65);

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
        int charToNumber = (int)subStringDesc[0] - 65;
        if(charToNumber < 0) {
          if (charToNumber == -52) continue;
          stringstream transform(subStringDesc);
          transform >> charToNumber;
          arqDescompactado << charToNumber;
          continue;
        }
        
        // arqDescompactado << subStringDesc << " | " << charToNumber << " -> ";
        array<int, 4> result = decimalToBinary(charToNumber, numBinary);
        
        for(int i : result)
          ss << i;
        
        string resultado;
        ss >> resultado;
        arqDescompactado << resultado;
      }
      // cout << "Linha: " << lines << " Text: " << lineComp << endl;
      arqDescompactado << "\n";
    }
  } else {
    cout << "Deu moios." << endl;
  }

  arqCompactadoLeitura.close();
  arqDescompactado.close();
  
  return 0;
}