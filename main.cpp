#include <iostream>
#include "includes/fractalCreator.h"

int main(){

	int const WIDTH = 1800;
	int const HEIGHT = 1200;

	FractalCreator frac(WIDTH, HEIGHT); 
	frac.run("outputs/teste.bmp");

	std::cout << "Finished." << std::endl;
	return 0;
}

