/*
 * Stammbaum.cpp
 *
 *  Created on: Jun 21, 2022
 *      Author: FMJ Shawty
 */
#include <iostream>
#include <stack>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include "Stammbaum.h"
using namespace std;

Stammbaum::Stammbaum() {
	anchor = NULL;

}

Stammbaum::~Stammbaum() {
	// TODO Auto-generated destructor stub
}



void Stammbaum::createNode(string input){
	string x;
	if(input == "r"){
if(anchor == NULL){
	cout << "Wurzel erstellt" << endl;
	tree* root = new tree;
	cout << "Geben Sie Vornamen ein : ";
	cin >> x;
	root->navigation = ">>>";
	root->vorname = x;
	root->eltern = NULL;
	root->depth = 1;
	root->nachname = " Nachname";
	root->mutter = NULL;
	root->vater = NULL;
	anchor = root;
	current = root;
}
else{
	cout << "Wurzel schon erstellt" << endl;
}
	}
	else if(input == "m"){
		if(anchor != NULL){
			tree* mother = new tree;
			cout << "Geben Sie Vornamen ein : ";
			cin >> x;
			mother->vorname = x;
			current->mutter = mother;
			mother->eltern = current;
			mother->nachname = " Nachname";
			mother->mutter = NULL;
			mother->vater = NULL;
		}
		else{
			cout << "Wurzel muss erstellt werden" << endl;
		}
	}
	else if(input == "v"){
		if(anchor != NULL){
			tree* father = new tree;
			cout << "Geben Sie Vornamen ein : ";
			cin >> x;
			father->vorname = x;
			father->nachname = " Nachname";
			current->vater = father;
			father->mutter = NULL;
			father->vater = NULL;
		}
		else{
			cout << "Wurzel muss erstellt werden" << endl;
		}
	}

}


void Stammbaum::navigate(string input){
	if(input == "a"){
		if(current->mutter != NULL){
	current = current->mutter;
	current->navigation = ">>>";
		}
	}
	else if (input == "d"){
		if(current->vater != NULL){
		current = current->vater;
		current->navigation = ">>>";
		}
	}
	else if (input == "w"){
		current = current->eltern;
		current->navigation = ">>>";
	}

}

void Stammbaum::PrintTree(tree* node, int indent){
	tree* temp;
	temp = anchor;
if(anchor != NULL){
	cout << anchor->vorname << endl;

}
while(temp->vater != NULL){
cout << temp->vater->vorname << endl;
temp = temp->vater;
}

}

