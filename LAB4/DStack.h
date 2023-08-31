/*
 * DStack.h
 *
 *  Created on: Jun 6, 2022
 *      Author: FMJ Shawty
 */

#ifndef DSTACK_H_
#define DSTACK_H_
#include <stack>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include "DList.h"
using namespace std;


class DStack: public DList {
public:
	void Push(double x);
	bool Pop(double &x);
	DStack();
	virtual ~DStack();
	bool CheckDoubleNumber(string input);
	int CheckInputType(string input);
	void SPrintReverse();
	node* RecursiveCall(node* head);
};

#endif /* DSTACK_H_ */
