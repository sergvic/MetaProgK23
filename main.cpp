#include <iostream>
#include <string>

using namespace std;

template <typename T> class Matrix {
private:
	T data[];
};

template<typename T, typename Arg1Type, typename Arg2Type>
T getMax(Arg1Type a, Arg2Type b)
{
	return a < b ? b : a;
}

template<>
string getMax<string, string, string>(string a, string b)
{
	return a;
}

template<int K, typename T> T intExp(T x)
{
	T res = 1;
	for (int i = 0;i < K;i++) {
		res *= x;
	}

	return res;
}

template <int X, int K> class IntExp {
public:
	static const int R = IntExp<X, K - 1>::R*X;
};

template <int X> class IntExp<X, 0> {
public:
	static const int R = 1;
};

void main()
{
	int r = IntExp<2, 10>::R;
	int data[IntExp<2, 10>::R];
	data[1023] = IntExp<2, 10>::R;

	cout << "d = " << data[1023] << endl;

	return;

	getMax<string>("AA", "BB");

	int a = getMax<double>(3.4, 2);
	int b = getMax<int>(3, 2);
	int c = intExp<5>(2);
	cout << a << b << "; " << c << endl;
}