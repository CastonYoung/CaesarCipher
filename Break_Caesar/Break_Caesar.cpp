// Break_Caesar.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"	//I guess I could copy and paste it over...
#include "Header.h"
#include <iostream>
#include <fstream>
#include <ostream>
#include <string>

using namespace std;

bool ContainsThe(string newtext)//Check if nextext contains the word "the".
{	/*It is probablly best to use lambdas for something like this.
	  The only problems are that lambdas have been hard for me to learn
	  (I learned them when I was learning Mocs which are even more confusing,
	  and as such I get them all confused) and I am not sure there is anything
	  in type string that can take a lambda.*/
	return true;
}

int main()
{	string filename;
	string ciphertext = "";
	string plaintext = "";
	ifstream* fin = nullptr;
	try
	{	cout<< "Enter message or file: ";
		cin >> filename;
		fin = new ifstream(filename);
		if(fin) if (fin->good()) //double if for gaurenteed sequentialization
		{	char achar;
			while(fin->get(achar)) ciphertext += achar;
			fin->close();
		}
		else { ciphertext = filename; }
	}catch(exception error)
	{	if(fin != nullptr)	if(fin->good()) fin->close();
		delete fin;
		cout<< error.what();
	}

	for(int i(0); i < N_CHAR; ++i)
	{	for(int j(0); j < ciphertext.size(); ++j) plaintext += ciphertext[j] + i;
		if (ContainsThe(plaintext)) break;
		plaintext = "";
	}
	if (plaintext == "")
	{	cout<< "Failure: no english text could be identified." <<endl;
		return 0;
	}

    return 0;
}

