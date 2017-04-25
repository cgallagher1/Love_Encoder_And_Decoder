#pragma once
#include <iostream>
#include <time.h>
#include <fstream>
#include <ostream>
#include <vector>
#include <string>

using namespace std;

class NeedToDecrypt
{
public:
	NeedToDecrypt();
	void FindDET(vector<vector<float>>& ogkey);
	void CreateInverseKey(vector <vector <float>>& ogkey);
	void MultiplyEncodedByInverse(vector <vector <float>>& encoded, vector <vector <float>>& inverse);
	void SwitchBackSpecialLetters(vector <vector <int>>& multi);
	void Print();
	//~NeedToDecrypt();

private:
	vector<vector<float>> encodedNumers;
	vector <vector<float>> originalKey;
	vector <vector<float>> inverseKey;
	vector <vector<int>> multipliedNumbers;
	vector <int> decodedNumbers;
	vector <char> message;
	float DET;
	int specialNumber;
};


/*NeedToDecrypt::~NeedToDecrypt()
{
}*/