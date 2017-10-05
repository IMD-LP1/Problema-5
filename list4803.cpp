#include <iostream>

template <class T>
class rational
{
public:
    typedef T value_type;
    rational() : rational{0} {}
    rational(T num) : numerator_{num}, denominator_{1} {}
    rational(T num, T den);

    void assign(T num, T den);

    template<class U>
    U convert()
    const
    {
        return static_cast<U>(numerator()) / static_cast<U>(denominator());
    }

    T numerator() const { return numerator_; }
    T denominator() const { return denominator_; }
private:
    T MDC();
    void reduce();
    T numerator_;   // numerator gets tje sing of the rational value.
    T denominator_; // denominator is always positive
};

//  Construct a rational object, given a numerator and a denominator.
template<class T>
rational<T>::rational(T num, T den)
: numerator_{num}, denominator_{den}
{
    rational<T>::reduce();
}

//  Assing a numerator and a denominator, then reduce to normal form.
template<class T>
void rational<T>::assign(T num, T den)
{
    numerator_ = num;
    denominator_ = den;
    rational<T>::reduce();
}

// Reduce the numerator and denominator by their GCD.
template<class T>
void rational<T>::reduce(){
rational<T>::MDC();

}
template<class T>
T rational<T>::MDC(){

    int resto;
    resto = numerator_% denominator_;
              while(resto!=0)
              {
                  numerator_    = denominator_;
                  denominator_    = resto;
                  resto = numerator_ % denominator_;         
              }
              return denominator_;
              //system("pause");
}

//  Compare two rational number for equality.
template<class T>
bool operator==(rational<T> const& a,rational<T> const& b)
{
    return a.numerator() == b.numerator() and a.denominator() == b.denominator();
}

//  Compare two rational number for inequality.
template<class T>
inline bool operator!=(rational<T> const& a, rational<T> const& b)
{
    return not(a == b);
}

int main() {
    rational<short> zero{};
    rational<int> pi1{355, 113}, x{1, 2}, y{2, 4};
    rational<long> pi2{80143857L, 25510582L};
    rational<int> r{(rational<int>)3 * rational<int>{1, 3}};

    std::cout <‌< r.numerator() <‌< ’/’ <‌< r.denominator() <‌< std::endl;
 

    if(bool operator==() != bool operator!=() )
        std::cout << "1/2 == 2/4" << std::endl;
    else
        std::cout << "1/2 != 2/4" << std::endl;
}
