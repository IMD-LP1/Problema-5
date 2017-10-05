/** Questão 2 - Problema 5 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<class T>
class conjunto
{
public:
conjunto(T const&);
conjunto();
T tamanh();

void ler_elementos();
void imprime_elementos();
void alocar_elementos(T);
void diferenca(conjunto A, conjunto B); 			//verificar
bool verifica_vetor(int);
void uniao(conjunto A, conjunto B);
void interseccao(conjunto A, conjunto B);

T* elementos;								//verificar

private:
int tamanho;
//T *elementos;
};

template<class T>
conjunto<T>::conjunto(T const& x)
: tamanho{x}
{}

template<class T>
conjunto<T>::conjunto()
: tamanho{}
{}

template<class T>
T conjunto<T>::tamanh()

{
return tamanho;
}

template<class T>
void conjunto<T>::alocar_elementos(T tam)
{
tamanho = tam;
elementos = new T[tam];
}

template<class T>
void conjunto<T>::ler_elementos()
{
cout << "Informe os elementos do vetor:\n";
for (int i = 0; i < tamanh(); ++i){
cout << "Element " << i+1 << ": ";
cin >> elementos[i];
while(verifica_vetor(i)){
cout << "Elemento repetido! Digite outro!" << endl;
cin >> elementos[i];
}
}
}

template<class T>
void conjunto<T>::imprime_elementos()
{
for (int i = 0; i < tamanh(); ++i){
cout << elementos[i] << " ";
	}
}

template<class T>
bool conjunto<T>::verifica_vetor(int i)
{
int j = i;
int aux = i-1;
while(i > 0){
if(elementos[j] == elementos[aux]){
return true;
}
i--;
aux--;
}
return false;
}


template<class T>
void conjunto<T>::diferenca(conjunto A, conjunto B)              //verificar
{

	int tamC = A.tamanh();
	vector<T> aux;
	int Acc;

	for (int i = 0; i < A.tamanh(); ++i){
		Acc = 0;
		for (int j = 0; j < B.tamanh(); ++j){
			if (A.elementos[i] == B.elementos[j]){
					tamC--;
					Acc = 1;
				}
			}
    	if (Acc == 0){
    		aux.push_back(A.elementos[i]); //troquei o "+=" pela função "push_back()" pois assim não exige usar acesso de posição no
    		                               //vector aux, e você usa o tamanho dele depois para transcrever para o vetor destino
    	}
	}

		
	alocar_elementos(tamC);

	for(int i = 0;i < tamanh();i++){
		elementos[i] = aux[i]; 
	}
	
}


template<class T>
void conjunto<T>:: uniao(conjunto A, conjunto B)
{
	vector<T> v;
	int aux = 0;
	int tamU = A.tamanh();

	for (int i = 0; i < A.tamanh(); ++i){
			v.push_back(A.elementos[i]);
	}

	for (int i = 0; i < B.tamanh(); ++i){
		for (int j = 0; j < A.tamanh(); ++j){
			if (B.elementos[i] == A.elementos[j]){
					aux = 1;
					}
		}

			if(aux == 1)
				aux = 0;
		else{
			v.push_back(B.elementos[i]);
			tamU++;
		}
	}

	alocar_elementos(tamU);
	for (int i = 0; i < tamanh(); ++i){
			elementos[i] = v[i];
	}
}

template<class T>
void conjunto<T>:: interseccao(conjunto A, conjunto B)
{
	int tamD = 0;
	vector<T> aux;

	for (int i = 0; i < A.tamanh(); ++i){
		for (int j = 0; j < B.tamanh(); ++j){
			if (A.elementos[i] == B.elementos[j]){
					tamD++;
					aux.push_back(A.elementos[i]);
					 }
				}
	}

	alocar_elementos(tamD);
	for (int i = 0; i < tamanh(); ++i)
	{
		elementos[i] = aux[i];
	}
}


int main()
{
int AA, BB;
cout << "Tamanho de A:\n";
cin >> AA;

conjunto <int> A(AA);
A.alocar_elementos(AA);
A.ler_elementos();
cout << " A = {";
A.imprime_elementos();
cout << "}";
cout << endl;


cout << "Tamanho de B: ";
cin >> BB;
conjunto<int> B {BB};
B.alocar_elementos(BB);
B.ler_elementos();
cout << "B = {";
B.imprime_elementos();
cout << "}";
cout << "\n\n";


conjunto<int> C{0};
C.diferenca(A, B);
cout << "Diferença = {";
C.imprime_elementos();
cout << "}";
cout <<"\n";

conjunto<int> D{0};
D.uniao(A,B);
cout << "União = { ";
D.imprime_elementos();
cout << "}\n";

conjunto<int> E{};
E.interseccao(A,B);
cout << "Interseccao = {";
E.imprime_elementos();
cout << "} \n";


}
