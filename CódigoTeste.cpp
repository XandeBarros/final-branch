#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

class winrar{
    private:
        // Definição das variáveis
        ifstream arq1;           // Arquivo que armazena os bits fornecidos
        fstream arq2;           // Arquivo compactado
        ofstream arq3;         // Arquivo descompactado
        char simbolo[5]={0};
        char line[17] =""; // linha a ser lida
        int contador, i=0;
//                                            Dicionário de símbolos
        char *A = "0000";
        char *B = "0001";
        char *C = "0010";
        char *D = "0011";
        char *E = "0100";
        char *F = "0101";
        char *G = "0110";
        char *H = "0111";
        char *I = "1000";
        char *J = "1001";
        char *K = "1010";
        char *L = "1011";
        char *M = "1100";
        char *N = "1101";
        char *O = "1110";
        char *P = "1111";
    public:
        //definição das funções da classe:
        void leitura();
        void sequencia();
        void compactar();

}obj1;

void winrar::leitura(){
//   Abrindo arquivo com Banco de Dados
    arq1.open("BancoDados.txt");
//   Abrindo arquivo compactado
    arq2.open("Compactado.txt", ios::out);
//   Abrindo arquivo descompactado
    arq3.open("Compactado1.txt");
    if(arq1.is_open()) {
        /*
        while(arq1){
            arq1.read(line, 16);
            cout << "Vetor "<< contador << " lido: " << line  << endl;
            contador +=1;
        };
        */
        //Só pega se tiver 16 elementos, com menos ele ignora
        while (arq1.read(line, 16)){
            cout << "Vetor "<< contador + 1 << " lido: " << line  << endl;
            contador +=1;
            sequencia();
       }
    arq1.close();
    arq2.close();
    arq3.close();
  } else {
    cout << "Deu ruim" << endl;
  }
}

void winrar::sequencia(){
    cout << "****COMPACTACAO****"<< endl;
    memcpy(simbolo, &line[0], 4);
    cout << "Simbolo1: "<< simbolo << endl;
    compactar();
    memcpy(simbolo, &line[4], 4);
    cout << "Simbolo2: "<< simbolo<< endl;
    compactar();
    memcpy(simbolo, &line[8], 4);
    cout << "Simbolo3: "<< simbolo<< endl;
    compactar();
    memcpy(simbolo, &line[12], 4);
    cout << "Simbolo4: "<< simbolo<< endl;
    compactar();
    cout << endl;
}


void winrar::compactar(){
    if (strcmp(simbolo, A)==0){
        cout << "eh igual A" << endl;
        arq2 << A;
     }
     if (strcmp(simbolo, B)==0){
        cout << "eh igual B" << endl;
        arq2 << B;
        }
     if (strcmp(simbolo, C)==0){
        cout << "eh igual C" << endl;
        arq2 << C;
     }
     if (strcmp(simbolo, D)==0){
         cout << "eh igual D" << endl;
         arq2 << D;
     }
     if (strcmp(simbolo, E)==0){
         cout << "eh igual E " << endl;
         arq2 << E;
     }
     if (strcmp(simbolo, F)==0){
        cout << "eh igual F" << endl;
         arq2 << F;
      }
      if (strcmp(simbolo, G)==0){
         cout << "eh igual G" << endl;
         arq2 << G;
      }
      if (strcmp(simbolo, H)==0){
          cout << "eh igual H" << endl;
          arq2 << H;
       }
       if (strcmp(simbolo, I)==0){
           cout << "eh igual I" << endl;
           arq2 << I;
        }
        if (strcmp(simbolo, J)==0){
            cout << "eh igual J";
            arq2 << J;
        }
        if (strcmp(simbolo, K)==0){
            cout << "eh igual K" << endl;
            arq2 << K;
        }
        if (strcmp(simbolo, L)==0){
            cout << "eh igual L" << endl;
            arq2 <<L;
         }
         if (strcmp(simbolo, M)==0){
             cout << "eh igual M" << endl;
             arq2 << M;
         }
         if (strcmp(simbolo, N)==0){
             cout << "eh igual N" << endl;
             arq2 << N;
         }
         if (strcmp(simbolo, O)==0){
              cout << "eh igual O" << endl;
              arq2 << O;
         }
         if (strcmp(simbolo, P)==0){
              cout << "eh igual P" << endl;
              arq2 << P;
         }
}


int main() {
  obj1.leitura();
  return 0;
}

/*
ofstream -> informação saindo do programa e entrando no arquivo
fstream -> informação saindo do arquivo e entrando no programa
fsteam -> pode ser configurado como um ou outro

Exemplo:

ofstream arquivo;

arquivo.open("teste.txt", ios::app); // abre um arquivo novo, neste caso com o ios::app ele mantem o texto já escrito anteriormente no arquivo

arquivo << "simbolo"; // passa o texto para o aquivo

arquivo.close(); // libera memória



  char A[4] = '0000';      // 0000
  char B;     // 0001
  char C;      // 0010
  char D;     // 0011
  char E;      // 0100
  char F;     // 0101
  char G;      // 0110
  char H;     // 0111
  char I;      // 1000
  char J;      // 1001
  char K;      // 1010
  char L;     // 1011
  char M;      // 1100
  char N;     // 1101
  char O;      // 1110
  char P;     // 1111



*/
