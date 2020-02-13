#include <iostream>
#include <functional> 
#include <vector>
#include <algorithm>

bool check(std::string &test){
	return test.size() == 3;
}

class Check{
public:
	bool operator()(std::string &test){
		return test.size() == 5;
	}
} check1;

void run(std::function<bool(std::string&)> check){
	std::string test = "dog";
	std::cout << check(test) << std::endl;
}

int main(){

	int size = 5;

	std::vector<std::string> vec{"one", "two", "three"};
	int count = count_if(vec.begin(), vec.end(),
				[size](std::string test){return test.size() == size;});
	std::cout << count << std::endl;

	auto lambda = [size](std::string test){return test.size() == size;};
	count = count_if(vec.begin(), vec.end(), lambda);

	std::cout << count << std::endl;

	count = count_if(vec.begin(), vec.end(), check1);
	std::cout << count << std::endl;

	run(lambda);
	run(check1);
	run(check);

	std::function<int(int, int)> add = [](int one, int two){return one + two;};
	std::cout << add(3, 8) << std::endl;

	return 0;
}
