#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<array>
#include<map>
#include"Interface.hpp"

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

  // Interface

  Interface interface;

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

  // Métodos Privados

  int binaryToDecimal(int numberBinary);
  array<int, 4> decimalToBinary(int numberDecimal, array<int, 4> arr);
public:
  bool compactar(string arq);
  bool descompactar(string arq);
};
