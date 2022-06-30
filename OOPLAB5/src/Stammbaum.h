/*
 * Stammbaum.h
 *
 *  Created on: Jun 21, 2022
 *      Author: FMJ Shawty
 */

#ifndef STAMMBAUM_H_
#define STAMMBAUM_H_
#include <stack>
#include <string>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
class Stammbaum {
protected:
	struct tree {
		string vorname;
		string nachname;
		tree* mutter;	//vorlaufender ptr
		tree* vater;	//vorlaufender ptr
		tree* eltern;	//rücklaufender ptr
		string navigation; //>>> oder /-- oder \--
		int depth = 0; //tiefe des baumes
	};

	tree* anchor = NULL;	//ptr auf die wurzel
	tree* current = NULL;	//ptr auf den aktuellen knoten

public:
	Stammbaum();
	virtual ~Stammbaum();
	void PrintTree(tree* node, int indent);
	void createNode(string input);
	void navigate(string input);


};

#endif /* STAMMBAUM_H_ */
