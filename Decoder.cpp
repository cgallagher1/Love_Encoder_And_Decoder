#include <iostream>
#include <time.h>
#include <fstream>
#include <ostream>
#include <vector>
#include <string>
#include "Decoder.h"

using namespace std;

NeedToDecrypt::NeedToDecrypt()
{
	int howMany;
	cout << "How many numbers would you like decrypted: ";
	cin >> howMany;
	cout << endl;

	//Creates the encrypted matrix
	vector <float> temp;
	for (int i = 0; i < howMany; i++)
	{
		float numberToBeDecoded;
		cout << "Please enter number: ";
		cin >> numberToBeDecoded;
		temp.push_back(numberToBeDecoded);
		if (temp.size() == 2)
		{
			encodedNumers.push_back(temp);
			temp.clear();
		}
	}
	cout << endl;
	//Creates the original key matrix
	int totalKey;
	cout << "How many numbers are in your key: ";
	cin >> totalKey;
	cout << endl;
	vector <float> secondtemp;
	for (int i = 0; i < totalKey; i++)
	{
		float numberToBeDecoded;
		cout << "Please enter in Key number by number: ";
		cin >> numberToBeDecoded;
		secondtemp.push_back(numberToBeDecoded);
		if (secondtemp.size()==2)
		{
			originalKey.push_back(secondtemp);
			secondtemp.clear();
		}
	}
	cout << endl;
	cout << "What was your special number: ";
	cin >> specialNumber;
	cout << endl;
}

void NeedToDecrypt::FindDET(vector<vector<float>>& ogkey)
{
	DET = 1.00 / ((ogkey[0][0] * ogkey[1][1]) - (ogkey[0][1] * ogkey[1][0]));
}

void NeedToDecrypt::CreateInverseKey(vector <vector <float>>& ogkey)
{
	// Creates 
	vector <float> rows;
	float r1c1 = (originalKey[0][0]);
	float r1c2 = (originalKey[0][1]);
	float r2c1 = (originalKey[1][0]);
	float r2c2 = (originalKey[1][1]);

	//switches a and d
	float temp = r1c1;
	r1c1 = r2c2;
	r2c2 = temp;

	//Switches sign on b and c
	r1c2 = -(r1c2);
	r2c1 = -(r2c1);

	//First Row of inverse key
	r1c1 = r1c1 * DET;
	rows.push_back(r1c1);
	r1c2 = r1c2 * DET;
	rows.push_back(r1c2);
	inverseKey.push_back(rows);
	rows.clear();

	//Second Row of inverse key
	r2c1 = r2c1 * DET;
	rows.push_back(r2c1);
	r2c2 = r2c2 * DET;
	rows.push_back(r2c2);
	inverseKey.push_back(rows);
	rows.clear();
}

void NeedToDecrypt::MultiplyEncodedByInverse(vector <vector <float>>& encoded, vector <vector <float>>& inverse)
{
	vector <int> temp;
	for (int i = 0; i < encoded.size(); i++)
	{
		float first = 0;
		float second = 0;
		first = (encoded[i][0] * inverse[0][0]) + (encoded[i][1] * inverse[1][0]);
		temp.push_back(first);
		second = (encoded[i][0] * inverse[0][1]) + (encoded[i][1] * inverse[1][1]);
		temp.push_back(second);
		multipliedNumbers.push_back(temp);
		temp.clear();
	}
}

void NeedToDecrypt::SwitchBackSpecialLetters(vector <vector <int>>& multi)
{
	for (int i = 0; i < multi.size(); i++)
	{
		int temp = multi[i][0];
		if ((temp - specialNumber) == 101)
		{
			temp = 101;
			decodedNumbers.push_back(temp);
		}
		else if ((temp - specialNumber) == 97)
		{
			temp = 97;
			decodedNumbers.push_back(temp);
		}
		else if ((temp - specialNumber) == 114)
		{
			temp = 114;
			decodedNumbers.push_back(temp);
		}
		else if ((temp - specialNumber) == 105)
		{
			temp = 105;
			decodedNumbers.push_back(temp);
		}
		else if ((temp - specialNumber) == 111)
		{
			temp = 111;
			decodedNumbers.push_back(temp);
		}
		else if ((temp - specialNumber) == 110)
		{
			temp = 110;
			decodedNumbers.push_back(temp);
		}
		else if ((temp - specialNumber) == 108)
		{
			temp = 108;
			decodedNumbers.push_back(temp);
		}
		else if ((temp - specialNumber) == 118)
		{
			temp = 118;
			decodedNumbers.push_back(temp);
		}
		else if ((temp - specialNumber) == 109)
		{
			temp = 109;
			decodedNumbers.push_back(temp);
		}
		else if ((temp - specialNumber) == 103)
		{
			temp = 103;
			decodedNumbers.push_back(temp);
		}
		else
		{
			decodedNumbers.push_back(temp);
		}
	}
}

void NeedToDecrypt::Print()
{
	FindDET(originalKey);
	CreateInverseKey(originalKey);
	MultiplyEncodedByInverse(encodedNumers, inverseKey);
	SwitchBackSpecialLetters(multipliedNumbers);

	for (int i = 0; i < decodedNumbers.size(); i++)
	{
		char temp;
		temp = decodedNumbers[i];
		message.push_back(temp);
	}

	cout << "Your message is: " << endl;

	for (int i = 0; i < message.size(); i++)
	{
		cout << message[i] << " ";
	}
	cout << endl;
}