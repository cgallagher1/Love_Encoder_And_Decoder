#include <iostream>
#include <time.h>
#include <fstream>
#include <ostream>
#include <vector>
#include <string>
#include "Encoder.h"

using namespace std;

NeedToEncode::NeedToEncode(string filename)
{
	ifstream information;
	string incomingword;
	information.open(filename);
	if (information.is_open())
	{
		while (information.good())
		{
			information >> incomingword;
			//Lower case
			for (unsigned int j = 0; j < incomingword.length(); j++)
			{

				if (incomingword[j] >= 65 && incomingword[j] <= 91)
				{
					incomingword[j] += 32;
				}
			}
			//Strip punctuation
			for (unsigned int j = 0; j < incomingword.length(); j++)
			{
				if ((incomingword[j] <= 64 || incomingword[j] >= 91 && incomingword[j] <= 96 || incomingword[j] >= 123) && !(incomingword[j] >= 48 && incomingword[j] <= 57))
				{
					incomingword.erase(j, 1);
					j--;
				}
			}
			//Puts words in our file into the vector
			words.push_back(incomingword);
		}
	}
	else
	{
		cout << "File could not be found";
	}
}

void NeedToEncode::ChangeWordsIntoNumbers(vector <string>& word)
{
	//Takes the words and breaks them down to indiviual letters and converts them to numbers
	for (int i = 0; i < word.size(); i++)
	{
		for (int j = 0; j < word[i].size(); j++)
		{
			convertedwords.push_back(word[i][j]);
		}
	}
}

void NeedToEncode::MostCommonLetterssManipulaor(vector<int>& converted)
{
	//Checks letters and if these letters are in the top 10 most used letters (l,o,v,e,r,m,a,g,n,i) adds a number to them randomly
	for (int i = 0; i < converted.size(); i++)
	{
		if (converted[i] == 101 || converted[i] == 97 || converted[i] == 114 || converted[i] == 105 || converted[i] == 111 || converted[i] == 110 || converted[i] == 108 || converted[i] == 118 || converted[i] == 109 || converted[i] == 103)
		{
			converted[i] = converted[i] + randmonAdder;
		}
	}
}

void NeedToEncode::CreateMatrix(vector <int> convertedwords)
{
	vector<int> temp;
	for (int i = 0; i < convertedwords.size(); i++)
	{
		//creates a row of the matrix
		temp.push_back(convertedwords[i]);
		temp.push_back(0);

		//pushes back the row and starts to creat columns
		matrix.push_back(temp);

		//Need to clear to make sure temp isn't greater than 2
		temp.clear();
	}
}

void NeedToEncode::CreateKeyMatrix(vector <vector <int>> original)
{
	//creates a random 2 x 2 matrix
	vector <int> temp;
	temp.push_back(rand()%100);
	temp.push_back(rand() % 100);
	keyMatrix.push_back(temp);
	temp.clear();
	temp.push_back(rand() % 100);
	temp.push_back(rand() % 100);
	keyMatrix.push_back(temp);
	temp.clear();
}

void NeedToEncode::MultiplyTheMatricies(vector <vector <int>> original, vector <vector <int>> key)
{
	vector <int> temp;

	for (int i = 0; i < original.size(); i++)
	{
		int first = 0;
		int second = 0;
		first = (original[i][0] * key[0][0]) + (original[i][1] * key[1][0]);
		temp.push_back(first);
		second = (original[i][0] * key[0][1]) + (original[i][1] * key[1][1]);
		temp.push_back(second);
		encodedMatrix.push_back(temp);
		temp.clear();
	}

}

void NeedToEncode::Print()
{
	ChangeWordsIntoNumbers(words);
	MostCommonLetterssManipulaor(convertedwords);
	CreateMatrix(convertedwords);
	CreateKeyMatrix(matrix);
	MultiplyTheMatricies(matrix, keyMatrix);

	cout << "Your encoded message is: " << endl;
	for (int i = 0; i < encodedMatrix.size(); i++)
	{
		for (int j = 0; j < encodedMatrix[i].size(); j++)
		{
			cout << encodedMatrix[i][j] << endl;
		}
	}

	cout << endl;

	cout << "Your key is: " << endl;
	for (int i = 0; i < keyMatrix.size(); i++)
	{
		for (int j = 0; j < keyMatrix[i].size(); j++)
		{
			cout << keyMatrix[i][j] << endl;
		}
	}

	cout << endl;

	cout << "Your special number is: " << randmonAdder;

	cout << endl;
}