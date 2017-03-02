#include "Stack.h"
#include <string>
#include <iostream>

using namespace std;
int main() {

	Stack<string> s;

	s.push("Banan");

	s.push("Motorbåt");
	s.push("Cykel");

	try {
		cout << s.pop() << endl;
	}
	catch (char * e){
		cout << e << endl;
	}
	try {
		cout << s.Peek() << endl; 
	}
	catch (char *e) {
		cout << e << endl;
	}

	return 0;
}