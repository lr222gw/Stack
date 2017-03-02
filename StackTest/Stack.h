#ifndef STACK_H
#define STACK_H

#include "IStack.h"

class stack : public IStack 
{
private:
	
	template <typename T>
	T * myStack = new T();

public:
	virtual void push(const  T& element) = 0;
	
	virtual T pop() throw(...) = 0;
		
	virtual T Peek() const throw(...) = 0;
	
	virtual bool isEmpty() const = 0;
};

#endif // !STACK_H
