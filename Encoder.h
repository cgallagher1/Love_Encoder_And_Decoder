#pragma once
#include <iostream>
#include <time.h>
#include <fstream>
#include <ostream>
#include <vector>
#include <string>

using namespace std;

class NeedToEncode
{
public:
	NeedToEncode(string filename);
	void ChangeWordsIntoNumbers(vector <string>& words);
	void MostCommonLetterssManipulaor(vector <int>& convertedwords);
	void CreateMatrix(vector <int> convertedwords);
	void CreateKeyMatrix(vector<vector <int> > n);
	void MultiplyTheMatricies(vector <vector <int>> original, vector <vector <int>> key);
	void Print();
	//~NeedToEncode();

private:
	vector<string> words;
	vector <int> convertedwords;
	vector <vector <int> > matrix;
	vector <vector<int>> keyMatrix;
	vector <vector <int>> encodedMatrix;
	int randmonAdder = (rand()) + 27;
};

/*NeedToEncode::~NeedToEncode()
{
}*/