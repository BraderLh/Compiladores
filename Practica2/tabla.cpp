#include "tabla.h"

tabla::tabla()
{
	estado = 0;
	punto = '\0';
	mm = '\0';
	digito = '\0';
	otro = '\0';
}

tabla::tabla(int vestado, char vpunto, char vmm, char vdigito, char votro)
{
	estado = vestado;
	punto = vpunto;
	mm = vmm;
	digito = vdigito;
	otro = votro;
}

void tabla::setEstado(int es)
{
	estado = es;
}

void tabla::setPunto(char p)
{
	//p = '.';
	punto = p;
}

void tabla::setMasMenos(char mms)
{
	//mms = '-';
	mm = mms;
}

void tabla::setDigito(char d)
{
	digito = d;
}

void tabla::setOtro(char o)
{
	otro = o;
}

int tabla::getEstado()
{
	return estado;
}

char tabla::getPunto()
{
	return punto;
}

char tabla::getMm()
{
	return mm;
}

char tabla::getDigito()
{
	return digito;
}

char tabla::getOtro()
{
	return otro;
}

string tabla::toString()
{
	stringstream ss;
	ss << "Estado: " << estado<<endl;
	ss << "Punto: " << punto <<endl;
	ss << "MasMenos: " << mm << endl;
	ss << "Digito: " << digito << endl;
	ss << "Otro: " << otro << endl;
	return ss.str();
}

tabla::~tabla()
{
}
