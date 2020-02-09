#include<iostream>
#include<vector>

int main(){
	
	auto texts = {"one", "two", "three"};
	for(auto i: texts){
		std::cout << i << std::endl;
	}
		
	std::vector<int> numbers;
	numbers.push_back(3);
	numbers.push_back(5);
	numbers.push_back(6);
	numbers.push_back(11);

	for(auto i: numbers){
		std::cout << i << std::endl;
	}

	std::string myString = "hello";
	
	std::cout << std::endl;
	for(auto c: myString){
		std::cout << c << std::endl;
	}

	return 0;
}
