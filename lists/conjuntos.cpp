#include <iostream>
using std::cout ;
using std::cin ;
using std::endl ;




template <class T>
class conjunto {
public:
	conjunto() ;
	conjunto(int t) ;
	~conjunto() ;
	void write() ;
	void read() ;
	int get_tamanho() ;

private:
	T *elementos ;
	int tamanho ;
} ;


template<class T>
conjunto<T>::conjunto() {
	tamanho = 0 ;
	elementos = nullptr ;
}

template<class T>
conjunto<T>::conjunto(int t) {
	tamanho = t ;
	elementos = new T[tamanho] ;
}

template<class T>
void conjunto<T>::write() {
	for (int ii{0} ; ii < tamanho ; ii++) {
		cout << "Element " << ii+1 << ": " ;
		cin >> elementos[ii] ;
		if (ii > 0) {
			for (int jj{0} ; jj < ii ; jj++) {
				if (elementos[ii] == elementos[jj]){
					cout << "O elemento " << elementos[ii] << " ja esta no conjunto, digite outro." << endl ;
					ii-- ;
				}
			}
		} 
	}
}

//template<class T>
//conjunto<T>::tirando_ele_iguais

template<class T>
void conjunto<T>::read() {
	cout << "{" ;
	for (int i{0} ; i < tamanho ; i++) {
		cout << elementos[i] << ", " ; 
		if (i+1 == tamanho) {
			cout << elementos[i] << "}\n" ;
		}
	}
}

template<class T>
int conjunto<T>::get_tamanho() {
	return tamanho ;
}

template<class T>
conjunto<T>::~conjunto() {
	delete[] elementos ;
}

/*template<class T>
conjunto conjunto<T>::uniao (conjunto a, conjunto b ) {
	tamanho = a.get_tamanho() + b.get_tamanho() ;


} */


int main () {
	int na , nb ;
	cout << "Cardinalidade de A: " ;
	cin >> na ;
	cout << "Cardinalidade de B: " ;
	cin >> nb ;


	conjunto <int>a(na) ;
	conjunto <int>b(nb) ;
	cout << "Informe elementos de A:\n" ;
	a.write() ;
	cout << "Informe elementos de B:\n" ;
	b.write() ;

	cout << "A = " ; 
	a.read() ;
	cout << "B = " ; 
	b.read() ;




}



