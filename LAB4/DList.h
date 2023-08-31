/*
 * DList.h
 *
 *  Created on: Jun 6, 2022
 *      Author: FMJ Shawty
 */

#ifndef DLIST_H_
#define DLIST_H_
#include <iostream>
#include <stack>
#include <string>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct node {
	double id;     //Speichert den Wert des Listeneintrags
	node *ptrFollow;   //Zeiger auf das nachfolgende Element in der Liste

};

class DList {
public:

	node *anchor = NULL;  //Zeiger der auf den Kopf der Liste zeigt
	int stacklength = 0;		//Anzahl der Elemente auf dem Stack


	void InsertAsFirstElement(double x);		//Knoten an Anfang setzen
	bool GetAndDeleteFirstElement(double &x);	//Ersten Knoten bekommen und löschen
	void LPrintForward();		//Liste ausgeben
	DList();		//Konstruktor
	virtual ~DList();	//Destruktor


};

#endif /* DLIST_H_ */
