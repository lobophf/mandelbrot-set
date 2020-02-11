#include <iostream>
#include <vector>

//c++11
int main(){
	
	int value{4};
	std::cout << value << std::endl;

	std::string text{"Hello"};
	std::cout << text << std::endl;
	
	int numbers[]{1, 2, 3};
	std::cout << numbers[1] << std::endl;
	
	int *pInts = new int[3]{1, 2, 3};
	std::cout << pInts[1] << std::endl;
	delete pInts;

	int values{};
	std::cout << values << std::endl;

	int *pSomething{nullptr};
	std::cout << pSomething << std::endl;
	
	int numbers1[5]{};
	std::cout << numbers[1] << std::endl;

	struct{
		int value;
		std::string text;
	} s1{4, "lalala"};

	std::cout << s1.text << std::endl;	

	std::vector<std::string> myVector {"one", "two", "three"};
	std::cout << std::endl;

	std::vector<std::string>::iterator it;
	for(it = myVector.begin(); it != myVector.end(); it++){
		std::cout << *it << std::endl;
	}

	return 0;
}
