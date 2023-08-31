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
int a[10]; 		//Erstellt Array mit 10 Elementen

cout << "Geben Sie zehn Integerzahlen ein: " << endl;

for(i=0; i<10; i++){			//For-Schleife zur Speicherung der 10 Eingaben
	cin >> a[i];


}

cout << endl << "Array " << endl;

for(i=0; i<10; i++){
	cout << a[i] << " "; 		//Ausgabe des Arrays

}

cout << endl << endl << "Sortiertes Array" << endl;

bubblesort(a, 10);	//Aufruf der Fkt mit Arraysize von 10 Elementen

	return 0;
}
