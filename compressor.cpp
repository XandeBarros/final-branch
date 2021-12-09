#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main() {
  ifstream arq;
  string line;
  arq.open("test.txt");

  if(arq.is_open()) {
    int lines = 0;
    while(getline(arq, line)) {
      lines++;
    }
    


    arq.close();
  } else {
    cout << "xD deu errado!" << endl;
  }

  return 0;
}