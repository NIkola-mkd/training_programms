#include <iostream>
#include <cmath>
#include <exception>
#include <iomanip>

using namespace std;

double f(double x, double absError, int numberMax)
{

	if ((x < -1) || (x > 1))
		throw out_of_range("x vne intervala (-1, 1)");

	double sum = 1;
	int kolichestvo_slagaemih = 1;

	double chislitel = x * x; 
	double znamenatel = 1.0; 
	double znak = -1.0; 

	while (true)
	{
		if (kolichestvo_slagaemih > numberMax)
			throw out_of_range("kolichestvo slagaemih previshaet max dopushenoe kolichestvo slagaemih"); 

		double vrs = znak * (chislitel / znamenatel);

		if (abs(vrs) < absError)
			break;

		sum = sum + vrs; 

		kolichestvo_slagaemih = kolichestvo_slagaemih + 1;
		chislitel = chislitel * x * x;
		znamenatel = znamenatel * kolichestvo_slagaemih;
		znak = znak * (-1);
		
	    
	}
	cout <<"\n"<< sum << endl;
	return sum;
	


}

void makeTable(double absError, int numberMax, double x_nizneye, double x_verhneye, double shag)
{
	for (double x = x_nizneye; x <= x_verhneye; x = x + shag)
	{
		cout << "F(" << x << ") = " << fixed<< f(x, absError, numberMax) << endl;
	}
}

int main()
{
	double absError, x_nizneye, x_verhneye, shag, sum;
	int numberMax;

	cout << "Vvedite max pogreshnost \n";
	cin >>absError;

	cout << "Vvedite perviy nomer vnutri intervala \n";
	cin >>x_nizneye;

	cout<< "Vvedite posledniy nomer vnutri intervala \n";
	cin >>x_verhneye;

	cout << "Vvedite shag \n";
	cin >>shag;

	cout << "Vvedite NumberMax \n";
	cin >>numberMax;

	try
	{
		makeTable(absError, numberMax, x_nizneye, x_verhneye, shag);
		
	}
	catch (const out_of_range & exception)
	{
		cout << "Error: " << exception.what() << endl;
	}
	
	system("PAUSE");
	return 0;
}