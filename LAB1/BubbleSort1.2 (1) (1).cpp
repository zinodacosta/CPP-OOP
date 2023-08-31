//============================================================================
// Name        : Prog2Lab1.cpp
// Author      : Zino da Costa
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : BubbleSort
//============================================================================


#include <time.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

void bubblesort(int a[], int size){

int i,j;
bool check = true;		//Check-Wert um zu prüfen ob noch eine Schleife notwendig ist
									//True wenn noch eine Schleife False wenn keine mehr

for (j = 1; j < size && check == true ; j++){ 	//Falls Zähler Variable kleiner als Array Größe und check true ist
	check = false;
	cout << "count\n";
	for(i = 0; i < size-1; i++)
	{
		if (a[i] > a[i+1])			//Falls a[i] größer als a[i+1]
		{
			swap(a[i], a[i+1]);			//Ruft swap Fkt. auf
			check = true;
		}
	}
}

for (int x = 0; x < size; x++){
	cout << a[x] << " "; 		//Ausgabe des Arrays

}

}

void swap(int &a, int &b){ 		//swap Fkt. tauscht Arrayplatz von Element a[i] und a[i+1]

	int tmp;

	tmp = a;
	a = b;
	b = tmp;

}

int main() {

int i;


//Aufgabe b
cout << "Aufgabe b" << endl;
int r[100];
time_t t; time(&t); srand((unsigned int)t);

for(i=0; i<100; i++){	//Füllt Array mit Werte zwischen 1 und 100


	r[i]=rand() % 100 + 1;	//Random Range von 1 bis 100

}

bubblesort(r, 100);	//Aufruf der Fkt mit Arraysize von 100 Elementen

	return 0;
}
