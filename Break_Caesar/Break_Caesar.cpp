// Break_Caesar.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"	//I guess I could copy and paste it over...
#include "Header.h"
#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <stdlib.h>

using namespace std;

bool ContainsThe(string newtext)//Check if nextext contains the word "the".
{	if(newtext.find("THE", 0) != string::npos) return true;
	//if(newtext.find("The", 0) != string::npos) return true;
	//if(newtext.find("the", 0) != string::npos) return true;
	//if(newtext.find("ThE", 0) != string::npos) return true;
	//if(newtext.find("THe", 0) != string::npos) return true;
	//if(newtext.find("tHe", 0) != string::npos) return true;
	return false;
}

int main()
{	
	while (true)
	{
		string filename;
		string ciphertext = "";
		string plaintext = "";
		ifstream* fin = nullptr;
		try
		{
			cout << "Enter message or file: ";
			cin >> filename;
			fin = new ifstream(filename);
			if (fin) if (fin->good()) //double if for gaurenteed sequentialization
			{
				char achar;
				while (fin->get(achar)) ciphertext += achar;
				fin->close();
			}
			else { ciphertext = filename; }
		}
		catch (exception error)
		{
			if (fin != nullptr)	if (fin->good()) fin->close();
			delete fin;
			cout << error.what();
		}

		for (int i(0); i < N_CHAR; ++i)
		{
			for (int j(0); j < ciphertext.size(); ++j)
			{
				if (ciphertext[j] < MINVAL || ciphertext[j] > MAXVAL)	plaintext += ciphertext[j];
				else plaintext += ciphertext[j] + i;
			}
			if (ContainsThe(plaintext)) break;
			plaintext = "";
		}

		if (plaintext == "")
		{
			cout << "Failure: no english text could be identified." << endl;

			system("PAUSE");
			system("CLS");

			//return 0;
		}
		else
		{
			fstream plainStream;
			plainStream.open("plaintextfile.txt", ios::out | ios::trunc);
			plainStream << plaintext;
			plainStream.close();

			cout << "Possible original text found, see plaintextfile.txt" << endl;

			system("PAUSE");
			system("CLS");
		}

	}
    return 0;

}

