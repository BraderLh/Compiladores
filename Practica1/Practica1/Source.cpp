#include <iostream>
#include <fstream>
using namespace std;


int main() {
	char letra;
	ifstream ficherote;
	ficherote.open("textoplano.txt", ios::in);
	if (ficherote.is_open()) {
		while (!ficherote.eof()) {
			ficherote >> letra;
			cout << letra << endl;
		}
		ficherote.close();
	}
	else cout << "Fichero inexistente" << endl;
	return 0;
}