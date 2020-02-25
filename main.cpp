#include <iostream>

class Parent {
public:
	virtual void speak() {
		std::cout << "parent!" << std::endl;
	}
};

class Brother: public Parent {

};

class Sister: public Parent {

};

int main() {

	Parent parent;
	Brother brother;

	Parent *ppb = &brother;

	Brother *pbb = dynamic_cast<Brother *>(ppb);

	if(pbb == nullptr){
		std::cout << "invalid cast" << std::endl;
	}
	else{
		std::cout << pbb << std::endl;
	}

	return 0;
}

