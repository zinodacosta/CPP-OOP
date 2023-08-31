//============================================================================
// Name        : dlist.cpp
// Author      : Zino da Costa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "dlist.h"
using namespace std;

DList::DList(void){	//Konstruktor der nach jeder
//    cout << "Konstruktor DList aufgerufen" << endl;
stacklength = 0;

}


DList::~DList(void) {
//   cout << "Destruktor ~DList aufgerufen" << endl;
    delete anchor;
}

void DList::InsertAsFirstElement(double x) {
	stacklength++;
    node* new_node = new node;		//Erstellt neuen Knoten für die Liste
    new_node->ptrFollow = anchor;	//Setzt ptr auf Kopf der Liste
    new_node->id = x;							//Uebertraegt Wert auf Knoten
    anchor = new_node;						//Knoten wird an den Anfang gesetzt


}//fkt

bool DList::GetAndDeleteFirstElement(double& x) {
    bool check = false;     //Liste leer
    node* temp = anchor;	//temp ptr
    DList DList;		//objekt deklarierung
    if (anchor == NULL) {		//falls liste leer
        check = false;
    }//if
    else {
    	check = true;		//Liste nicht leer
    	x = anchor->id;		//übertrage wert
    	temp = anchor->ptrFollow;	//übertrage ptr des 2. elements auf temp
    	anchor = temp;	//setze anchor auf das nächste element
    	DList.~DList();
    }
    stacklength--;
    return check;
}//fkt

void DList::LPrintForward(){
	node* ptr = anchor;			//temporärer ptr um die Liste zu traversieren

	for (int i=0; i<stacklength; i++){
		cout << "---->" << ptr->id<< endl;
		ptr = ptr->ptrFollow;
	}


}


