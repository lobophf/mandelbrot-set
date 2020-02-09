#include<iostream>
#include "ring.h"

int main(){

	Ring<std::string> r(3);

	r.add("one");
	r.add("two");
	r.add("tree");
	r.add("four");

	for(int i = 0; i < r.size(); i++){
		std::cout << r.get(i) << std::endl;
	}

	return 0;
}
