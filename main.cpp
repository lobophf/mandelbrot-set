#include <iostream>
#include <initializer_list>

class Test{
public:
	Test(std::initializer_list<std::string> texts){
		for(auto value: texts){
			std::cout << value << std::endl;
		}
	}

	void print(std::initializer_list<std::string> texts){
		for(auto value: texts){
			std::cout << value << std::endl;
		}
	}
};

int main(){

	Test test{"apple", "orange", "banana"};
	test.print({"one", "two", "three", "four"});

	return 0;
}
