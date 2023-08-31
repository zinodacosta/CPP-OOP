/*
 * DStack.cpp
 *
 *  Created on: Jun 6, 2022
 *      Author: FMJ Shawty
 */

#include "DStack.h"
#include "DList.h"
#include <iostream>
#include <stack>
#include <string>
#include <stdlib.h>
#include <stdio.h>
using namespace std;


enum checkdoublen {
	Start, Vorzeichen, Vorkommaziffer,
	Komma, Nachkommaziffer,
	Exponent, Exponentvorzeichen,
	Exponentenziffer, Error
}Zustand;

enum typ {Operator, Operand, Error2, Command
}Type;


void DStack::Push(double x) {		//Fkt um Wert auf den Stack zu schieben
	node* ptrNext = anchor;
	if (stacklength == 0){
		InsertAsFirstElement(x);		//falls der stack leer ist
	}//if
	else if (stacklength > 0){
		for(int i=0; i<stacklength-1; i++){
			ptrNext = ptrNext->ptrFollow;
		}//for
		node *new_node = new node;
		ptrNext->ptrFollow = new_node;
		new_node->id = x;
		stacklength++;
	}//elseif
	LPrintForward();
	}//fkt

bool DStack::Pop(double &x) {		//Fkt um Wert aus den Stack zu nehmen
	bool popped = true;	//Stack leer oder nicht
	if (stacklength == 0) {
		cout << "Stack ist leer" << endl;
		popped = false;
	}
	else {
		GetAndDeleteFirstElement(x);
		popped = true;
	}

	return popped;

}


void DStack::SPrintReverse(){
RecursiveCall(anchor);
}

node* DStack::RecursiveCall(node* head){
if(head == NULL || head->ptrFollow == NULL){
	LPrintForward();
	return head;
}

node* recursive(RecursiveCall(head->ptrFollow));
head->ptrFollow->ptrFollow = head;
head->ptrFollow = NULL;
return recursive;

}

DStack::DStack() {		//Konstruktor
	stacklength = 0;
//	cout << "Konstruktor DStack aufgerufen" << endl;
}

DStack::~DStack() {		//Destruktor
//	cout << "Destruktor ~DStack aufgerufen" << endl;
}

bool DStack::CheckDoubleNumber(string input) {//Fkt um auf gültige Zahl zu prüfen
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

int DStack::CheckInputType(string input) {	//Fkt um auf gütlige Eingabe zu Prüfen
	int inputType = 0;
	if (input== "+" || input == "-"|| input == "/" || input == "*") {
		inputType = 1;
		Type = Operator;
	}
	else if (input == "q" || input == "x") {
		inputType = 2;
		Type = Command;
	}

	else if (CheckDoubleNumber(input)) {
		inputType = 3;
		Type = Operand;
	}
	else{
		inputType = 4;
		Type = Error2;
	}

return inputType;

}//fkt

