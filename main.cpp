#include<iostream>

void test(){
	std::cout << "hello" << std::endl;

}

void test2(int n){
	std::cout << "value: " << n << std::endl;
}


int main(){
	

	test();
	void (*pTest)() = test;

	pTest();

	test2(2);
	void (*pTest2)(int) = test2;

	pTest2(8);

}
