#ifndef I_STACK_H
#define I_STACK_H

template <typename T>	// Det �r en Template klass
class IStack {			// V�r "Interface" f�r v�r stackklass...
public:
	//Funktion f�r att stoppa in element i stacken, kallas alltid "Push"
	virtual void push(const  T& element ) = 0;

	//Funktion f�r att plocka bort det element som ligger �vest i stacken och returnera det, kallas alltid "Pop" i stack
	virtual T pop() throw(...)= 0; 
												//Om stacken �r tom ska vi kasta ett error, d�rf�r har vi Throw

	//Funktion f�r att titta p� det element som ligger �verst i stacken, kallas f�r "Peek" i stack
	virtual T Peek() const throw(...) = 0; 
												//Om stacken �r tom ska vi kasta ett error, d�rf�r har vi Throw

	//Funktion f�r att titta om stacken �r tom.
	virtual bool isEmpty() const = 0;


};

#endif // !I_STACK_H
