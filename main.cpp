#include<iostream>

class Parent{
	int dogs{5};
	std::string text{"hello"};
public:
	Parent() : Parent("hello"){
		std::cout << "no parameter parent construtor" << std::endl;
	}

	Parent(std::string text){
		std::cout << "string parent constructor" << std::endl;
	}
};

class Child: public Parent{
public:
	Child() = default;
};

int main(){

	Parent parent("hello");
	Child child;

	return 0;
}
