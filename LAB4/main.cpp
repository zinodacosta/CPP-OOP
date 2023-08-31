#include <iostream>
#include <stack>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include "DList.h"
#include "DStack.h"
using namespace std;


int main(){
	DStack objectDStack;
	DList objectDList, objectDList1;
	string input;
	double number;
	double valueL = 0;
	double valueR = 0;
	double newValue = 0;
	int counter = 0;
	cout << "RPN Calculator ( Q or X to Exit . P to Output in Reverse)" << endl;
	while (true) {
		cout << ">>";
		cin >> input ;
		if(input == "p"){
			objectDStack.SPrintReverse();
			cout << "Reversed" << endl;
		}
		if(objectDStack.CheckInputType(input) == 3){	//Operand eingegeben
			number = stod(input);		//String Konversion in Double
			objectDStack.Push(number);		//Call Fkt um Zahl auf den Stack zu schieben
			counter++;	//Counter ist die Anzahl der Zahlen im Stack
			}
			else if(objectDStack.CheckInputType(input) == 2){	//Command eingegeben
				cout << "Exiting" << endl;
				exit(0);
			}
			else if(objectDStack.CheckInputType(input) == 1){	//Operator eingegeben
				if (counter > 1) {
				objectDStack.Pop(number);
				valueL = number;
				objectDStack.Pop(number);
				valueR = number;
				counter--;
				if(input == "+"){
				newValue = valueL + valueR;	//Berechnet den Wert aus 1. und 2. Wert im Stack
				objectDStack.Push(newValue);	//Ergebnis wird als 1. Element im Stack abgespeichert
				cout << " = " << newValue << endl;
				}
				else if(input == "-"){
					newValue = valueL - valueR;	//Berechnet den Wert aus 1. und 2. Wert im Stack
					objectDStack.Push(newValue);	//Ergebnis wird als 1. Element im Stack abgespeichert
					cout << " = " << newValue << endl;
				}
				else if(input == "*"){
					newValue = valueL * valueR;	//Berechnet den Wert aus 1. und 2. Wert im Stack
					objectDStack.Push(newValue);		//Ergebnis wird als 1. Element im Stack abgespeichert
					cout << " = " << newValue << endl;
				}
				else if(input == "/"){
					newValue = valueL / valueR;	//Berechnet den Wert aus 1. und 2. Wert im Stack
					objectDStack.Push(newValue);	//Ergebnis wird als 1. Element im Stack abgespeichert
					cout << " = " << newValue << endl;
				}
			}
				else{
					cout << "Not enough Operands" << endl;
			}

			}


	}

	return 0;


}



/**
int main() {
	string input;
	DList node;
	double x;

	cout << "q : Ausgabe der Liste " << endl;
	cout << "w : Zufälliger Wert an Anfang der Liste" << endl;
	cout << "e : Löschen des ersten Knotens " << endl;
	cout << "r :  Programm beenden " << endl;

	while (true) {

		cin >> input;

		if (input == "q") {
			node.LPrintForward();		//Ausgabe der Liste
		}		//if

		if (input == "w") {
			cout << endl;
			x = (rand() & 999);
			node.InsertAsFirstElement(x);	//Eingabe an Anfang der Liste gesetzt
			node.LPrintForward();
			cout << endl;
		}	//if

		if (input == "e"){
		node.GetAndDeleteFirstElement(x);
		node.LPrintForward();
		}

		if (input == "r"){
			node.~DList();
			exit(0);
		}
	}	//while

}	//main
**/
