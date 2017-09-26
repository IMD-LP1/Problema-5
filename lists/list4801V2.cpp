/** Listing 48-1. The point Class Template */
template<class T>
class point
{
public:
	point(T const& x, T const& y);
	point();
	T const& x() const;
	T const& y() const;
	
private:
	T x_;
	T y_;
};

template<class T>
point<T>::point(T const& x, T const& y)
: x_{x}, y_{y}
{}

template<class T>
point<T>::point()
: x_{}, y_{}
{}

template<class T>
T const& point<T>::x()
const
{
	return x_;
}

template<class T>
T const& point<T>::y()
const
{
	return y_;
}

int main() {}
