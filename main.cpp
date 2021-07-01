#include <iostream>
#include <fstream>
using namespace std;

class no{
public:
  float valor;
  no* proximo;

  no(float elemento){
    this -> valor=elemento;
    this -> proximo=NULL;
  }

  void defProximo(no* end){
    proximo=end;
  }

  float obterValor(){
    return valor;
  }

  no* obterProximo(){
    return proximo;
  }
};

//======================================LISTA======================================

class lista{
 public: 
  no* inicio;
  no* fim;

  lista(){
    inicio=NULL;
    fim = NULL;
  }

  lista(float num){
    inicio = new no(num);
    fim = inicio;
  }

  virtual ~lista(){
    delete inicio;
  }

  bool seVazia(){
    return (inicio == NULL);
  }

  void insereNoFim(float valor){
    no* novo = new no(valor);

    if (seVazia()){
      inicio = novo;
      fim = novo;
    }else{
      fim -> defProximo(novo);
      fim = novo;
    }
  }

   void gravarNaLista(string x){
    ofstream gravar;
    no* i=inicio;
    gravar.open(x, ios::out);
      while (i){
        gravar << i -> obterValor() << endl;
        i=i -> obterProximo();
      }
      gravar << "-----";
      gravar.close();
  }
};

//=====================================FUNÇÕES=====================================
  
  void paralelo(float v1, float r1, float r2){
    lista out;
    float resT, corrente, potencia;
    resT = r1*r2/(r1+r2);
    out.insereNoFim(resT);
    corrente = v1/ resT;
    out.insereNoFim(corrente);
    potencia = v1 * corrente;
    out.insereNoFim(potencia);
    out.gravarNaLista("saidas.txt");
  }

  void serie(float v1, float r1, float r2){
    lista out;
    float resT, corrente, potencia;
    resT = r1*r2;
    out.insereNoFim(resT);
    corrente = v1/ resT;
    out.insereNoFim(corrente);
    potencia = v1 * corrente;
    out.insereNoFim(potencia);
    out.gravarNaLista("saidas.txt");
  }

//=====================================MAIN=====================================

int main() {
  int i=0, tipo=0, x=1;
  lista var;
  ifstream lerin, lerout;
  string txt1 = " ", txt2 = " ";

  while (x!=0){
    float v1=0, r1=0, r2=0;
    cout << "Escolha a ação a ser realizada: \n1 - Inserir dados\n2 - Ler dados\n0 - Sair\n";
    cin >> x;

    if (x == 1){
      cout << "Informe o valor da fonte: \n";
      cin >> v1;
      var.insereNoFim(v1);
      cout << "Informe o valor da primeira resistência: \n";
      cin >> r1;
      var.insereNoFim(r1);
      cout << "Informe o valor da segunda resistência: \n";
      cin >> r2;
      var.insereNoFim(r2);
      var.gravarNaLista("Entradas.txt");
      do {
      cout << "Para qual circuito deseja obter as informações: \n1 - Paralelo \n2 - Série \n";
      cin >> tipo;

       if (tipo==1){
        cout <<"------------------------------------------------\n";
        paralelo(v1, r1, r2);
        i=0;
        }else if(tipo == 2){
        cout <<"------------------------------------------------\n";
        serie(v1, r1, r2);
        i=0;
        }else {
        cout << "Opção nao listada!\n";
        i=1;
        }
    }    
    while(i);

    }else if(x == 2){
      lerin.open("Entradas.txt", ios::in);
      lerout.open("saidas.txt", ios::in);
      cout << "-----   -----\n";
      while (!lerin.eof()){
        lerin >> txt1;
        lerout >> txt2;
        cout << txt1 << "   " << txt2 << endl;
      }
    lerin.close();
    lerout.close();
    }
  }
}