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

template <int K> class IntExp {
public:
	static const int R = IntExp<K - 1>::R;
};

template <> class IntExp<0> {
public:
	static const int R = 1;
};

void main()
{
	int r = IntExp<3>::R;
	getMax<string>("AA", "BB");

	int a = getMax<double>(3.4, 2);
	int b = getMax<int>(3, 2);
	int c = intExp<5>(2);
	cout << a << b << "; " << c << endl;
}