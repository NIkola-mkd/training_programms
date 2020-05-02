#include "BookinLibrary.h"
#include "String.h"
#include "Exception.h"
#include "DynamicArray.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <map>

using namespace std;

int findLargest(DynamicArray<BookinLibrary>& bookLib)
{
	int Largest = 0;
	for (int i = 1; i < bookLib.getSize(); i++)
	{
		if (bookLib[i] > bookLib[Largest])
		{
			Largest = i;
		}
	}
	return Largest;
}

template <class T>
void sortDynamicArray(DynamicArray<T>& d)
{
	for (int i = 1; i < d.getSize(); i++)
	{
		T k = d[i];
		int j = i - 1;
		for (; j >= 0 && d[j] > k; j--)
		{
			d[j + 1] = d[j];
		}
		d[j + 1] = k;
	}
}

int findLargest(DynamicArray<BookinLibrary>& bookLib);
template <class T>
void sortDynamicArray(DynamicArray<T>& d);

int main()
{
	cout << "You can select two text files:\n";
	cout << "1-'inp.txt'. Its a simple library and works perfectly\n";
	cout << "2-'book.txt.' Its a simple Polytech library which has errors and shows how classException works\n";
	cout << "Enter input file name: ";
	String file1;
	cin >> file1;
	cout << "*Checking for errors in input file*\n";
	ofstream("result.txt");
	if (cin.bad())
	{
		cerr << "Can't read file with that name!" << endl;
		return -1;
	}
	ifstream fin;
	fin.open(file1.get());
	if (!fin.is_open())
	{
		cerr << "Can't open file with that name!" << endl;
		return -2;
	}
	ofstream fout;
	fout.open("result.txt");
	if (!fout.is_open())
	{
		cerr << "Can't create output_file.txt!" << endl;
		fin.close();
		return -3;
	}
	DynamicArray<BookinLibrary> bookLib;
	BookinLibrary bookR;
	while (!fin.eof())
	{
		try
		{
			fin >> bookR;
			bookLib.add(bookR);
		}
		catch (const Exception & e)
		{
			cout << e.getError() << endl;
			if (fin.bad() && !fin.eof())
			{
				fin.clear();
			}
		}
	}
	fin.close();
	if (bookLib.isEmpty())
	{
		cerr << "No books could be read!" << endl;
		fout.close();
		return -4;
	}
	
	sortDynamicArray(bookLib);
	fout << endl
		<< "Table ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n" 
		<< setw(30) << "Author's name"
		<< setw(50) << "Title"
		<< setw(7) << "Year"
		<< setw(25) << "Genre"
		<< setw(7) << "Amount"
		<< endl;
	for (int i = 0; i < bookLib.getSize(); i++)
	{
		fout << bookLib[i] <<endl;
	}
	map<String, int> genre;
	for (int i = 0; i < bookLib.getSize(); i++)
	{
		if (genre.count(bookLib[i].getGenre()) != 0)
		{
			genre[bookLib[i].getGenre()]++;
		}
		else
		{
			genre[bookLib[i].getGenre()] = 1;
		}
	}
	fout << endl
		<< "List _____________________________________________________________________________________________________________________________________________________________________________________________________\n"
		<< setw(20) << "Genre"
		<< setw(7) << "Count"
		<< endl;
	
	for (map<String, int>::iterator itr = genre.begin(); itr != genre.end(); itr++)
	{
		fout <<setw(20) << itr->first
			<< setw(7) << itr->second
			<<endl;
	}
	fout << "Maximum object: " << bookLib[findLargest(bookLib)] << endl;
	fout.close();
	
	cout << "|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-||-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|\n";
	cout << "Data from output file\n";
	ifstream openfile2("result.txt");
	cout << ifstream("result.txt").rdbuf() << endl;
	return 0;
}