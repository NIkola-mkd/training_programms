#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

int main()
{
	int n;
	cout << "Vyberite odin variant\n";
	cout << "Variant 1: Massiv chiy chisla zadani v inicializacii\n ";
	cout << "Variant 2: Massiv kolichestvo elementov kotorie vvodyatsya\n";
	cout << "Variant 3: Massiv iz faila\n";
	cout << "_______________________________________________________________\n";

	cin >> n;
	cout << endl;

	void transfer(int arr[], int n, int left, int right, int newArr[]);

	switch (n)
	{

	case 1:
		{int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

		for (int i = 0; i < 10; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
		int n = 10;
		int left, right;
		int newArr[10];
		cin >> left >> right;
		transfer(arr, n, left, right,newArr);
		
		break;
		return 0;


	}

	case 2:
	{	int m = 0;
		
		cout << "Vnesite kolichestvo elementov v massive: \n";
		cin >> m;
		cout << endl;

		int* arr = new int[m];

		srand(time(NULL));

	for (int i=0 ; i< m; i++)
	{
		arr[i] = rand() % 5 + 1;
		cout << arr[i] << " ";
		
	}
	cout << endl;

	int left, right;
	cin >> left >> right;

	int newArr[100];
	transfer(arr, m, left, right, newArr);
	
	
	delete[] arr;
	break;
	return 0;

	}

	case 3:
	{
		int x = 0;
		

		int y = 0;
		int s;

		ifstream OpenFile("variant_15.txt");

		if (OpenFile.is_open())
		{

			OpenFile >> x;
			int* arr = new int[x];

			
			cout << "1viy massiv iz faila: \n";
			cout << endl;

			for (int i = 0; i < x; i++)
			{

				OpenFile >> arr[i];
				cout << arr[i]<<" ";
				
			}
			cout << endl;

			int left, right;
			cin >> left >> right;

			int newArr[100];
			transfer(arr,x , left, right, newArr);

			delete[] arr;
			cout << endl;

			int s;
			
			OpenFile >> s;

			int* arr1 = new int[s];

			cout << "2oy massiv iz faila: \n";
			cout << endl;

			for (int y = 0; y < s; y++)
			{

				OpenFile >> arr1[y];
				cout << arr1[y] << " ";
			}
			cout << endl;

			int left1, right1;
			cin >> left1 >> right1;

			int newArr1[100];
			transfer(arr1, s, left1, right1, newArr1);

			
			delete[] arr1;
			cout << endl;
			break;
			return 0;

		}

		OpenFile.close();
		{
			if (!OpenFile)
				cout << "File failed to open\n";

			break;
			return 0;
		}
	}

	default:
		cout << "Nepravilniy nomer !!!\n";

	}
	return 0;
}
void transfer(int arr[], int n, int left, int right,int newArr[])
{
	int j = 0;
	for (int i = 0; i < left; i++)
	{
		newArr[j++] = arr[i];
	}
	for (int i = right + 1; i < n; i++)
	{
		newArr[j++] = arr[i];
	}
	for (int i = left; i <= right; i++)
	{
		newArr[j++] = arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		cout << newArr[i] << " ";
	}

}