#include <iostream>

template <class T>
class rational
{
public :
	//typedef T value_type ;
	rational() : rational{0} {}
	rational(T num) : numerator_{num} , denominator_{1} {}
	rational(T num , T den) ;

	void assign (T num, T den) ; 
	int mdc (T num, T den) ;
	void set_numerator(T) ;
	void set_denominator(T) ;

	template<class U>
	U convert()
	const {
		return static_cast<U>(numerator()) / static_cast<U>(denominator()) ;
	}

	T numerator() const { return numerator_;}
	T denominator() const { return denominator_ ;}

private:
	void reduce() ;
	T numerator_ ;
	T denominator_ ;
} ;


template <class T>
rational<T>::rational(T num, T den) : numerator_{num} , denominator_{den} {
	rational<T>::reduce() ;
}

template <class T>
void rational<T>::assign(T num , T den) {
	numerator_ = num ; 
	denominator_ = den ;
	rational<T>::reduce() ;
}

template<class T>
int rational<T>::mdc(T num, T den) {
	int x , y{1};
	if (num < den) {
		x = num ;
	}
	else {
		x = den ;
	}

	for (int i{x} ; i > 1 ; i--) {
		if (num % x == 0 || den % x == 0) {
			y = i ;
		}
	}
	return y ;

}

template<class T>
void rational<T>::set_numerator(T num) {
	numerator_ = num ;
}

template<class T>
void rational<T>::set_denominator(T den) {
	denominator_ = den ;
}


template <class T>
void rational<T>::reduce() {
	int divisor = mdc(numerator() , denominator() ) ;
	set_numerator(numerator()/divisor) ;
	set_denominator(denominator()/divisor) ;

}

template<class T>
bool operator==(rational<T> const& a, rational<T> const& b){
	return a.numerator() == b.numerator() and a.denominator() == b.denominator() ;
}

template <class T>
inline bool operator!=(rational<T> const& a, rational<T> const& b) {
	return not (a == b) ;	
}

int main () {
	rational<short> zero{} ;
	rational<int> pil{355, 113} , x{1,2} , y{2,4} ;
	rational<long> p2{80143857L, 25510582L} ;

	//std::cout << x.numerator() << " " << x.denominator() << "\n" ;
	//std::cout << y.numerator() << " " << y.denominator() << "\n" ;

	if (x == y) {
		std::cout << "1/2 == 2/4" << std::endl ;
	}
	else {
		std::cout << "1/2 != 2/4" << std::endl ; 
	}
}