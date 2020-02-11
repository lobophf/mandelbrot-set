#include <iostream>

int main(){
	
	int value[] = {1, 2, 3, 4};

	std::cout << value[3] << std::endl;

	class C{
	public:
		std::string text;
		int id;
	};

	C c1 = {"Hello", 3};

	std::cout << c1.text << std::endl;	

	struct S{
		std::string text;
		int id;
	};

	S s1 = {"lalala", 1};

	std::cout << s1.text << std::endl;	

	struct {
		std::string text;
		int id;
	} r1 = {"aaaaaaaaaaa", 5}, r2 = {"bbbbbbbbbbbb" , 4};


	std::cout << r1.text << std::endl;	
	return 0;
}
