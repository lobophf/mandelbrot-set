#ifndef RING_H
#define RING_H

#include<iostream>

template<typename T>
class Ring{
private:
	T *m_ptr;
	int m_size;
	int m_pos= 0;

public:
	Ring(int size);
	~Ring();
	int size();
	void add(T value);
	T &get(int pos);
};

template<typename T>
Ring<T>::Ring(int size){
	m_size = size;
	m_ptr = NULL;
	m_ptr = new T[m_size];
	m_pos = 0;
};

template<typename T>
void Ring<T>::add(T value){
	m_ptr[m_pos] = value;
	m_pos++;

	if(m_pos == m_size){
		m_pos = 0;
	}
};

template<typename T>
T& Ring<T>::get(int pos){
	return m_ptr[pos]; 
};


template<typename T>
int Ring<T>::size(){
	return m_size;
};

template<typename T>
Ring<T>::~Ring(){
	delete [] m_ptr;	
};

#endif
