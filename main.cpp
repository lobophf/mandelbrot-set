#include <iostream>
#include <vector>

class Test{
public:
	Test(){
		std::cout << "constructor" << std::endl;
	}

	Test(int i){
		std::cout << "parametrized constructor" << std::endl;
	}
	
	Test(const Test &other){
		std::cout << "copy constructor" << std::endl;
	}

	Test &operator=(const Test &other){
		std::cout << "assigment" << std::endl;
	}
	
	~Test(){
		std::cout << "destructor" << std::endl;
	}

	friend std::ostream &operator<<(std::ostream &out, const Test &test);
};

std::ostream &operator<<(std::ostream &out, const Test &test){
	out << "Hello from test" << std::endl;
	return out;
}

Test getTest(){
	return Test();
}

int main(){

	Test test1 = getTest();

	// !g++ -fno-elide-constructors main.cpp && ./a.out

	std::cout << test1 << std::endl;


	std::vector<Test> vec;
	vec.push_back(Test());


	return 0;
}
