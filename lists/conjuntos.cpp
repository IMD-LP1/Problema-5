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
	void set_tamanho(int) ;
	T get_elemento(int) ;
	void insert(T ele, int pos) ;
	bool pertinencia(int) ;

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
				if (pertinencia(ii)){
					cout << "O elemento " << elementos[ii] << " ja esta no conjunto, digite outro." << endl ;
					ii-- ;
				}
			}
		} 
	}
}

template<class T>
bool conjunto<T>::pertinencia(int tam_atual) {
	for (int i{0} ; i < tam_atual ; i++) {
		if (elementos[i] == elementos[tam_atual]){	
			return true ;
		}
	}
	return false ;
}

template<class T>
void conjunto<T>::read() {
	cout << "{" ;
	for (int i{0} ; i < tamanho ; i++) {
		if (i+1 == tamanho) {
			cout << elementos[i] << "}\n" ;
			i++ ;
		}
		else {	
			cout << elementos[i] << ", " ; 
		}
	}
}

template<class T>
int conjunto<T>::get_tamanho() {
	return tamanho ;
}

template<class T>
void conjunto<T>::set_tamanho(int t) {
	tam = t ;
}

template<class T>
T conjunto<T>::get_elemento(int pos;) {
	return elementos[pos] ;
}

template<class T>
void conjunto<T>::insert(T ele, int pos) {
	for (int i{0} ; i < pos ; i++) {
		if (!pertinencia(pos)) {
			elementos[pos] = ele ;
		}	
	}
}

template<class T>
conjunto<T>::~conjunto() {
	delete[] elementos ;
}

template<class T>
bool conjunto<T>::belongs(T ele) {
	for (int i{0} ; i < tam ; i++) {
		if (ele == elementos[i])  {
			return true ;
		}
	}
	return false ; 
}

template<class T>
conjunto conjunto<T>::intersecao (conjunto a) {
	conjunto <T>b ;
	if (tam < a.get_tamanho()) {
		b.set_tamanho(tam) ;
	}
	else {
		b.set_tamanho(a.get_tamanho()) ;
	}
	int indice{0} ;
	for (int i{0} ; i < b.get_tamanho() ; i++) {
		if(a.belongs(elementos[i])){
			b.insert(elementos[i],indice ) ;
			indice++ ;	
		}
	}
	return b ;

	

}	

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

	conjunto <int>c = a.intersecao(b) ;
	cout << "A inter B = " ;
	c.read() ;



}



