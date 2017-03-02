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
void swapThem(T& item, T &otherItem);			//SwapThem och Partition �r hj�lpfunktioner f�r sort! 

template <typename T>
int partition(T *theArray, int start, int end);

template <typename T>
void sort(T *theArray, int start, int end);


//F�rst pationerar vi hela arrayen
//sen beh�ver vi veta var den startar och slutar  
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

	time_t startTime = clock(); //time_t �r posetiva heltal som datorn anv�nder sig av n�r den r�knar med tid

	sort(anArray, 0, CAP - 1);

	for (int i = 0; i < CAP; i++) {
		cout << anArray[i] << endl;
	}

	time_t endTime = clock();
	cout << "start: " << startTime << endl << "End: " << endTime << "Differens: " << endTime - startTime  << endl;

	time_t startTimeAnother = clock(); //time_t �r posetiva heltal som datorn anv�nder sig av n�r den r�knar med tid

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
		cout << "nr �r nu ==" << n << endl;
		info(n-1);	//N�r vi anropar info igen s� 
					// har inte f�rsta info()-anropet fr�n main-funktionen avslutas �n.
	}

	cout << "Info() l�mnas nu med n == " << n << endl; 
	//Denna raden skrivs ut f�rst efter den rekrusiva delen �r slut, n�mligen n�r 
	//vi skickar in "1-1" i "info()" funktionen... d� blir ju "n" 0, vilket hoppar �ver if-satsen
	

}

void testStack() {

	Stack<string> s;

	s.push("Banan");

	s.push("Motorb�t");
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
	T pivotValue = theArray[start]; // pivot �r v�rt ungef�rliga mittenv�rde
	// v�rat ungef�rliga mittenv�rde...
	
	int pivotPosition = start;

	//Vi g�r igenom alla objekt fr�n start till end...
	for (int i = start + 1; i <= end; i++) {
		if (theArray[i] < pivotValue) {//Om det som finns p� plats I �r mindre �n PivotValue, byt ut (anv�nd swap) 
			swapThem(theArray[i], theArray[pivotPosition+1]);
									//"+1" tar platsen till h�ger om.

			//Byt plats p� pivot och den som �r brevid! eftersom vi lagt dem previd varandra... 
			swapThem(theArray[pivotPosition+1], theArray[pivotPosition] ); 
			pivotPosition++; // r�kna ut nya pivotPositionen
		}
	}
	return pivotPosition; //Returnerar pivotPositionen...	
}

template<typename T>
void sort(T * theArray, int start, int end)
{//Just denna sorteringsalgoritmen kallas QuickSort

	//anv�nder v�r partion metod f�r att grovsortera och ta reda p� var Pivot �r.
	if (start < end) {
		int pivotPos = partition(theArray, start, end);
		sort(theArray, start, pivotPos - 1);	//"-1"  f�r att vi vill ha den v�nstra om den mittersta
		sort(theArray, pivotPos + 1, end);		//"+1"  f�r att vi vill ha den h�gra om den mittersta
	}
	

}
