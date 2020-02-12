#include <iostream>

class Test{
private:
	int id{2};
	std::string name{"Mike"};
public:
	Test() = default;
//	Test(const Test &other) = delete;
	Test &operator=(const Test &other) = default;
	Test(int id) : id(id){

	}

	void print(){
		std::cout << id << ": " << name << std::endl;
	}
};

int main(){

	Test test;
	test.print();

	Test test1(4);
	test1.print();

//	Test test2 = test1;


	return 0;
}
