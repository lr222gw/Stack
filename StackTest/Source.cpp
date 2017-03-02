#include "Stack.h"
#include <string>
#include <iostream>
#include <time.h>

using namespace std;

void testStack();
void info(int n);
int faculty(int n);
int sum(int start, int end);

template <typename T>
void swapThem(T& item, T &otherItem);			//SwapThem och Partition är hjälpfunktioner för sort! 

template <typename T>
int partition(T *theArray, int start, int end);

template <typename T>
void sort(T *theArray, int start, int end);


//Först pationerar vi hela arrayen
//sen behöver vi veta var den startar och slutar  
//Den returnerar PivotPositionen... 
int main() {

	//info(5);
	//cout << to_string(faculty(4));
	//cout << to_string(sum(1,4));
	const int CAP = 8000;
	srand(static_cast <unsigned>(time(0)));
	int anArray[CAP];
	int anotherArray[CAP];

	for (int i = 0; i < CAP;i++) {
		anArray[i] = rand() % 1000 + 1;
		anotherArray[i] = anArray[i];
	}

	time_t startTime = clock(); //time_t är posetiva heltal som datorn använder sig av när den räknar med tid

	sort(anArray, 0, CAP - 1);

	for (int i = 0; i < CAP; i++) {
		cout << anArray[i] << endl;
	}

	time_t endTime = clock();
	cout << "start: " << startTime << endl << "End: " << endTime << "Differens: " << endTime - startTime  << endl;

	time_t startTimeAnother = clock(); //time_t är posetiva heltal som datorn använder sig av när den räknar med tid

	sort(anotherArray, 0, CAP - 1);

	for (int i = 0; i < CAP; i++) {
		cout << anotherArray[i] << endl;
	}

	time_t endTimeAnother = clock();
	//cout << "start: " << startTime << endl << "End: " << endTime << "Differens: " << endTime - startTime << endl;
	//cout << "start Another: " << startTimeAnother << endl << "End Another: " << endTimeAnother  << "Differens: "<< endTimeAnother - startTimeAnother<< endl;
	cout << "an " << endTime - startTime  << endl;
	cout << "another" << endTimeAnother - startTimeAnother << endl;

	return 0;
}

int sum(int start, int end) {

	if (start < end) {

		return end + sum(start, end - 1);
	}
	else {
		return start; //Basecase;
	}
}

int faculty(int n) {
	int result = 1;
	if (n > 1) {		
		return n * faculty(n - 1);
	}
	else {
		return 1;
	}	
}

void info(int n) { //rekursiv funktion

	if (n > 0) {
		cout << "nr är nu ==" << n << endl;
		info(n-1);	//När vi anropar info igen så 
					// har inte första info()-anropet från main-funktionen avslutas än.
	}

	cout << "Info() lämnas nu med n == " << n << endl; 
	//Denna raden skrivs ut först efter den rekrusiva delen är slut, nämligen när 
	//vi skickar in "1-1" i "info()" funktionen... då blir ju "n" 0, vilket hoppar över if-satsen
	

}

void testStack() {

	Stack<string> s;

	s.push("Banan");

	s.push("Motorbåt");
	s.push("Cykel");

	try {
		cout << s.pop() << endl;
	}
	catch (char * e) {
		cout << e << endl;
	}

	try {
		cout << s.Peek() << endl;
	}
	catch (char *e) {
		cout << e << endl;
	}

	
}

template<typename T>
void swapThem(T & item, T & otherItem)
{
	T temp = item;
	item = otherItem;
	otherItem = temp;
}

template<typename T> 
int partition(T * theArray, int start, int end) //Den icke rekrusiva delen..
{
	T pivotValue = theArray[start]; // pivot är vårt ungefärliga mittenvärde
	// vårat ungefärliga mittenvärde...
	
	int pivotPosition = start;

	//Vi går igenom alla objekt från start till end...
	for (int i = start + 1; i <= end; i++) {
		if (theArray[i] < pivotValue) {//Om det som finns på plats I är mindre än PivotValue, byt ut (använd swap) 
			swapThem(theArray[i], theArray[pivotPosition+1]);
									//"+1" tar platsen till höger om.

			//Byt plats på pivot och den som är brevid! eftersom vi lagt dem previd varandra... 
			swapThem(theArray[pivotPosition+1], theArray[pivotPosition] ); 
			pivotPosition++; // räkna ut nya pivotPositionen
		}
	}
	return pivotPosition; //Returnerar pivotPositionen...	
}

template<typename T>
void sort(T * theArray, int start, int end)
{//Just denna sorteringsalgoritmen kallas QuickSort

	//använder vår partion metod för att grovsortera och ta reda på var Pivot är.
	if (start < end) {
		int pivotPos = partition(theArray, start, end);
		sort(theArray, start, pivotPos - 1);	//"-1"  för att vi vill ha den vänstra om den mittersta
		sort(theArray, pivotPos + 1, end);		//"+1"  för att vi vill ha den högra om den mittersta
	}
	

}
