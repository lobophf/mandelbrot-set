#include<iostream>

struct Test{
	virtual bool operator()(std::string &text) = 0;
	virtual ~Test(){};
};

struct MatchTest: public Test{
	bool operator()(std::string &text){
		return text == "lion";
	}
};

void check(std::string text, Test &test){
	if(test(text)){
		std::cout << "Text match." << std::endl;
	}
	else{
		std::cout << "No match." << std::endl;
	}
}

int main(){
	
	MatchTest pred;	
	std::string value = "lion";
	
	//std::cout << pred(value) << std::endl;
	MatchTest m;
	check("lon", m);

	return 0;
}
