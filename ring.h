#ifndef RING_H
#define RING_H
#include<iostream>

template<class T>
class ring{
	
private:
	int m_pos;
	int m_size;
	T *m_values;

public:
	class iterator;
public:
	ring(int size);
	~ring();
	int size();
	void add(T value);
	T &get(int pos);

	iterator begin(){
		return iterator(0, *this);
	}

	iterator end(){
		return iterator(m_size, *this);
	}
};

template<typename T>
ring<T>::ring(int size){ 
	m_pos = 0;
	m_size = size;
	m_values = nullptr;
	m_values = new T[size];
}

template<typename T>
ring<T>::~ring(){
	delete[] m_values;
}
template<typename T>
int ring<T>::size(){
	return m_size;
}

template<typename T>
void ring<T>::add(T value){
	m_values[m_pos++] = value;
	if(m_pos == m_size){
		m_pos = 0;
	}
}

template<typename T>
T &ring<T>::get(int pos){
	return m_values[pos];
}

template<class T>
class ring<T>::iterator{
private:
	int m_pos;
	ring &m_ring;
public:
	iterator(int pos, ring &ring_ref): m_ring(ring_ref){
		m_pos = pos;
	}

	iterator operator++(int){
		iterator old = *this;
		++(*this);
		return old;
	}
	
	iterator& operator++(){
		++m_pos;
		return *this;
	}

	T& operator*(){
		return m_ring.get(m_pos);
	}

	bool operator==(const iterator &other) const{
		return m_pos == other.m_pos;
	}

	bool operator!=(const iterator &other) const{
		return !(*this == other);	
	}
};

#endif
