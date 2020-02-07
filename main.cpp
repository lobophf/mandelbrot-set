#include<iostream>
#include<algorithm>
#include<vector>

bool match(std::string test){
	
	return test.size() == 3;
}

int countString(std::vector<std::string> &texts, bool (*match)(std::string test) ){
	int tally = 0;
	for(int i = 0; i < texts.size(); i++){
		if(match(texts[i])){
			tally++;
		}
	}
	return tally;
}


int main(){

	std::vector<std::string> texts;
	texts.push_back("one");
	texts.push_back("two");
	texts.push_back("three");
	texts.push_back("four");
	texts.push_back("two");
	texts.push_back("three");
	
	std::cout << match("one") << std::endl;
	
	std::cout << std::count_if(texts.begin(), texts.end(), match) << std::endl;

	std::cout << countString(texts, match) << std::endl;
	return 0;
}
