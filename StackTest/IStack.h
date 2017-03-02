#ifndef I_STACK_H
#define I_STACK_H

template <typename T>	// Det är en Template klass
class IStack {			// Vår "Interface" för vår stackklass...
public:
	//Funktion för att stoppa in element i stacken, kallas alltid "Push"
	virtual void push(const  T& element ) = 0;

	//Funktion för att plocka bort det element som ligger övest i stacken och returnera det, kallas alltid "Pop" i stack
	virtual T pop() throw(...)= 0; 
												//Om stacken är tom ska vi kasta ett error, därför har vi Throw

	//Funktion för att titta på det element som ligger överst i stacken, kallas för "Peek" i stack
	virtual T Peek() const throw(...) = 0; 
												//Om stacken är tom ska vi kasta ett error, därför har vi Throw

	//Funktion för att titta om stacken är tom.
	virtual bool isEmpty() const = 0;


};

#endif // !I_STACK_H
