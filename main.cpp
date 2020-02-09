#include<iostream>
#include<typeinfo>

auto test() -> int{

	return 8;
}

template<class T> 
auto test1(T value) -> decltype(value){	
	return value;
}

template<class T, class S>
auto test2(T value1, S value2) -> decltype(value1 + value2){
	return value1 + value2;
}

int get(){
	return 99;
}

auto test3() -> decltype(get()){
	return get();
}

int main(){

	auto value = 9;
	std::cout << value << std::endl;

	std::cout << test1(87) << std::endl;
	std::cout << test2(1, 6) << std::endl;

	std::cout << typeid(test2(7, 4)).name() << std::endl;

	std::cout << test3() << std::endl;

	return 0;
}
