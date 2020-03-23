#include <iostream>
#include "includes/fractalCreator.h"

int main(){

	int const WIDTH = 1800;
	int const HEIGHT = 1200;

	FractalCreator frac(WIDTH, HEIGHT); 

	frac.addZoom(Zoom(521, 499, 0.1));
	frac.addZoom(Zoom(164, 222, 0.1));
	frac.addZoom(Zoom(882, 483, 0.05));

	frac.run("outputs/teste.bmp");

	std::cout << "Finished." << std::endl;
	return 0;
}

