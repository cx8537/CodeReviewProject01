#include <iostream>

class B { // class A, B 보다 어떤 목적을 지닌 클래스인지 네이밍이 명확했으면 좋겠어요.
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
	void printValue(B& b) {		// class A의 모든 기능이 class B에 들어있기 때문에 추가적인 제작 필요가 없지 않을까 싶어요
		b.printData();
	}
};


void main()
{

}