/** Listing 48-1. The point Class Template */
template<class T>
class point
{
public:
	point(T const& x, T const& y);
	point();
	T const& x() const;
	T const& y() const;
	void move_to(T, T);	/// mova o ponto para as coordenadas (x, y)
	void move_by(T, T);	/// adicione (x, y) à posição atual do ponto

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

template<class T>
void point<T>::move_to(T x, T, y) {
	x_ = x;
	y_ = y;
}

template<class T>
void point<T>::move_by(T x, T y) {
	x_ += x;
<<<<<<< HEAD
	y_ += y;
=======
	y_ += y;	
>>>>>>> ecece59374841771a1af92ecda48a72cf1a59404
}

int main() {}
