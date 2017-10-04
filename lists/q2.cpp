/** Questão 2 - Problema 5 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<class T>
class point
{
public:
point(T const&);
point();
T tamanh();

void ler_elementos();
void imprime_elementos();
void alocar_elementos(T);
void diferenca(point A, point B); 			//verificar
bool verifica_vetor(int);
T* elementos;								//verificar

private:
int tamanho;
//T *elementos;
};

template<class T>
point<T>::point(T const& x)
: tamanho{x}
{}

template<class T>
point<T>::point()
: tamanho{}
{}

template<class T>
T point<T>::tamanh()

{
return tamanho;
}

template<class T>
void point<T>::alocar_elementos(T tam)
{
tamanho = tam;
elementos = new T[tam];
}

template<class T>
void point<T>::ler_elementos()
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
void point<T>::imprime_elementos()
{
for (int i = 0; i < tamanh(); ++i){
cout << elementos[i] << " ";
	}
}

template<class T>
bool point<T>::verifica_vetor(int i)
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
void point<T>::diferenca(point A, point B)              //verificar
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
		aux[i] += A.elementos[i];
	}
	}

		
	alocar_elementos(tamC);

	for(int i = 0;i < tamanh();i++){
		elementos[i] += aux[i];
		}
	
}

/*

template<class T>
T point<T>:: uniao(T tamA, T vetorB, T tamB, T vetorB)
{
std::vector<T> v;
int aux = 0;
int tamU;

for (int i = 0; i < tamA; ++i){
v+= vetorA[i];
tamU++;
}

for (i = 0; i < tamB; ++i){
for (int j = 0; j < tamA; ++i){
if (vetorB[i] == vetorA[j])
{
aux = 1;
}
}
if(aux == 1)
aux = 0;
else{
v+= vetorB[i];
tamU++;
}
}

D.alocar_elementos(tamU);
for (int i = 0; i < tamanh(); ++i)
{
elementos+=v[i];
}

}

template<class T>
T point<T>:: interseccao(T tamA, T vetorA, T tamB, T vetorB)
{
int tamD = 0;
vector<T> aux;
for (int i = 0; i < tamA; ++i){
for (int j = 0; j < tamB; ++j){
if (vetorA[i] == vetorB[j]){
tamD++;
aux+=vetorA[i]; }
}
}

D.alocar_elementos(tamD);
for (int i = 0; i < tamanh(); ++i)
{
elementos+= aux;
}
}

*/

int main()
{
//point uniao, diferenca, interseccao;
int AA, BB;
cout << "Tamanho de A:\n";
cin >> AA;

point <int> A(AA);
A.alocar_elementos(AA);
A.ler_elementos();
cout << " A = {";
A.imprime_elementos();
cout << "}";
cout << endl;


cout << "Tamanho de B: ";
cin >> BB;
point<int> B {BB};
B.alocar_elementos(BB);
B.ler_elementos();
cout << "B = {";
B.imprime_elementos();
cout << "}";
cout << "\n";

point<int> C{0};
C.diferenca(A, B);
cout << "C = {";
C.imprime_elementos();
cout << "}";
cout <<"\n";

}