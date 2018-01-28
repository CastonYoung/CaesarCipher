// main.cpp : Defines the entry point for the console application.

#include  "stdafx.h"
#include "_stdafx.h"
#include <fstream>
#include "caesaralgo.h"
#include <cstdlib>

using namespace std;

int main()
{	//string filename;


	// Code assistance from http://www.cplusplus.com/forum/beginner/21033/
	int choice;
	auto programRun = true;
	while (programRun) 
	{
		cout << "*************CaesarCipher************\n";
		cout << " 1 - Encrypt\n";
		cout << " 2 - Decrypt\n";
		cout << " 3 - Exit\n";
		cout << " Enter your choice and press return: ";

		cin >> choice;


		switch (choice)
		{
		case 1:
			{
				string plaintext = "";

				ifstream* fin = nullptr;
				try
				{	fin = new ifstream("plaintextfile.txt");
					char achar;
					while(fin->get(achar)) plaintext += achar;
					fin->close();
				}
				catch(exception error)
				{	if(fin != nullptr)	if(fin->good()) fin->close();
					delete fin;
					cout<< error.what();
				}


				char* cStrPlain = new char[strlen(plaintext.c_str())];
				char* ciphertext = new char[strlen(plaintext.c_str()) + 1];

				strcpy_s(cStrPlain, strlen(plaintext.c_str()) + 1 , plaintext.c_str());
				
				//Routines to make sure plaintext is all lowercase

				for (size_t currentChar{}; currentChar < sizeof(cStrPlain) + 1; currentChar++)
				{
					char c = cStrPlain[currentChar];
					if (isalpha(c) && !isspace(c))
					{
						c = tolower(c);
						cStrPlain[currentChar] = c;
					}
				}

				int key{};

				cout << " Enter Key: ";
				cin >> key;


				Caesar_En(cStrPlain, ciphertext, key);
				fstream cipherStream;
				cipherStream.open("ciphertextfile.txt", ios::out | ios::trunc);
				cipherStream << ciphertext;
				cipherStream.close();

				//delete[] ciphertext;
				//delete[] cStrPlain;

				cout << "\n Encryption Sucessful! \n";

				break;
			}
		case 2:
			{
				int key{};

				cout << " Enter Key: \n";
				cin >> key;

				char* ciphertext = nullptr;

				//Caesar_De(ciphertext, plaintext.c_str(), key);
				fstream plainStream;
				plainStream.open("ciphertextfile.txt");
				plainStream << ciphertext;
				plainStream.close();

				break;
			}
		case 3:
			{
				cout << "End of Program.\n";
				programRun = false;
				break;
			}
		default:
			{
				cout << "Not a Valid Choice. \n";
				cout << "Choose again.\n";
				cin >> choice;
				break;
			}
		}
	}
	return 0;
}