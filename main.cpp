#include<iostream>

class Animal{
public:
	virtual void run() = 0;
	virtual void speak() = 0;

};

class Dog: public Animal{
public:
	void speak(){
		std::cout << "Wolf" << std::endl;
	}

};

class Labrador: public Dog{
public: 
	Labrador(){
		std::cout << "new labrador" << std::endl;
	}
	
	void run(){
		std::cout << "Running" << std::endl;
	}

};

void test(Animal &a){
	a.speak();
}

int main(){


	Labrador labs[5];

	Labrador lab;
	lab.run();
	lab.speak();
	
	Animal *animals[5];
	animals[0] = &lab;	
	lab.run();
	
	test(lab);

	return 0;
}
