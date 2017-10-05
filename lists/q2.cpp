#include <iostream>
#include <iomanip>

using namespace std;

template <class T>
class Conjunto{
public:
  Conjunto (int);
  Conjunto();
  ~Conjunto();

  void ler_conjunto(int); 
  void escrever_conjunto();
  bool belongs(int);
  Conjunto<T> diferenca_conjunto(conjunto<T> const);
  Conjunto<T> uniao_conjunto(conjunto<T> const);
  Conjunto<T> intercecao(conjunto<T> const);

  int retornar_tam() const {return tam_;}
  int max_size() const {return tam_max;}

private:
  void inserir(T);
  T get_elemento(int i) const {return elementos_[i];}
  
  int tam_;
  int tam_max;
  T* elementos_;

};

template<class T>
Conjunto<T>::Conjunto() {
	tam_ = 0;
	elementos_ = nullptr;
}

template<class T>
Conjunto<T>::Conjunto(int t) {
	
	tam_ = t;
		
	elementos_ = new (nothrow) T [tam_];
	if (not(elementos_))
		exit(EXIT_FAILURE);
}

template <class T>
Conjunto<T>::~Conjunto() {
  delete []  elementos_;
  elementos_ = nullptr;
}


template <class T>
void Conjunto<T>::inserir(T elemento)
{
  if (tam_ == tam_max)
  {
    cout << "erro ! .. encerrando programa .. " << endl;
    exit (EXIT_FAILURE);
  }

  if (not(procurar_conjunto(elemento)))
  {
    elementos_[tam_] = elemento;
    tam_++;
  }
}

template <class T>
void Conjunto<T>::ler_conjunto()
{
  ler_conjunto(tam_max);
}

template <class T>
void Conjunto<T>::ler_conjunto(int n)
{
  T elemento; 

  for (int i{0}; i < n; i++)
  {
    cout << "Element " << i + 1 << ": ";
    cin >> elemento_[i];
		if(belongs(i)) {
			i--;		
		}
    }
}

template <class T>
void Conjunto<T>::escrever_conjunto()
{
  cout << "{";
  for (int i{0}; i < tam_; i++)
  {
    cout << elementos_[i];
    if (i < tam_ - 1)
      cout << ", ";
  }
  cout << "}" << endl;
}

template <class T>
bool Conjunto<T>::belongs(int t) {
	for (int i{0}; i < t; i++) {	
		if (elementos_[i] == elementos[t]) {
			return true;
		}
	}
	return false;  
}

template<class T>
Conjunto<T> Conjunto<T>::diferenca_conjunto(Conjunto<T> const b) {
	Conjunto<T> c{tam_};

	for (int i{0}; i < tam_; i++) {
		if (not(b.procurar_conjunto(elementos_[i])))
			c.inserir(elementos_[i]);
		}
	return c;
}

template <class T>
Conjunto<T> Conjunto<T>::uniao_conjunto(Conjunto<T> const b)
{
  // 
  Conjunto<T> c {tam_ + b.retornar_tam()};

  // insert elements of A
  for (int i{0}; i < tam_; i++)
     c.inserir(elementos_[i]);
  
  // insert elements of B
  for (int i{0}; i < b.retornar_tam(); i++)
     c.inserir(b.get_elemento(i));

  return c;
}

template <class T>
Conjunto<T> Conjunto<T>::intercecao(conjunto<T> const b)
{
  conjunto<T> c {tam_};

  for (int i{0}; i < tam_; i++)
    if (b.retornar_tam(elementos_[i]))
      c.inserir(elementos_[i]);

  return c;
}


int main (int argc, char** argv)
{
  int n1, n2;
  
  
  cout << "Cardinalidade de A: ";
  cin >> n1;
  cout << "Cardinalidade de B: ";
  cin >> n2;
  
  Conjunto<int> A{n1},B{n2};
 
  cout << "Informe os elementos de A:" << endl;
  A.ler_conjunto();
  
  cout << "Informe os elementos de B" << endl;
  B.ler_conjunto();

  cout << "Conjunto A: " << endl;
  A.escrever_conjunto();

  cout << "Conjunto B: " << endl;
  A.escrever_conjunto();
  
  cout << "Diferença: " << endl;
  A.diferenca_conjunto(B).escrever_conjunto();
  
  cout << "União: " << endl;
  A.uniao_conjunto(B).escrever_conjunto();
}
