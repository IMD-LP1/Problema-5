#include <iostream>
#include <iomanip>

using namespace std;

template <class T>
class conjunto{
public:
  conjunto (int);
  conjunto(conjunto<T> const&);
  ~conjunto();

  void ler_conjunto();
  void ler_conjunto(int); 
  void escrever_conjunto();
  bool procurar_conjunto(T e) const;
  conjunto<T> diferenca_conjunto(conjunto<T> const);
  conjunto<T> uniao_conjunto(conjunto<T> const);
  conjunto<T> intercecao(conjunto<T> const);

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
conjunto<T>::conjunto(int size)
{
  tam_max = size;
  tam_ = 0;

  elementos_ = new (nothrow) T [tam_max];
  if (not(elementos_))
    exit(EXIT_FAILURE);
}

template <class T>
conjunto<T>::conjunto(conjunto<T> const& that)
{
  tam_max = that.max_size();
  tam_ = that.retornar_tam();

  elementos_ = new (nothrow) T [tam_max];
  if (not(elementos_))
    exit(EXIT_FAILURE);

  for (int i{0}; i < tam_; i++)
    elementos_[i] = that.get_elemento(i);
}

template <class T>
void conjunto<T>::inserir(T elemento)
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
void conjunto<T>::ler_conjunto()
{
  ler_conjunto(tam_max);
}

template <class T>
void conjunto<T>::ler_conjunto(int n)
{
  T elemento; 

  for (int i{0}; i < n; i++)
  {
    cout << "Element " << i + 1 << ": ";
    cin >> elemento;
    inserir(elemento);
    }
}

template <class T>
void conjunto<T>::escrever_conjunto()
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
bool conjunto<T>::procurar_conjunto(T e)
const
{
  for (int i{0}; i < tam_; i++)
    if (elementos_[i] == e)
      return true;
  return false;  
}

template<class T>
conjunto<T> conjunto<T>::diferenca_conjunto(conjunto<T> const b)
{
  conjunto<T> c{tam_};

  for (int i{0}; i < tam_; i++)
  {
    if (not(b.procurar_conjunto(elementos_[i])))
      c.inserir(elementos_[i]);
  }

  return c;
}

template <class T>
conjunto<T> conjunto<T>::uniao_conjunto(conjunto<T> const b)
{
  // 
  conjunto<T> c {tam_ + b.retornar_tam()};

  // insert elements of A
  for (int i{0}; i < tam_; i++)
     c.inserir(elementos_[i]);
  
  // insert elements of B
  for (int i{0}; i < b.retornar_tam(); i++)
     c.inserir(b.get_elemento(i));

  return c;
}

template <class T>
conjunto<T>::~conjunto()
{
  delete []  elementos_;
  elementos_ = nullptr;
}


template <class T>
conjunto<T> conjunto<T>::intercecao(conjunto<T> const b)
{
  conjunto<T> c {tam_};

  for (int i{0}; i < tam_; i++)
    if (b.retornar_tam(elementos_[i]))
      c.inserir(elementos_[i]);

  return c;
}


int main (int argc, char** argv)
{
  int n1,n2;
  
  
  cout << "Cardinalidade de A: ";
  cin >> n1;
  cout << "Cardinalidade de B: ";
  cin >> n2;
  
  conjunto<int> A{n1},B{n2};
  
  cout << "-----------Conjunto A--------------" << endl;
  cout << "-----------Informe os elementos----" << endl;
  A.ler_conjunto();
  
  
  cout << "-----------Conjunto B--------------" << endl;
  cout << "-----------Informe os elementos----" << endl;
  B.ler_conjunto();

  cout << "-----------Conjunto A--------------" << endl;
  A.escrever_conjunto();

  cout << "-----------Conjunto B--------------" << endl;
  A.escrever_conjunto();
  
  cout << "------------Diferença---------------\n";
  A.diferenca_conjunto(B).escrever_conjunto();
  
  cout << "-------------União-------------------\n";
  A.uniao_conjunto(B).escrever_conjunto();
  
  
  
  
  




}
