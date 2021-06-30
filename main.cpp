#include <iostream>
#include <fstream>
using namespace std;

class no{
public:
  int valor;
  no* proximo;

  no(int elemento){
    this -> valor=elemento;
    this -> proximo=NULL;
  }

  void defProximo(no* end){
    proximo=end;
  }

  int obterValor(){
    return valor;
  }

  no* obterProximo(){
    return proximo;
  }
};

no* inicio;
no* fim;
class lista{
 public: 
  
  lista(){
    inicio=NULL;
    fim = NULL;
  }

  lista(int num){
    inicio = new no(num);
    fim = inicio;
  }

  virtual ~lista(){
    delete inicio;
  }

  bool seVazia(){
    return (inicio == NULL);
  }

  /*void imprimirElem(){
    cout << "Elementos da lista" << endl;
    no* i=inicio;
    if (seVazia()){
      cout << "lista sem elementos" << endl;
    }else{
      while (i){
        cout << i -> obterValor() << endl;
        i=i -> obterProximo();
      }
      cout << endl;
    }
  }*/

  void insereNoInicio(int valor){
    no* novo = new no(valor);

    if (seVazia()){
      inicio = novo;
      fim = novo;
    }else {
      novo -> defProximo(inicio);
      inicio = novo;
    }
  }

  void insereNoFim(int valor){
    no* novo = new no(valor);

    if (seVazia()){
      inicio = novo;
      fim = novo;
    }else{
      fim -> defProximo(novo);
      fim = novo;
    }
  }
  int tamanhoLista(){
    if (seVazia()){
      return 0;
    }
 
    no* i = inicio;
    int tamanho = 0;

    do{
      i = i -> obterProximo();
      tamanho++;
    }while(i);

      return tamanho;
    

  };

  bool existeElemento (int valor){
    no* i = inicio;
    while(i){
      if(i -> obterValor() == valor){
        return true;
      }else{
        i = i -> obterProximo();
      }
    }
    return false;
  }

  void removerDaLista(){
    if (!seVazia()){
      if (inicio -> obterProximo() == NULL){
        inicio = NULL;
      }else if(inicio -> obterProximo() == NULL){
        inicio -> defProximo(NULL);
      }else{
        no* anteriorDoAnterior = inicio;
        no* anterior = inicio -> obterProximo();
        no* elo = inicio -> obterProximo() -> obterProximo();

        while (elo){
          no* auxiliar = anterior;
          anterior = elo;
          anteriorDoAnterior = auxiliar;
          elo = elo -> obterProximo();
        }
        delete anteriorDoAnterior -> obterProximo();
        anteriorDoAnterior -> defProximo(NULL);
        fim = anteriorDoAnterior;
      }
    }
  }

};

  void paralelo(float v1, float r1, float r2){
    float resT, corrente, potencia;
    resT = r1*r2/(r1+r2);
    corrente = v1/resT;
    potencia = v1 * corrente;
    cout << "\nA resistencia em paralelo é: " << resT << " ohm(s)\n";
    cout << "A corrente total é: " << corrente <<" A\n";
    cout << "A potencia da fonte é: " << potencia << " W\n";
  }

  void serie(float v1, float r1, float r2){
    float resT, corrente, potencia;
    resT = r1+r2;
    corrente = v1/resT;
    potencia = v1 * corrente;
    cout << "\nA resistência em serie é: " << resT << " ohm(s)\n";
    cout << "A corrente total é: " << corrente <<" A\n";
    cout << "A potência da fonte é: " << potencia << " W\n";
  }

  void gravarNaLista(){
    ofstream gravar;
    no* i=inicio;
    gravar.open("Entradas.txt", ios::out);
      while (i){
        gravar << i -> obterValor() << endl;
        i=i -> obterProximo();
      }
      gravar << "------------------";
      gravar.close();
  }


int main() {
  int i=0, x=1;
  lista var;
  ifstream ler;
  string texto = " ";

  while (x!=0){
    cout << "Escolha a ação a ser realizada: \n1 - Inserir dados\n2 - Ler dados\n0 - Sair\n";
    cin >> x;

    if (x == 1){
      cout << "Informe o valor da fonte: \n";
      cin >> i;
      var.insereNoFim(i);
      cout << "Informe o valor da primeira resistência: \n";
      cin >> i;
      var.insereNoFim(i);
      cout << "Informe o valor da segunda resistência: \n";
      cin >> i;
      var.insereNoFim(i);
      gravarNaLista();

    }else if(x == 2){
      ler.open("Entradas.txt", ios::in);
      cout << "------------------\n";
      while (!ler.eof()){
        ler >> texto;
        cout << texto << endl;
      }
    ler.close();
    }


    /*do {
      cout << "Para qual circuito deseja obter as informações: \n1 - Paralelo \n2 - Série \n";
      cin >> tipo;

    if (tipo==1){
        cout <<"------------------------------------------------\n";
        cout << var;
        paralelo( var.v1, var.r1, var.r2);
        i=0;
        }else if(tipo == 2){
        cout <<"------------------------------------------------\n";
        cout << var;
        serie( var.v1, var.r1, var.r2);
        i=0;
        }else {
        cout << "Opção nao listada!\n";
        i=1;
        }
    }    
    while(i);*/
  }
}