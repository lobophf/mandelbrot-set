#include <iostream>
#include <memory.h>
#include <vector>

class Test{
private:
	static const int SIZE=100;
	int *_pBuffer{nullptr};

public:
	Test(){
		_pBuffer = new int[SIZE];
		//_pBuffer = new int[SIZE](); C++11;
		memset(_pBuffer, 0, sizeof(int)*SIZE);
	}

	Test(int i){

//		for(int i = 0; i < SIZE; i++){
//			_pBuffer[i] = 7 * i;
//		}
	}
	
	Test(const Test &other){
//		memcpy(_pBuffer, other._pBuffer, SIZE*sizeof(int));
	}

	Test &operator=(const Test &other){
//		memcpy(_pBuffer, other._pBuffer, SIZE*sizeof(int));
		return *this;
	}
	
	~Test(){
		delete [] _pBuffer;
	}

	friend std::ostream &operator<<(std::ostream &out, const Test &test);

	Test(Test &&other){
	
		std::cout << "move constructor" << std::endl;
		_pBuffer = other._pBuffer;
		other._pBuffer = nullptr;
	}

};
std::ostream &operator<<(std::ostream &out, const Test &test){
	return out;
}

Test getTest(){
	return Test();
}

int main(){

	Test test1 = getTest();

	std::vector<Test> vec;
	vec.push_back(Test());




	return 0;
}
