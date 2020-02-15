#include <iostream>
#include <memory.h>
#include <vector>

class Test{
private:
	static const int SIZE=100;
	int *_pBuffer;

public:
	Test(){
		std::cout << "constructor" << std::endl;
		_pBuffer = new int[SIZE];
		//_pBuffer = new int[SIZE](); C++11;
		memset(_pBuffer, 0, sizeof(int)*SIZE);
	}

	Test(int i){
		std::cout << "parametrized constructor" << std::endl;

		for(int i = 0; i < SIZE; i++){
			_pBuffer[i] = 7 * i;
		}
	}
	
	Test(const Test &other){
		std::cout << "copy constructor" << std::endl;
//		memcpy(_pBuffer, other._pBuffer, SIZE*sizeof(int));
	}

	Test &operator=(const Test &other){
		std::cout << "assigment" << std::endl;
//		memcpy(_pBuffer, other._pBuffer, SIZE*sizeof(int));
		return *this;
	}
	
	~Test(){
		std::cout << "destructor" << std::endl;
		delete [] _pBuffer;
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

	std::vector<Test> vec;
	vec.push_back(Test());

	int value1 = 7;
	
	int *pValue1 = &value1;
//	int *pValue2 = &7;

	Test *pTest1 = &test1;
//	Test *pTest2 = &getTest();

	int *pValue3 = &++value1;
	std::cout << *pValue3 << std::endl;
	
//	int *pValue4 = &value1++;	
//	int *s = &(8 + value1);
	
	return 0;
}
