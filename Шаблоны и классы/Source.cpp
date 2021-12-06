#include<iostream>
#include<initializer_list>
using namespace std;

//void print()
//{}
//template<class First, class ...Other>
//void print(const First& first, const Other& ... other)
//{
//	cout << first;
//	print(other...);
//}
//template<class ... Args>
//void println(const Args& ... args)
//{
//	print(args...);
//	cout << endl;
//}
//

//struct Point
//{
//	int x;
//	int y;
//	friend ostream& operator<<(ostream& output, const Point& p)
//	{
//		output << "(" << p.x << "." << p.y << ")";
//		return output;
//	}
//};

//double getSum(double x)
//{
//	return x;
//}
//
//template<class ... Args>
//double getSum(double x, Args...args)
//{
//	return x+getSum(args...);
//}

//int getSum(int count, int first, ...)
//{
//	int sum = 1;
//	int* p = &first;
//	while (count--)
//	{
//		sum += *p;
//		p++;
//	}
//	return sum;
//}

//template<class Args>
//class IntArray
//{
//	int lenght;
//	Args* data;
//public:
//	IntArray() :lenght(0), data(nullptr) {};
//	IntArray(int lenght) :lenght(lenght)
//	{
//		data = new Args[lenght];
//	};
//
//	IntArray(const initializer_list<Args>& list) : IntArray(list.size())
//	{
//		int i = 0;
//		for (auto& element : list)
//		{
//			data[i] = element;
//			i++;
//		}
//	};
//
//	~IntArray()
//	{
//		delete[] data;
//	};
//
//
//	Args& operator[](int index)
//	{
//		return data[index];
//	}
//
//	int getLenght()const
//	{
//		return lenght;
//	}
//};

template<class T>
class Fraction
{
private:

	T numerator;
	T denumerator;

	void Nod()
	{
		T n = numerator;
		T d = denumerator;
		while (n != 0 && d != 0)
		{
			if (n > d)
			{
				n = fmod(d, n);
			}
			else
			{
				d = fmod(d, n);
			}
		}
		numerator = numerator / (n + d);
		denumerator = denumerator / (n + d);
	}

public:

	Fraction(T numerator = 0, T denumerator = 1)
	{
		this->numerator = numerator;
		if (denumerator != 0)
		{
			this->denumerator = denumerator;
		}
		else
			this->denumerator = 1;
		if (this->numerator > 0)
		{
			Nod();
		}
	}

	void setdernumerator(T denumerator)
	{
		if (denumerator != 0)
		{
			this->denumerator = denumerator;
		}
		else
			this->denumerator = 1;
		Nod();
	}

	void setnumerator(T numerator)
	{
		this->numerator = numerator;
		Nod();
	}

	int getnumerator() { return numerator; }

	int getdernumerator() { return denumerator; }

	void print()
	{
		cout << numerator << "/" << denumerator << "\n";
	}

	static Fraction add(const Fraction& fodj1, const Fraction& fodj2)
	{
		return Fraction(fodj1.numerator * fodj2.denumerator + fodj2.numerator * fodj1.denumerator, fodj1.denumerator * fodj2.denumerator);
	}

	static Fraction sub(const Fraction& fodj1, const Fraction& fodj2)
	{
		return Fraction((fodj1.numerator * fodj2.denumerator) - (fodj2.numerator * fodj1.denumerator), fodj1.denumerator * fodj2.denumerator);
	}

	static Fraction mult(const Fraction& fodj1, const Fraction& fodj2)
	{
		return Fraction(fodj1.numerator * fodj2.numerator, fodj1.denumerator * fodj2.denumerator);
	}

	static Fraction div(const Fraction& fodj1, const Fraction& fodj2)
	{
		return Fraction(fodj1.numerator * fodj2.denumerator, fodj2.numerator * fodj1.denumerator);
	}

	static bool ravni(const Fraction& fodj1, const Fraction& fodj2)
	{
		if ((fodj1.denumerator * fodj2.denumerator) == (fodj1.numerator * fodj2.numerator))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	static bool bolse(const Fraction& fodj1, const Fraction& fodj2)
	{
		if ((fodj1.denumerator * fodj2.denumerator) > (fodj1.numerator * fodj2.numerator))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	static bool menche(const Fraction& fodj1, const Fraction& fodj2)
	{
		if ((fodj1.denumerator * fodj2.denumerator) < (fodj1.numerator * fodj2.numerator))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	static bool bolseiliravni(const Fraction& fodj1, const Fraction& fodj2)
	{
		if ((fodj1.denumerator * fodj2.denumerator) >= (fodj1.numerator * fodj2.numerator))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	static bool mencheiliravni(const Fraction& fodj1, const Fraction& fodj2)
	{
		if ((fodj1.denumerator * fodj2.denumerator) <= (fodj1.numerator * fodj2.numerator))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	static Fraction plusplus(Fraction& fodj1)
	{
		fodj1.numerator = fodj1.numerator + fodj1.denumerator;
		return fodj1;
	}

	static Fraction minysminys(Fraction& fodj1)
	{
		fodj1.numerator = fodj1.numerator - fodj1.denumerator;
		return fodj1;
	}

	static Fraction pow(Fraction& fodj1)
	{
		return fodj1 * fodj1;
	}

	static Fraction sqrt1(Fraction& fodj1)
	{
		return Fraction(sqrt(fodj1.numerator), sqrt(fodj1.denumerator));
	}

	static Fraction Ne(Fraction& fodj1)
	{
		if (fodj1.numerator > 0)
		{
			return Fraction(fodj1.denumerator, fodj1.numerator);
		}
		else
		{
			return Fraction(fodj1.numerator, fodj1.denumerator);
		}
	}

	friend Fraction operator+(const Fraction& fraction1, const Fraction& fraction2)
	{
		return add(fraction1, fraction2);
	}

	friend Fraction operator-(const Fraction& fraction1, const Fraction& fraction2)
	{
		return sub(fraction1, fraction2);
	}

	friend Fraction operator*(const Fraction& fraction1, const Fraction& fraction2)
	{
		return mult(fraction1, fraction2);
	}

	friend Fraction operator/(const Fraction& fraction1, const Fraction& fraction2)
	{
		return div(fraction1, fraction2);
	}

	friend ostream& operator<<(ostream& output, const Fraction& fraction1)
	{
		output << fraction1.numerator << "/" << fraction1.denumerator;
		return output;
	}
	friend istream& operator>> (std::istream& in, Fraction& fraction1)
	{
		in >> fraction1.numerator;
		in >> fraction1.denumerator;
		return in;
	}
	friend bool operator== (const Fraction& fraction1, const Fraction& fraction2)
	{
		return ravni(fraction1, fraction2);
	}

	friend bool operator> (const Fraction& fraction1, const Fraction& fraction2)
	{
		return bolse(fraction1, fraction2);
	}

	friend bool operator< (const Fraction& fraction1, const Fraction& fraction2)
	{
		return menche(fraction1, fraction2);
	}

	friend bool operator>= (const Fraction& fraction1, const Fraction& fraction2)
	{
		return bolseiliravni(fraction1, fraction2);
	}

	friend bool operator<= (const Fraction& fraction1, const Fraction& fraction2)
	{
		return mencheiliravni(fraction1, fraction2);
	}

	friend Fraction operator++ (Fraction& fraction1)
	{
		return plusplus(fraction1);
	}

	friend Fraction operator-- (Fraction& fraction1)
	{
		return minysminys(fraction1);
	}

	friend Fraction pow1(Fraction& fraction1)
	{
		return pow(fraction1);
	}

	friend Fraction sqrt1(Fraction& fraction1)
	{
		return sqrt1(fraction1);
	}

	friend Fraction operator!(Fraction& fraction1)
	{
		return Ne(fraction1);
	}
};

template<class Args>
class FractionArray
{
	int lenght;
	Args* data;
public:
	FractionArray() :lenght(0), data(nullptr) {};

	FractionArray(int lenght) :lenght(lenght)
	{
		data = new Args[lenght];
	};

	FractionArray(const initializer_list<Args>& list) : FractionArray(list.size())
	{
		int i = 0;
		for (auto& element : list)
		{
			data[i] = element;
			i++;
		}
	};

	~FractionArray()
	{
		delete[] data;
	};


	Args& operator[](int index)
	{
		return data[index];
	}

	int getLenght()const
	{
		return lenght;
	}
};

int main()
{
	//double sum = getSum(1, 2, 3, 4, 5);
	//cout <<" sum= " << sum;
	//sum = getSum(25, 0, 5, 60);
	//cout << " sum= " << sum;

	//int sum = getSum(5, 1, 2, 3, 4, 5);
	//cout <<" sum= " << sum;
	//sum = getSum(4, 25, 1, 5, 60);
	//cout << " sum= " << sum;

	//println("Hello world!!!");
	//println("Pi= ", 3.14, '\n', 2, "*", 2, "=", 2 * 2);
	//println("Point: ",point);

	//IntArray<Point> pointArray{ Point{ 1,1 }, Point{ 7, 7 }, Point{ 3,3 },Point{ 3,6 }};
	//for (int i = 0; i < pointArray.getLenght(); i++)
	//{
	//	cout << pointArray[i] << ' ';
	//}

	FractionArray <Fraction<int>> fractarr{Fraction<int>{1, 2}, Fraction<int>{3, 4}, Fraction<int>{5, 6}, Fraction<int>{7, 8}};
	for (int i = 0; i < fractarr.getLenght(); i++)
	{
		cout << fractarr[i] << ' ';
	}






	return 0;
}