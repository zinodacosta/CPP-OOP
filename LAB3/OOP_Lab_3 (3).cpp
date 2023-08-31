//============================================================================
// Name        : OOPLab3.cpp
// Author      : Zino da Costa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


struct List{	//Liste im Typ Struct erstelle
public:
	int id;			//Gespeicherte Wert der vom Pointer
	List *ptrFollow; //init Pointer der Knoten folgt

};
bool sorted = false;
List *anchor = NULL;	//Pointer der auf den Anfang der Liste zeigt

List *InsertAtBegin(int number){	//Aufruf der Fkt.

	List *new_node = new List;		//Neues Listenelement wird erstellt
	new_node->ptrFollow = anchor;	//ptrFollow wird auf die erste Position in der Liste gesetzt
	new_node->id = number;	//Wert wird auf new_node->id ueberschrieben
	anchor = new_node;		//anchor wird mit dem neuem Knoten verbunden

	return new_node;
}


List *InsertAtEnd(int number){

	List *new_node = new List;
	new_node->ptrFollow = NULL;
	new_node->id = number;

	List *ptr = anchor;
	if(anchor == NULL){	//falls die Liste leer ist

		InsertAtBegin(number);
		return anchor;

	}
	while(ptr->ptrFollow != NULL){

		ptr = ptr->ptrFollow;	//letztes Element finden
	}

	ptr->ptrFollow = new_node;	//ptrFollow auf letztes Element gebracht

	return anchor;
}

void InsertSorted(int id1){

	List* ptr = new List;
	ptr->ptrFollow = NULL;
	ptr->id = id1;

	List* tmp2 = anchor;
	List** tmp3 = &anchor;	//Zeiger wolang tmp gehen soll
	while(tmp2 != NULL && tmp2->id < ptr->id)	//Loop bis wir das Ende der Liste erreichen	oder tmp2->id < tmp->id
	{

		tmp3 = &tmp2->ptrFollow;
	   tmp2 = tmp2->ptrFollow;

	}

	*tmp3 = ptr;
	ptr->ptrFollow = tmp2;
    }

void swap(struct List *left, struct List *right){	//Vertauscht linkes und rechtes Element
	int tmp = left->id;
	left->id = right->id;
	right->id = tmp;
}//fkt

void BubbleSort(struct List *number)
{
	sorted = true;
    bool swap1;
    List *left;
    List *right = NULL;
    if (number->ptrFollow == NULL){
    	cout << "Liste ist leer" << endl;
        return;
    }//if
    do
    {
    	swap1 = false;
        left = number;

        while (left->ptrFollow != right)
        {
            if (left->id > left->ptrFollow->id)	//Falls id groesser als das Element rechts von id ist = swap();
            {
                swap(left, left->ptrFollow);
                swap1 = true;
            }
            left = left->ptrFollow;
        }//while
        right = left;
    }//do while
    while (swap1);
}//fkt


void PrintList(){	//Fkt. um die Liste auszugeben
	int counter = 0;
	List *number = anchor;
while(number){	//Solange ptrFollow nicht NULL ist, also bis wir am Ende der Liste sind
	counter++;	//Zaehler fuer den Listenindex
	cout << "Element " << counter << " = "<< number->id << endl;
	cout << endl;
	number = number->ptrFollow;
}//while


}//fkt

int main() {

	int ran;
	char input;
	List *Number = new List;
	Number->ptrFollow = NULL;
	Number->id = 0;

	cout << "'A' um ein neues Element an Anfang der Liste hinzuzuf체gen" << endl;
	cout << "'E' um ein neues Element an Ende der Liste hinzuzuf체gen" << endl;
	cout << "'S' um die Liste mit BubbleSort aufsteigend zu sortieren" << endl;
	cout << "'I' um ein neues Element sortiert in eine sortierte Liste einf체gen" << endl;

	while(1 == 1){

	cin >> input;

	if(input == 'a'){
			sorted = false;
			ran = (rand() % 999);
			Number = InsertAtBegin(ran);
			PrintList();
	}
	if(input == 'e'){
		sorted = false;
			ran = (rand() % 999);
			Number = InsertAtEnd(ran);
			PrintList();
	}

	if(input == 's'){
		BubbleSort(Number);
		PrintList();

	}

	if(input == 'i'){
		if(!sorted){
			BubbleSort(Number);
		}
		ran = (rand() % 999);
		InsertSorted(ran);
		PrintList();
	}

	if(input == 'q'){
		cout << "Exit" << endl;
		exit(0);
	}

	}

	return 0;


}
