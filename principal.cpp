#include<iostream>
#include <iomanip>

using namespace std;

#define _MAX_ 100

class TAluno
{
    private:
       string nome;
       float nota1,nota2;
    public:
       void ler();
       float media();
       string situacao();
       string getNome();
       float getNota1();
       float getNota2();
};
void TAluno::ler()
{
   cin.ignore();
   cout << "Nome:";		getline(cin,nome);
   cout << "Nota1:";		cin >> nota1;
   cout << "Nota2:";		cin >> nota2;

}
float TAluno::media()
{
  return (nota1+2*nota2)/3;
}
string TAluno::situacao()
{
   return media()>=6?"Aprovado":"Reprovado";
}
string TAluno::getNome()
{
   return nome; 
}
float TAluno::getNota1()
{
   return nota1;
}
float TAluno::getNota2()
{
   return nota2;
}


class TTurma
{
    private:
       TAluno v[_MAX_];
       int    qtd;
    public:
        void ler();
        void listar();
};
void TTurma::ler()
{
  cout << "Entre com a quantidade de aluno:";
  cin >> qtd;
  for (int i=0; i<qtd ; i++)
    v[i].ler();
}

void TTurma::listar()
{
   cout << setprecision(2) << fixed;
   for(int i=0;i<qtd;i++)
    cout << setw(30) << left << v[i].getNome() << right << setw(6) << v[i].getNota1() << setw(6) <<
	    v[i].getNota2() << setw(6) << v[i].media() << setw(10) <<
            left << " " << v[i].situacao() << endl;       
}

int main()
{
	TTurma t;
	t.ler();
	t.listar();
	return 0;
}