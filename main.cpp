#include <iostream>


class Test{

};

template<typename T>
void call (T &&arg){
	check(std::forward<T>(arg));
}

void check(Test &test){
	std::cout << "lvalue" << std::endl;
}

void check(Test &&test){
	std::cout << "rvalue" << std::endl;
}

int main() {

	Test test;
	//call(Test());
	call(Test());

	return 0;
}

