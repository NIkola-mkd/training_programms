#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
#include <fstream>

using namespace std;

string sortFunc(const string& inp)
{ 
	string result;
	for (int i = 0; i < inp.size(); i++)
	{
		if (isalpha(inp[i]))
		{
			result += inp[i];
		}
	}
	sort(result.begin(), result.end());
	return result;
}

char* sortFunc2(const char* inp)
{
	int i = 0;
	int counter[255] = { 0 };
	int amount = 0;
	while (inp[i] != '\0')
	{
		if ((inp[i] >= 'a' && inp[i] <= 'z') || (inp[i] >= 'A' && inp[i] <= 'Z'))
		{
			counter[(int)inp[i]]++;
			amount++;
		}
		i++;
	}

	char* result = new char[amount + 1];
	result[amount] = '\0';
	int j = 0;
	for (char c = 'A'; c <= 'Z'; c++)
	{
		while (counter[(int)c] > 0)
		{
			result[j++] = c;
			counter[(int)c]--;
		}
	}
	for (char c = 'a'; c <= 'z'; c++)
	{
		while (counter[(int)c] > 0)
		{
			result[j++] = c;
			counter[(int)c]--;
		}
	}

	return result;
}

int main()
{
	ifstream inp("inp.txt");
	string line;

	string resultStr;

	getline(inp, line);
	cout << "input line: " << line << endl;
	string result1s = sortFunc(line);
	char* result1c = sortFunc2(line.c_str());
	
	getline(inp, line);
	cout << "input line: " << line << endl;
	string result2s = sortFunc(line);
	char* result2c = sortFunc2(line.c_str());

	cout << "result string: " << result1s << " " << result2s << endl;
	cout << "result char*: " << result1c << " " << result2c <<endl;

	delete[] result1c;
	delete[] result2c;
	
	return 0;
}


		
		

