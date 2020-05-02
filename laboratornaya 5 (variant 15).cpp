#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int minSumMatrix(int** mat, int size);
int main()
{

	const string ERROR_NOT_NUMBER = "Error: imposible to detect the length of matrix!";
	const string ERROR_NOT_NUMBER_ARRAY = "Error: must be a number!";
	const string ERROR_EMERGENCY_EXIT = "Emergency exit!!! ";
	ifstream OpenFile;
	int size = 0;
	OpenFile.open("Matrix.txt");
	
		if (!OpenFile.is_open())
		{
			cerr << "File cannot be open!\n";
		}
		while (!OpenFile.eof())
		{
			try
			{
				OpenFile >> size;
				if (!OpenFile)
					throw ERROR_NOT_NUMBER;
			}
			catch (const string& error)
			{
				cerr << '\n' << error << '\n' << ERROR_EMERGENCY_EXIT;
				return -1;
			}
			int** mat = new int* [size];
			for (int i = 0; i < size; i++)
			{
				mat[i] = new int[size];
			}
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					try
					{
						OpenFile >> mat[i][j];
						
						if (!OpenFile)
							throw ERROR_NOT_NUMBER_ARRAY;
					}
					catch (const string& error)
					{
						cerr << '\n' << error << '\n' << ERROR_EMERGENCY_EXIT;
						return -1;

					}
				}
			}
			cout <<"The minimal summ is:  " << minSumMatrix(mat, size) << '\n';
			for (int i = 0; i < size; i++)
			{
				delete[] mat[i];
			}
			delete[] mat;
		}
		OpenFile.close();
		return 0;
	
}
int minSumMatrix(int** mat, int size)
{
	int min;
	int sum = 0;
	int sum1 = 0;
	int counter = 0;
	if (mat[0][0] > mat[size - 1][size - 1])
		min = mat[size - 1][size - 1];
	else
		min = mat[0][0];
	for (int i = 0; i < (size - 1); i++)
	{
		for (int j = 0; j <= i; j++)
		{
			sum += mat[i - j][j];
		}
		if (sum < min)
			min = sum;
		sum = 0;
	}
	for (int i = 1; i < (size - 1); i++)
	{
		for (int j = 0; j < (size - i); j++)
		{
			sum1 += mat[i + j][size - i - j + counter];
		}
		if (sum1 < min)
			min = sum1;
		sum1 = 0;
		counter++;
	}
	return min;
}

