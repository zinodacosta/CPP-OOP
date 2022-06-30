//============================================================================
// Name        : OOPLAB5.cpp
// Author      : Zino da Costa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stack>
#include <string>
#include <stdlib.h>
#include <stdio.h>

#include "Stammbaum.h"
using namespace std;

int main() {
	Stammbaum obj1;
string input;
while(true){
cin >> input;

if(input == "r" || input == "v" || input == "m"){
obj1.createNode(input);

}

if(input == "d" || input == "a" || input == "w"){
obj1.navigate(input);

}

}
	return 0;
}
