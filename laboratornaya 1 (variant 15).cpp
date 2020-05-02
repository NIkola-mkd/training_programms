#include <iostream>
using namespace std;

int main()
{
	int n=1;  
	int count = 0; 
	int x = 0,y = 0; 
	bool first = false, second = false;
	
	while (n != 0) 
	{
		cout << "Insert number\n";
		cin >> n;

		if (n == 0) 
			break;
		
		if (first == false) {   
			x = n;      
			first = true;   
			continue;
		}

		if (second == false) {
			y = n;
			second = true;
			continue;
		}

		if (first == true && second == true) {
			if (n == x + y)
				count++;
			x = y;
			y = n;
		}
		
	}
	cout << "*********************************\n";
	cout << "Numbers that have sequential sum: ";
	cout << count << endl;
}
