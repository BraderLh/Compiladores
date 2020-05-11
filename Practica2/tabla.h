#pragma once

#include <string>
#include <sstream>
#include <vector>
using namespace std;

class tabla
{
public:
	tabla();
	tabla(int, char, char, char, char);
	void setEstado(int);
	void setPunto(char);
	void setMasMenos(char);
	void setDigito(char);
	void setOtro(char);

	int getEstado();
	char getPunto();
	char getMm();
	char getDigito();
	char getOtro();
	string toString();
	virtual ~tabla();
private:
	int estado;
	char punto;
	char mm;
	char digito;
	char otro;
};

