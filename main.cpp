#include<iostream>
#include<vector>

int main(){
	
	std::string texts[] = {"one", "two", "three"};

	for(auto i: texts){
		std::cout << i << std::endl;
	}
	
	std::cout << std::endl;

	std::vector<int> numbers;
	numbers.push_back(3);
	numbers.push_back(8);
	numbers.push_back(11);
	numbers.push_back(2);

	for(auto n: numbers){
		std::cout << n << std::endl;
	}
	
	std::cout << std::endl;

	std::string myString = "hello";

	for(auto c: myString){
		std::cout << c << std::endl;
	}

	return 0;
}
