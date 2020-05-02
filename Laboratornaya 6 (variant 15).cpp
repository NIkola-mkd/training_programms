#include <iostream> 
#include <fstream>
#include <conio.h>
#include <string>

using namespace std;

bool isReal(string Str);
bool isMantissa(string Str, int& x);
bool isExp(string Str, int& x);
bool isUnsignedInt(string Str, int& x);
bool isDigit(string Str, int& x);
bool isSign(string Str, int& x);

int main()
{
	

	ifstream OpenFile("Recursion.txt");
		if (OpenFile.fail()){

			cout << "Error. File is not open\n";
			return 0;
	
		}
		
		string Str;
	
		while (OpenFile >> Str){

			if (isReal(Str))
				cout << "yes\n";
			else
				
			cout << "no\n";
		}
		
		return 0;
}

bool isDigit(string Str, int& x)       //<цифра> ::= 0 | 1 | 2 | 3 | 4 | 5 | 6 |7 | 8 | 9
{
	if (x<(int)Str.size() && (Str[x] > '0' - 1 && Str[x] < '9' + 1))
		return true;
	
	return false;
}
bool isUnsignedInt(string Str, int& x) //<целое без знака> ::= <цифра> | <цифра> <целое без знака> 
{
	bool case1 = 0,case2 = 0;
	if (!(case1 = isDigit(Str, x)))
		return false;
	if (isDigit(Str, ++x))
		case2 = isUnsignedInt(Str,x);
	return case1|| case2;

}
bool isSign(string Str, int& x)       //<знак> ::= + | - 
{
	if (x < (int)Str.size() && Str[x] == '+' || Str[x] == '-')
		return true;
	return false;

}
bool isMantissa(string Str, int& x)  //<мантисса> ::= . <целое без знака> |<целое без знака> . <целое без знака>
{
	int temp1 = 0, temp2 = x;
	bool case1 = 0,case2 = 0;
	case1 = (x < (int)Str.size() && (Str[x] == '.') && isUnsignedInt(Str, ++x));
	temp1 = x;
	x = temp2;
	case2 = (x < (int)Str.size() && isUnsignedInt(Str, ++x) && (Str[x] == '.') && isUnsignedInt(Str, ++x));
	if (case1){
	
		x = temp1;
		return true;
	}
	else if (case2){
	
		x = temp2;
		return true;
	}
	else
		return false;

}
bool isExp(string Str, int& x)  //<порядок> ::= E <знак> <целое без знака> 
{
	if (x < (int)Str.size() &&(Str[x]=='E'||Str[x]=='e') &&isSign(Str,++x) && isUnsignedInt(Str, ++x))
		return true;
	return false;
}
bool isReal(string Str)     //<вещественное> ::= <мантисса> <порядок> | <знак> <мантисса> <порядок>
{
	int x=0, temp1 = 0, temp2 = 0;
	bool case1 = 0,case2 = 0;
	case1 = isMantissa(Str, x) && isExp(Str, x);
	temp1 = x;
	x = 0;
	case2 = isSign(Str, x) && isMantissa(Str, ++x) && isExp(Str, x);
	temp2 = x;
	if (case1){
	
		if (temp1 != Str.size())
			return false;
		return true;
	}
	else if (case2){
	
		if (temp2 != Str.size())
			return false; 
		return true;
	}
	else
		return false;

}
