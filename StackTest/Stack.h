#ifndef STACK_H
#define STACK_H

#include "IStack.h"

template <typename T>			//Skapar en klassmall
class Stack : public IStack<T>	//Ber�ttar att v�r klassmall �rver fr�n v�rt "IStack" interface, som i sig �r en klassmall...
{
private:
	T * elements;				//F�r att vi vill ha en dynamisk allokerad array av typen "T" 
	int nrOfElements;			
	int capacity;

	void expand();

public:
	Stack(int nrOfElements = 0, int stackCapacity = 2);
								//v�r defaultKonstruktor
	
	Stack(const Stack<T> &origObj);
	
	~Stack();

	void operator=(const Stack<T> &origObj);



	 void push(const  T& element);
	
	 T pop() throw(...);
	
	 T Peek() const throw(...);
	
	 bool isEmpty() const;

	 //TODO: copyConstruktor, tilldelningsoperator, etc ska g�ras: SKA VARA KLART NU... ta bort kommentaren d�
};

#endif // !STACK_H

template<typename T>
inline void Stack<T>::expand()
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
inline Stack<T>::Stack(const Stack<T>& origObj)
{
	this->capacity = origObj.capacity;
	this->nrOfElements = origObj.nrOfElements;
	this->elements = new T[origObj.capacity];
	for (int i = 0; i < origObj.nrOfElements; i++) {
		this->elements[i] = origObj.elements[i];
	}
}

template<typename T>
inline Stack<T>::~Stack()
{
	delete[] this->elements;
}

template<typename T>
inline void Stack<T>::operator=(const Stack<T>& origObj)
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
	if (this->nrOfElements == this->capacity) {		//Kolla om det finns plats, om inte g�r plats
		this->expand(); 
	}

	this->elements[this->nrOfElements] = element;	// l�ggs p� plats nrOfElements. (blir l�ngst bak men vi t�nker att det �r toppen)		
	this->nrOfElements++;
	//this->myStack[]

}

template<typename T>
T Stack<T>::pop() throw(...)
{
	if (this->nrOfElements == 0) { //Kasta error, empty stack.. f�r v�r stack �r tom
		throw "Empty Stack";
	}
	
	this->nrOfElements--;
	return this->elements[this->nrOfElements];


}

template<typename T>
inline T Stack<T>::Peek() const throw(...)
{
	if (this->nrOfElements == 0) { //Kasta error, empty stack.. f�r v�r stack �r tom
		throw "Empty Stack";
	}
		
	return this->elements[this->nrOfElements-1]; // vi returnerar bara det sista elementet i arrayen
}

template<typename T>
inline bool Stack<T>::isEmpty() const
{
	return this->elements == 0; //om vi har 0 element i v�r array s� �r den tom...
}
