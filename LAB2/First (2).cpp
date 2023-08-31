//============================================================================
// Name        : OOPLab2.cpp
// Author      : Zino da Costa
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include <iostream>
#include <stack>
#include <string>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int length = 0;
const int stacklength = 5;
double Stack[stacklength];	//Initialisiert einen Stack in Form eines Arrays
double* ptr = &Stack[0] - 1;	//Initialisiert Pointer um auf den Stack zu zeigen
bool empty = true;
enum checkdoublen {
	Start, Vorzeichen, Vorkommaziffer, Komma, Nachkommaziffer, Exponent, Exponentvorzeichen,
	Exponentenziffer, Error
}Zustand;
enum typ {Operator, Operand, Error2, Command}Type; //Definition Enum der Eingaben

void stack_print() { //Gibt den Stack auf der Konsole aus
	for (double *p = &Stack[0] ; p <= ptr; p++) {
		cout << *p << endl;
	}
}

bool CheckDoubleNumber(string input) {
	bool check = 0;
	for (unsigned int i = 0; i < input.size(); i++) {

		switch (Zustand) {
		case Start:
			if (input[i] == '+' || input[i] == '-') {
				check = 0;
				Zustand = Vorzeichen;
				break;
			}
			else if (isdigit(input[i])) {
				check = 1;
				Zustand = Vorkommaziffer;
				break;
			}
			else {
				check = 0;
				Zustand = Error;
				break;
			}
		case Vorzeichen:
			if (input[i] == '0' || input[i] == '1' || input[i] == '2' || input[i] == '3' || input[i] == '4'
				|| input[i] == '5' || input[i] == '6' || input[i] == '7' || input[i] == '8' || input[i] == '9') {
				check = 1;
				Zustand = Vorkommaziffer;
				break;
			}
			else {
				Zustand = Error;
				break;
			}

		case Vorkommaziffer:
			if (input[i] == '0' || input[i] == '1' || input[i] == '2' || input[i] == '3' || input[i] == '4'
				|| input[i] == '5' || input[i] == '6' || input[i] == '7' || input[i] == '8' || input[i] == '9') {
				check = 1;
				Zustand = Vorkommaziffer;
				break;
			}
			else if (input[i] == 'e') {
				check = 0;
				Zustand = Exponent;
				break;
			}
			else if (input[i] == '.') {
				Zustand = Komma;
				check = 0;
				break;
			}
			else {
				Zustand = Error;
				break;
			}
		case Komma:
			if (input[i] == '0' || input[i] == '1' || input[i] == '2' || input[i] == '3' || input[i] == '4'
				|| input[i] == '5' || input[i] == '6' || input[i] == '7' || input[i] == '8' || input[i] == '9') {
				check = 1;
				Zustand = Nachkommaziffer;
				break;
			}
			else {
				Zustand = Error;
				break;
			}
		case Nachkommaziffer:
			if (input[i] == '0' || input[i] == '1' || input[i] == '2' || input[i] == '3' || input[i] == '4'
				|| input[i] == '5' || input[i] == '6' || input[i] == '7' || input[i] == '8' || input[i] == '9') {
				check = 1;
				Zustand = Nachkommaziffer;
				break;
			}
			else if (input[i] == 'e') {
				Zustand = Exponent;
				check = 0;
				break;
			}
			else {
				break;
			}
		case Exponent:
			if (input[i] == '+' || input[i] == '-') {
				check = 0;
				Zustand = Exponentvorzeichen;
				break;
			}
			else {
				Zustand = Error;
				break;
			}
		case Exponentvorzeichen:
			if (input[i] == '0' || input[i] == '1' || input[i] == '2' || input[i] == '3' || input[i] == '4'
				|| input[i] == '5' || input[i] == '6' || input[i] == '7' || input[i] == '8' || input[i] == '9') {
				check = 1;
				Zustand = Exponentenziffer;
				break;
			}
			else {
				Zustand = Error;
				break;
			}
		case Exponentenziffer:
			if (input[i] == '0' || input[i] == '1' || input[i] == '2' || input[i] == '3' || input[i] == '4'
				|| input[i] == '5' || input[i] == '6' || input[i] == '7' || input[i] == '8' || input[i] == '9') {
				check = 1;
				Zustand = Exponentenziffer;
				break;
			}
			else {
				Zustand = Error;
				break;
			}
		case Error:
			check = 0;
			break;



		}//switch

	}//for

	return check;

}//function



void CheckInputType(string input) {

	if (input== "+" || input == "-"|| input == "/" || input == "*") {
		Type = Operator;
	}
	else if (input == "q" || input == "x") {
		Type = Command;
	}

	else if (CheckDoubleNumber(input)) {
		Type = Operand;
	}
	else{
		Type = Error2;
	}

}	//fkt

bool stack_push(double pushval) {	//Fkt um eine Zahl auf den Stack zu schieben
	bool pushed;
	if (ptr == &Stack[stacklength - 1]) {	//Falls der Stack voll ist cout "Full Stack"
		cout << "Full Stack" << endl;
		pushed = false;
	}
	else {
		ptr++;
		*ptr = pushval;	//Falls nicht schiebt er die Zahl auf den Stack
		pushed = true;

	}

	return pushed;
}

bool stack_pop(double* popval) {
	bool popped;

	if (ptr == &Stack[0] - 1) {	//Falls der Stack leer ist
		popped = false;
	}
	else {
		*popval = *(ptr);
		popped = true;
		ptr--;
	}

	return popped;
}





int main() {
	string input;
	double number;
	double valueL = 0;
	double valueR = 0;
	double newValue = 0;
	int counter = 0;
	cout << "RPN Calculator ( Q or X to Exit)" << endl;
	while (true) {
		cout << ">>";
		getline(cin, input);	//Speichert den Input in Variable input ab
		length = input.size();	//Erf‰hrt die Zeichenl‰nge des Inputs
		CheckInputType(input);
			if(Type == Operand){
			number = stod(input);		//String Konversion in Double
			//cout << number << endl;
			stack_push(number);
			stack_print();
			counter++;	//Counter ist die Anzahl der Zahlen im Stack
			}
			else if(Type == Command){
				cout << "Exiting" << endl;
				return 0;
			}
			else if(Type == Operator){
			if (counter > 1) {
				stack_pop(&valueR);
				stack_pop(&valueL);
				counter--;
				if(input == "+"){
				newValue = valueL + valueR;	//Berechnet den Wert aus 1. und 2. Wert im Stack
				cout << "= " << newValue << endl;
				stack_push(newValue);	//Ergebnis wird als 1. Element im Stack abgespeichert
				}
				else if(input == "-"){
					newValue = valueL - valueR;	//Berechnet den Wert aus 1. und 2. Wert im Stack
					cout << "= " << newValue << endl;
					stack_push(newValue);	//Ergebnis wird als 1. Element im Stack abgespeichert
				}
				else if(input == "*"){
					newValue = valueL * valueR;	//Berechnet den Wert aus 1. und 2. Wert im Stack
					cout << "= " << newValue << endl;
					stack_push(newValue);	//Ergebnis wird als 1. Element im Stack abgespeichert
				}
				else if(input == "/"){
					newValue = valueL / valueR;	//Berechnet den Wert aus 1. und 2. Wert im Stack
					cout << "= " << newValue << endl;
					stack_push(newValue);	//Ergebnis wird als 1. Element im Stack abgespeichert
				}
				stack_print();
			}
			}
			else {
				cout << "Not enough Operands" << endl;
			}



	}
	return 0;


}
