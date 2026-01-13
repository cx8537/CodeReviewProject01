#include <iostream>

class B {
public:
	B(int a) { x = a; }
	void printData() {
		std::cout << x << std::endl;
	}
private:
	int x;
};


class A {
public:
	void printValue(B& b) {
		b.printData();
	}
};


void main()
{

}