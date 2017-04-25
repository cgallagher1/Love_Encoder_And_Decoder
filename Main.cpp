#include <iostream>
#include <time.h>
#include <fstream>
#include <ostream>
#include <vector>
#include <string>
#include "Encoder.h"
#include "Decoder.h"

using namespace std;

int main()
{
	srand(time(0));

	string nameOfFile;
	string needMore;
	string likeToDo;


	cout << "Would you like to encrypt or decrypt a message: ";
	cin >> likeToDo;
	cout << endl;

	if (likeToDo == "encrypt")
	{
		//Grabs name of the file that will be passed into the encoder
		cout << "What is the name of the file you would like to encrypt: ";
		cin >> nameOfFile;
		cout << endl;

		//Promts the encoder to begin
		NeedToEncode FileToEncode(nameOfFile);
		FileToEncode.Print();

		//In case there are multiple messages
		cout << "Do you have another message to encrypt ot decrypt (y/n): ";
		cin >> needMore;
		while (needMore == "y")
		{
			cout << "Would you like to encrypt or decrypt the message: ";
			cin >> likeToDo;
			cout << endl;

			if (likeToDo == "encrypt")
			{
				//Grabs name of the file that will be passed into the encoder
				cout << "What is the name of the file you would like to encrypt: ";
				cin >> nameOfFile;
				cout << endl;

				//Promts the encoder to begin
				NeedToEncode FileToEncode(nameOfFile);
				FileToEncode.Print();

				//In case there are multiple messages
				cout << "Do you have another message to encrypt ot decrypt (y/n): ";
				cin >> needMore;
			}
			else
			{
				//Promts the decoder to begin
				NeedToDecrypt ToDecrypt;
				ToDecrypt.Print();
				//In case there are multiple messages
				cout << "Do you have another message to encrypt ot decrypt (y/n): ";
				cin >> needMore;
			}
		}
	}
	else
	{
		//Promts the decoder to begin
		NeedToDecrypt ToDecrypt;
		ToDecrypt.Print();
		//In case there are multiple messages
		cout << "Do you have another message to encrypt ot decrypt (y/n): ";
		cin >> needMore;
		while (needMore == "y")
		{
			cout << "Would you like to encrypt or decrypt the message: ";
			cin >> likeToDo;
			cout << endl;

			if (likeToDo == "encrypt")
			{
				//Grabs name of the file that will be passed into the encoder
				cout << "What is the name of the file you would like to encrypt: ";
				cin >> nameOfFile;
				cout << endl;

				//Promts the encoder to begin
				NeedToEncode FileToEncode(nameOfFile);
				FileToEncode.Print();

				//In case there are multiple messages
				cout << "Do you have another message to encrypt ot decrypt (y/n): ";
				cin >> needMore;
			}
			else
			{
				//Promts the decoder to begin
				NeedToDecrypt ToDecrypt;
				ToDecrypt.Print();
				//In case there are multiple messages
				cout << "Do you have another message to encrypt ot decrypt (y/n): ";
				cin >> needMore;
			}
		}

	}

	system("pause");
	return 0;
}