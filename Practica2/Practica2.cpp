
#include <iostream>
#include <ctype.h>
#include "tabla.h"
#include <fstream>
#include <chrono>
#include <thread>
#include <iomanip>
using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

enum class Estado { q0, q1, q2, q3, q4, ERROR};
char reconocerNumero(const string& cadena);
void verificador(char);
void escribir();
void leer();
int main()
{
	string cadena;
	cout << "Analizador lexico"<<endl;
	cout << endl;
	cout << "Ingrese un numero(s):";
	cin >> cadena;
	//escribir();
	leer();
	const char ultimo = reconocerNumero(cadena);
	verificador(ultimo);
	system("pause");
	system("cls");
	main();
	return 0;
}
void verificador(char u) {
	const char q2 = '2';
	const char q4 = '4';
	cout << "\nVerificando...";
	sleep_for(seconds(1));
	if (u == q2) {
		cout << "\nCadena aceptada" << endl;
	}
	else if (u == q4) {
		cout << "\nCadena aceptada" << endl;
	}
	else {
		cerr << "\nError" << endl;
		cerr << "Vuelva a Intentarlo..." << endl;
	}
}
void escribir()
{
	int est;
	char mm, pt, di, ot;
	tabla mitabla;
	ofstream textabla;
	textabla.open("tabla.txt", ios::app);

	if (!textabla)
	{
		cerr << "No se pudo abrir el archivo" << endl;
		exit(1);
	}
	else {
		cout << "Ingrese el numero de un estado: \n";
		cout << "Estado: ";
		cin >> est;

		while (est >= 0 && est <= 5)
		{
			cout << "+/- ";
			cin >> setw(15) >> mm;
			cout << ". ";
			cin >> setw(10) >> pt;
			cout << "digito ";
			cin >> setw(10) >> di;
			cout << "otro ";
			cin >> ot;

			mitabla.setEstado(est);
			mitabla.setMasMenos(mm);
			mitabla.setPunto(pt);
			mitabla.setOtro(ot);

			textabla.seekp((mitabla.getEstado()) * sizeof(tabla));

			textabla << est << "\t\t" << mm << "\t\t" << pt << "\t\t" << di << "\t\t" << ot << endl;

			cout << "Escriba un estado: ";
			cin >> est;
		}
	}
}
void leer() {
	ifstream inFile("tabla.txt");
	char x = '\0';
	cout << left << setw(8) << "Est/Entr" << "\t.,-\t" << "\t.\t" << "\tdigito\t" << right << "\tOtro" << endl;
	cout << "_____________________________________________________________________________" << endl;
	if (!inFile) {
		cerr << "No se puedo abrir el texto";
		exit(1);
	}
	else {
		while (inFile.get(x) && !inFile.eof())
		{
			cout << x;
		}
	}

}
char reconocerNumero(const string& inputString)
{
	ifstream inFile("tabla.txt");
	char x = '\0';
	if (!inFile) {
		cout << "No se puedo abrir el texto";
		exit(1);
	}
	else {
		unsigned int pos = 0;
		const char  q0 = '0';
		const char q1 = '1';
		const char q2 = '2';
		const char q3 = '3';
		const char q4 = '4';
		const char ERROR = '5';
		bool cadenaRechazada = false;

		while (inFile.get(x) && !inFile.eof()) {
			char actual = x;
			while (not cadenaRechazada and pos < inputString.length()) {
				char simbolo = inputString[pos];
				switch (actual) {
				case q0:
					if (isdigit(simbolo)) {
						actual = q2;
					}
					else if (simbolo == '+' or simbolo == '-' or simbolo == '.') {
						actual = q1;
					}
					else {
						cadenaRechazada = true;
					}
					break;
				case q1:
					if (isdigit(simbolo)) {
						actual = q2;
					}
					else if (simbolo == '.' || simbolo == ',') {
						actual = q3;
					}
					else {
						cadenaRechazada = true;
					}
					break;
				case q3:
					if (isdigit(simbolo)) {
						actual = q4;
					}
					else {
						cadenaRechazada = true;
					}
					break;
				case q2:
					if (isdigit(simbolo)) {
						actual = q2;
					}
					else if (simbolo == '.' || simbolo == ',') {
						actual = q3;
					}
					else {
						cadenaRechazada = true;
					}
					break;
				case q4:
					if (isdigit(simbolo)) {
						actual = q4;
					}
					else {
						cadenaRechazada = true;
					}
					break;
				default:
					break;
				}
				pos++;
			}
			if (cadenaRechazada) {
				 actual=ERROR;
			}
			return actual;
		}
	}
}





