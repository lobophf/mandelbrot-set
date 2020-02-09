#include<iostream>
#include<typeinfo>

class myClass{
public:
	myClass(){}
	~myClass(){}
};

int main(){
	
	double i;
	
	std::cout << typeid(i).name() << std::endl;

	std::string myString;
	std::cout << typeid(myString).name() << std::endl;

	char myChar;
	std::cout << typeid(myChar).name() << std::endl;

	myClass p;
	std::cout << typeid(p).name() << std::endl;

	return 0;
}
