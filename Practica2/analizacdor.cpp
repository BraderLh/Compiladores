/*unsigned int pos = 0;
	Estado actual = Estado::q0;
	bool cadenaRechazada = false;
	while (not cadenaRechazada and pos < inputString.length()) {
		char simbolo = inputString[pos];
		switch (actual) {
		case Estado::q0:
			if (isdigit(simbolo)) {
				actual = Estado::q2;
			}
			else if (simbolo == '+' or simbolo == '-' or simbolo == '.') {
				actual = Estado::q1;
			}
			else {
				cadenaRechazada = true;
			}
			break;
		case Estado::q1:
			if (isdigit(simbolo)) {
				actual = Estado::q2;
			}
			else if (simbolo == '.' || simbolo==',') {
				actual = Estado::q3;
			}
			else {
				cadenaRechazada = true;
			}
			break;
		case Estado::q3:
			if (isdigit(simbolo)) {
				actual = Estado::q4;
			}
			else {
				cadenaRechazada = true;
			}
			break;
		case Estado::q2:
			if (isdigit(simbolo)) {
				actual = Estado::q2;
			}
			else if (simbolo == '.'	|| simbolo == ',') {
				actual = Estado::q3;
			}
			else {
				cadenaRechazada = true;
			}
			break;
		case Estado::q4:
			if (isdigit(simbolo)) {
				actual = Estado::q4;
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
	*/