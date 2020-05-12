
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <ctype.h>
#include <sstream>
#include <stdio.h>
using namespace std;

void mostrar(vector<char> c)
{
	for (auto i = c.begin(); i != c.end(); ++i)
		cout << *i;
}
void cifrado(vector<char>& c, int& t, int& dc) {
	cout << "\nTexto codificado:" << endl;
	int aux = 0;
	for (int i = 0; i < t; i++) {
		aux = c[i];

		if (aux + dc > 122) {
			aux = ((aux + dc) - 122) + 96;
		}
		else if (aux < 32)
		{
			if (aux == 9)
				aux = '\t';
			if (aux == 10)
				aux = '\n';
		}
		else
		{
			aux = aux + dc;

		}
		if (c[i] != ' ') {
			c[i] = aux;
		}
	}
	mostrar(c);
}
void descifrado(vector<char>& c, int& t, int& dd)
{
	cout << "\nTexto descodificado:\n";
	int aux = 0;
	for (int j = 0; j < t; j++) {
		aux = c[j];
		if (aux < 32)
		{
			if (aux == 9)
			{
				aux = '\t';
			}
			else if (aux == 10)
			{
				aux = '\n';
			}
			else {
				aux = 122 - ((122 - (aux - dd)));
			}

		}
		else
		{
			if (aux < 97 + dd && aux >= 97) {
				aux = 123 - (97 - (aux - dd));
			}
			else {
				aux = aux - dd;
			}
			
		}
		if (c[j] != ' ')
		{
			c[j] = aux;
		}
	}
	mostrar(c);
}

int main()
{
	char texto;
	vector<char> ga;
	int des = 3;
	int i = 0;
	int tam = 0;
	ifstream myfile("pseudocodigo.txt");

	if (myfile.fail()) {
		cerr << "Error al abrir el archivo Pruebas.txt" << endl;
	}
	else {
		while (myfile.get(texto) && !myfile.eof())
		{
			ga.push_back(texto);
		}
		myfile.close();
	}
	cout << "\nPseudocodigo:\n ";
	tam = ga.size();
	cifrado(ga, tam, des);
	descifrado(ga, tam, des);
	return 0;

}

