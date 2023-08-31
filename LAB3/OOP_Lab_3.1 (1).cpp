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
	int id;
	List *ptrFollow;	//init Pointer der id folgt
	List *ptrBehind;

};

bool sorted = false;
List *anchor = NULL;	//Pointer der auf den Anfang der Liste zeigt
List *last = NULL;	//Zweiter Pointer der auf den Anfang der Liste vom Ende aus zeigt



List *InsertAtBegin(int number){
	List *new_node = new List;
	new_node ->id = number;
	if(anchor == NULL){	//Falls die Liste leer ist
		anchor = new_node;	//Referenz auf neuen Knoten
		new_node->ptrBehind = NULL;
		new_node->ptrFollow = NULL;
		last = new_node; //Referenz auf den selben Knoten
	}
	else{
		new_node->ptrBehind = last; //rückgängiger Pointer
		last->ptrFollow = new_node;
		new_node->ptrFollow = NULL; //fortlaufender Pointer zeigt auf das letzte Element
		last = new_node; //Verbindung auf den vorherigen Knoten
	}

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
	new_node->ptrBehind = last;
	ptr->ptrFollow = new_node;	//ptrFollow auf letztes Element gebracht
	last = new_node;
	return anchor;
}

void InsertSorted(int id1){
	List* tmp2 = anchor;
	List* tmp3 = NULL;	//Zeiger wolang tmp gehen soll
	List* tmp = new List;
	tmp->ptrFollow = NULL;
	tmp->ptrBehind = last;
	tmp->id = id1;


	while(tmp2 != NULL && tmp2->id < tmp->id)	//Loop bis wir das Ende der Liste erreichen	oder tmp2->id < tmp->id
	{
		tmp3 = tmp2;
	   tmp2 = tmp2->ptrFollow;

	}
	tmp->ptrFollow = tmp2;
	tmp2->ptrBehind = tmp;
	tmp3->ptrFollow = tmp;
	tmp->ptrBehind = tmp3;

    }

void swap(struct List *left, struct List *right){	//Vertauscht linkes und rechtes Element
	int tmp = left->id;
	left->id = right->id;
	right->id = tmp;
}

void BubbleSort()
{
	sorted = true;
	List *firstNumber = anchor;
    bool swap1;
    List *left;
    List *right = NULL;
    if (firstNumber->ptrFollow == NULL){
    	cout << "Liste ist leer" << endl;
        return;
    }
    do
    {
    	swap1 = false;
        left = firstNumber;

        while (left->ptrFollow != right)
        {
            if (left->id > left->ptrFollow->id)	//Falls id grer als das Element rechts von id ist = swap();
            {
                swap(left, left->ptrFollow);
                swap1 = true;
            }
            left = left->ptrFollow;
        }
        right = left;
    }
    while (swap1);
}


void PrintList(){	//Fkt. um die Liste auszugeben
	int counter = 0;
	List *number = anchor;	//Vom Anfang der Liste aus
while(number){	//Solange ptrFollow nicht NULL ist, also bis wir am Ende der Liste sind
	counter++;	//Zhler fr den Listenindex
	cout << endl << "Element " << counter << " = "<< number->id << endl;
	//cout << number->ptrFollow << "-" << number->ptrBehind << endl << endl;
	number = number->ptrFollow;
	}
}

void PrintList_Reverse(){	//Fkt. um die Liste auszugeben
	int counter = 0;
	List *number = last;		//Vom Ende der Liste aus
	while(number){
		counter++;
		cout << endl << "Element" << counter << " = "  << number->id << endl;
		number = number->ptrBehind;
	}

}

int main() {
	int ran;
	char input;
	List *Number = new List;
	Number->ptrFollow = NULL;
	Number->id = 0;

	cout << "'A' um ein neues Element an Anfang der Liste hinzuzufgen" << endl;
	cout << "'E' um ein neues Element an Ende der Liste hinzuzufgen" << endl;
	cout << "'S' um die Liste mit BubbleSort aufsteigend zu sortieren" << endl;
	cout << "'I' um ein neues Element sortiert in eine sortierte Liste einfgen" << endl;
	cout << "'R' um die Liste rückwarts auszugeben" << endl;
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
		BubbleSort();
		PrintList();

	}

	if(input == 'i'){
		if(!sorted){
			BubbleSort();
		}
		ran = (rand() % 999);
		InsertSorted(ran);
		PrintList();

	}

	if(input == 'q'){
		cout << "Exit" << endl;
		exit(0);
	}
	if(input == 'r'){
		PrintList_Reverse();
	}

	}

	return 0;


}
