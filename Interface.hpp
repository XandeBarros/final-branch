#include<iostream>
using namespace std;

class Interface {
public: 
  int menu();
  void interfaceCompactar(string binario, int decimal, char simbolo, string line, int inicioLoop, int vetor);
  void interfaceDescompactar(string sequencia, string simbolo, int inicioLoop);
};