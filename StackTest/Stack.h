#ifndef STACK_H
#define STACK_H

#include "IStack.h"

template <typename T>			//Skapar en klassmall
class Stack : public IStack<T>	//Berättar att vår klassmall ärver från vårt "IStack" interface, som i sig är en klassmall...
{
private:
	T * elements;				//För att vi vill ha en dynamisk allokerad array av typen "T" 
	int nrOfElements;			
	int capacity;

	void expand();

public:
	Stack(int nrOfElements = 0, int stackCapacity = 2);
								//vår defaultKonstruktor	
	Stack(const Stack<T> &origObj);
	
	~Stack();

	void operator=(const Stack<T> &origObj);

	 void push(const  T& element);
	
	 T pop() throw(...);
	
	 T Peek() const throw(...);
	
	 bool isEmpty() const;

	 //TODO: copyConstruktor, tilldelningsoperator, etc ska göras: SKA VARA KLART NU... ta bort kommentaren då
};

#endif // !STACK_H

template<typename T>
 void Stack<T>::expand()
{
	this->capacity *= 2;
	T *temp = new T[this->capacity];

	for (int i = 0; i < this->nrOfElements; i++) {
		temp[i] = this->elements[i];
	}

	this->elements = temp;

}

template <typename T>
Stack<T>::Stack(int nrOfElements, int stackCapacity)
{
	this->nrOfElements = nrOfElements;
	this->capacity = stackCapacity;

	this->elements = new T[this->capacity];
}

template<typename T>
 Stack<T>::Stack(const Stack<T>& origObj)
{
	this->capacity = origObj.capacity;
	this->nrOfElements = origObj.nrOfElements;
	this->elements = new T[origObj.capacity];
	for (int i = 0; i < origObj.nrOfElements; i++) {
		this->elements[i] = origObj.elements[i];
	}
}

template<typename T>
 Stack<T>::~Stack()
{
	delete[] this->elements;
}

template<typename T>
 void Stack<T>::operator=(const Stack<T>& origObj)
{

	if (this != origObj) {
		delete[] this->elements;

		this->capacity = origObj.capacity;
		this->nrOfElements = origObj.nrOfElements;
		this->elements = new T[origObj.capacity];
		for (int i = 0; i < origObj.nrOfElements; i++) {
			this->elements[i] = origObj.elements[i];
		}
	}
}

template<typename T>
void Stack<T>::push(const T & element)
{
	if (this->nrOfElements == this->capacity) {		
		//Kolla om det finns plats, om inte gör plats
		this->expand(); 
	}

	this->elements[this->nrOfElements] = element;	
	// läggs på plats nrOfElements. 
	//(blir längst bak men vi tänker att det är toppen)		

	this->nrOfElements++;
	//this->myStack[]

}

template<typename T>
T Stack<T>::pop() throw(...)
{
	if (this->nrOfElements == 0) { //Kasta error, empty stack.. för vår stack är tom
		throw "Empty Stack";
	}
	
	this->nrOfElements--; 
	// anger att sista platsen i arraten är OK att skriva över, räknas som borttagen

	return this->elements[this->nrOfElements]; 
	//returnerar sista elementet i arrayen
	
	//return this->elements[--this->nrOfElements]; //alternativ rad
}

template<typename T>
T Stack<T>::Peek() const throw(...)
{
	if (this->nrOfElements == 0) { 
		//Kasta error, empty stack.. för vår stack är tom
		throw "Empty Stack";
	}
		
	return this->elements[this->nrOfElements-1]; 
	// vi returnerar bara det sista elementet i arrayen
}


template<typename T>
bool Stack<T>::isEmpty() const
{
	return this->elements == 0; 
	//om vi har 0 element i vår array så är den tom...
}
