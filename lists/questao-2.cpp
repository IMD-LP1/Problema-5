/** 
 *	@file questao-2.cpp 
 *
*/
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

/**
 * @Class Conjunto
 */
template<typename T>
class Conjunto {
public:
	Conjunto();
	Conjunto(int t);
	~Conjunto();

	void ler();
	void imprimir();
	bool pertinencia(int);
	void diferenca(Conjunto, Conjunto, Conjunto);
	void uniao(Conjunto, Conjunto);
	void intersecao();

	

private:
	int tam_;
	T* elementos_;
};

template <typename T>
Conjunto<T>::Conjunto() {
	tam_ = 0;
	elementos_ = nullptr;
}

template <typename T>
Conjunto<T>::Conjunto(int t) {
	tam_ = t;
	elementos_ = new (std::nothrow) T[tam_];
}
template <typename T>
Conjunto<T>::~Conjunto() {
	delete[] elementos_;
}

template <typename T>
void Conjunto<T>::ler() {

	for(int i{0}; i < tam_; i++) {
		cout << "Element " << i + 1 << ": ";
		cin >> elementos_[i];
		if(pertinencia(i)) {
			i--;
		}
	}
}

template <typename T>
void Conjunto<T>::imprimir() {

	for(int i{0}; i < tam_; i++) {
		cout << elementos_[i];
		if(i < tam_ - 1)
			cout << ", ";
	}
}

template <typename T>
bool Conjunto<T>::belongs(int t) {
	for(int j{0}; j < t; j++) {
		if(elementos_[j] == elementos_[t]) {
			return true;
		} 
	}
	return false;
}

template <typename T>
void Conjunto<T>::diferenca(Conjunto b) {
	Conjunto <T> c {get_current_size()}

	for(int i{0}; i < get_current_size()_; i++) {
		if(not b.belongs(elementos_[i])) 
		 	c.insert(elementos_[i]);
	}	
	return c;
}

template <typename T>
void Conjunto<T>::uniao(Conjunto a, Conjunto b) {

	for(int i{0}; i < a.tam_; i++) {
		for(int j{0}; j < b.tam_; j++) {

		}
	}

}

template <typename T>
void Conjunto<T>::intersecao() {
	for(int i{0}; i < tam_; i++) {

	}
}

int main() {

	int a, b, c;
	
	cout << "Cardinalidade de A: ";
	cin >> a;
	Conjunto <int>A(a);
	A.ler();

	cout << "Cardinalidade de B: ";
	cin >> b;
	Conjunto <int>B(b);
	B.ler();

	cout << "A = { "; 
	A.imprimir();
	cout << " }" << endl;
	cout << "B = { ";
	B.imprimir();
	cout << " }" << endl;
	
	Conjunto <int> c = a.diferenca(b);

	cout << "Diferenca: ";
	//C.diferenca(a, b);
	C.imprimir();

}