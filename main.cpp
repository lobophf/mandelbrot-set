#include <iostream>

#include<iostream>

int main(){

	int cats = 5;
	[cats]() mutable{
		cats = 9;
		std::cout << cats << std::endl;	
	}();

	std::cout << cats << std::endl;

	return 0;
}
