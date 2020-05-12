
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <ctype.h>
#include <sstream>
#include <stdio.h>
using namespace std;

bool esSeparador(char c) {
	bool es = false;
	vector<char> separador{ ' ','\t','\n' };
	for (auto i = separador.begin(); i != separador.end(); ++i)
	{
		if (c == *i) {
			es = true;
		}
	}
	return es;

}
bool esCaracter(char& d) {
	bool cr = false;
	vector<char> jamas;

	if (isdigit(d)) {
		cout << " digito ";
		cr = true;
	}
	else if (isalpha(d)) {
		cout << " letra ";
		cr = true;
		jamas.push_back(d);
	}
	else if (ispunct(d)) {
		cout << " caracter especial ";
		cr = true;
	}
	else {
		cr = false;
	}

	return cr;

}
int main()
{
	char x = '\0';
	bool p = false;
	ifstream inFile("textoplano.txt");
	//inFile.seekg(2, ios::beg);
	string lines;
	vector<string> tokens;
	string intermediate;

	if (!inFile) {
		cout << "No se puedo abrir el texto";
		exit(1);
	}
	else {
		while (inFile.get(x) && !inFile.eof()) {
			if (esSeparador(x)) {
				cout << "SeparadoR";
			}
			else {
				if (esCaracter(x)) {
					cout << " ";
				}
			}

		}
	}
	inFile.close();

}

