#ifndef RING_H
#define RING_H

#include<iostream>

template<typename T>
class Ring{
public:
	class iterator;
};

template<typename T>
class Ring<T>::iterator{
public:
	void print(){
		std::cout << "Hello from iterator " << T() << std::endl;
	}
};
#endif
