#include <iostream>

int main(){

	int one = 1;
	int two = 2;
	int three = 3;

	[one, two](){std::cout << one << ", " << two << std::endl;}();
	[=](){std::cout << one << ", " << two << std::endl;}();
	[=, &three](){three = 9; std::cout << one << ", " << two << std::endl;}();
	std::cout << one << ", " << two << ", " << three << std::endl;
	[&](){three=21; two = 34; std::cout << one << ", " << two << std::endl;}();
	std::cout << one << ", " << two << ", " << three << std::endl;
	[&, two, three](){one = 100; std::cout << one << ", " << two << std::endl;}();
	std::cout << one << std::endl;

	return 0;
}
