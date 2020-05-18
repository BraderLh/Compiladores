#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <iostream>

#define PUNTOYCOMA ';'
#define PARI '('
#define MAYOR '>'
#define MENOR '<'
#define COMA ','
#define ASIGANCION '='
#define MAS '+'
#define MENOS '-'
#define MULTIPLACION '*'
#define DIVISION '/'
#define PARD ')'
#define CORI '['
#define CORD ']'
#define LLAVI '{'
#define LLAVD '}'

#define ID	256
#define NUM 257
#define MAYORIGUAL 258
#define WHILE 259
#define IF 260
#define IGUAL 261
#define DIFERENTE 262
#define MENORIGUAL 263
#define INT 264
#define CHAR 265
#define STRING 266
#define FLOAT 267
#define DOUBLE 268
#define DO 269
#define ELSE 270
#define TRUE 271
#define FALSE 272
#define RETURN 273
#define BREAK 274
#define PRINTF 275
#define COMENT 276

using namespace std;
	
int scaner();
void mostrar(int);
int espalres();
FILE *f;
char lexema[80];

int main(int n, char* pal[])
{
	int token;
	f = stdin;
	if (n == 2)
	{
		#pragma warning(suppress : 4996)
		f = fopen(pal[1], "rt");
		if (f == NULL)
		{
			f = stdin;
		}
	}
	if (f == stdin) {
		cout << "Bienvenido al analizador lexico en C++" << endl;
		cout << "-Pulse Crtl + z para salir\n-Ingrese texto\n"<< endl;
		printf("Ingrese texto: ");
	}
	while (1)
	{
		token = scaner();
		if (token == EOF)
			break;
		mostrar(token);
		cout << endl;
	}
	if (f != stdin)
		fclose(f);
	return 0;
}
int scaner()
{
	int c, i;
	do
	{
		c = fgetc(f);
	} while (isspace(c));

	if (c == EOF)
	{		
		return EOF;
	}
	if (isalpha(c))
		{
			i = 0;
			do
			{
				lexema[i++] = c;
				c = fgetc(f);
			} while (isalnum(c) || c == '_');
			lexema[i] = 0;
			ungetc(c, f);
			i = espalres();

			if (i >= 0) {
				return i;
			}
			return ID;
	}
	if (isdigit(c)) {
		i = 0;
		do
		{
			lexema[i++] = c;
			c = fgetc(f);
		} while (isdigit(c));

		lexema[i] = 0;
		ungetc(c, f);
		return NUM;
	}
	if (ispunct(c))
	{
			if (c == '>') {
				c = fgetc(f);
				if (c == '=')
				{
					lexema[0] = '>';
					lexema[1] = '=';
					lexema[2] = 0;
					return MAYORIGUAL;
				}
				ungetc(c, f);
				return MAYOR;
			}
			if (c == '<') {
				c = fgetc(f);
				if (c == '=')
				{
					lexema[0] = '<';
					lexema[1] = '=';
					lexema[2] = 0;
					return MENORIGUAL;
				}
				ungetc(c, f);
				return MENOR;
			}
			if (c == '=') {
				c = fgetc(f);
				if (c == '=')
				{
					lexema[0] = '=';
					lexema[1] = '=';
					lexema[2] = 0;
					return IGUAL;
				}
				ungetc(c, f);
				return ASIGANCION;
			}
			if (c == '!')
			{
				c = fgetc(f);
				if (c == '=')
				{
					lexema[0] = '!';
					lexema[1] = '=';
					lexema[2] = 0;
					return DIFERENTE;
				}
				ungetc(c, f);
			}
			if (c=='/')
			{
				c = fgetc(f);
				if (c == '*')
				{
					i = 0;
					do
					{
						if (c == '*')
						{
							c = fgetc(f);
							if (c == '/')
								return COMENT;
								
						}
						lexema[i++] = c;
						c = fgetc(f);
						
					} while (isprint(c) || c == '_');
					lexema[i] = 0;
					ungetc(c, f);
					i = espalres();
					if (i >= 0) {
						return i;
					}
					
				}
				else if (c == '/')
				{
					i = 0;
					do
					{
						lexema[i++] = c;
						c = fgetc(f);
					} while (isprint(c) || c == '_');

					lexema[i] = 0;
					ungetc(c, f);
					return COMENT;
				}
				else
				{
					ungetc(c, f);
					return DIVISION;
				}
			}
			return c;
		}
}
int espalres() {
	if (strcmp(lexema, "while") == 0) {
		return WHILE;
	}
	if (strcmp(lexema, "if") == 0)
	{
		return IF;
	}
	if (strcmp(lexema, "int") == 0)
	{
		return INT;
	}
	if (strcmp(lexema, "char") == 0)
	{
		return CHAR;
	}
	if (strcmp(lexema, "string") == 0)
	{
		return STRING;
	}
	if (strcmp(lexema, "float") == 0)
	{
		return FLOAT;
	}
	if (strcmp(lexema, "double") == 0)
	{
		return DOUBLE;
	}
	if(strcmp(lexema, "do") == 0)
	{
		return DO;
	}
	if (strcmp(lexema, "else") == 0)
		return ELSE;
	if (strcmp(lexema, "true") == 0)
		return TRUE;
	if (strcmp(lexema, "false") == 0)
		return FALSE;
	if (strcmp(lexema, "return") == 0)
		return RETURN;
	if (strcmp(lexema, "break") == 0)
		return BREAK;
	if (strcmp(lexema, "printf") == 0)
		return PRINTF;

	return -1;
}
void mostrar(int token) {
	switch (token)
	{
		case ID: printf("token = ID [%s] \n", lexema);
			//cout << lexema << endl;
			break;
		case NUM: printf("token = NUM [%s] \n", lexema); 
			break;
		case IGUAL: printf("token = IGUAL [%s]\n", lexema);
			break;
		case DIFERENTE: printf("token = DIFERENTE [%s]\n", lexema);
			break;
		case MAYORIGUAL: printf("token = MAYORIGUAL [%s]\n",lexema); 
			break;
		case MENORIGUAL: printf("token = MENORIGUAL [%s]\n", lexema);
			break;
		case WHILE: printf("token = WHILE [%s] \n", lexema); 
			break;
		case IF: printf("token = IF [%s] \n", lexema); 
			break;
		case INT: printf("token = INT [%s] \n", lexema);
			break;
		case CHAR: printf("token = CHAR [%s] \n", lexema);
			break;
		case STRING: printf("token = STRING [%s] \n", lexema);
			break;
		case DO: printf("token = DO [%s] \n", lexema);
			break;
		case ELSE: printf("token = ELSE [%s] \n", lexema);
			break;
		case TRUE: printf("token = TRUE [%s] \n", lexema);
			break;
		case FALSE: printf("token = FALSE [%s] \n", lexema);
			break;
		case RETURN: printf("token = RETURN [%s] \n", lexema);
			break;
		case BREAK: printf("token = BREAK [%s] \n", lexema);
			break;
		case PRINTF: printf("token = PRINTF [%s] \n", lexema);
			break;
		case PARI: printf("token = PARI [%c] \n", token); 
			break;
		case PARD: printf("token = PARD [%c] \n", token);
			break;
		case LLAVI: printf("token = LLAVI [%c] \n", token);
			break;
		case LLAVD: printf("token = LLAVD [%c] \n", token);
			break;
		case CORD: printf("token = CORD [%c] \n", token);
			break;
		case CORI: printf("token = CORI [%c] \n", token);
			break;
		case MAYOR: printf("token = MAYOR [%c] \n", token); 
			break;
		case MENOR: printf("token = MENOR [%c] \n", token);
			break;
		case ASIGANCION: printf("token = ASIGNACION [%c] \n", token);
			break;
		case PUNTOYCOMA: printf("token = PUNTOYCOMA [%c]\n",token); 
			break;
		case MENOS: printf("token = MENOS [%c]\n", token);
			break;
		case MAS: printf("token = MAS [%c]\n", token);
			break;
		case MULTIPLACION: printf("token = MULTIPLICACION [%c]\n ", token);
			break;
		case DIVISION: printf("token = DIVISION [%c]\n", token);
			break;
		case COMA: printf("token = COMA [%c]\n", token);
			break;
		case COMENT:
			break;
	}
}


