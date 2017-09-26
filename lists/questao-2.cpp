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
	bool pertinencia();
	void diferenca();
	void uniao();
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
		for(int j{0}; j < i; i++) {
			if()
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


int main() {

	int a, b;
	
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
}