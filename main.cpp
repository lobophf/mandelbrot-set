#include <iostream>
#include "includes/fractalCreator.h"

int main(){

	int const WIDTH = 1800;
	int const HEIGHT = 1200;

	FractalCreator frac(WIDTH, HEIGHT); 

	frac.addRange(0.0, RGB(0, 0, 0));
//	frac.addRange(0.3, RGB(255, 0, 0));
//	frac.addRange(0.5, RGB(255, 255, 0));
	frac.addRange(1.0, RGB(0, 255, 0));

	frac.addZoom(Zoom(521, 499, 0.1));
	frac.addZoom(Zoom(164, 222, 0.1));
	frac.addZoom(Zoom(882, 483, 0.05));

	frac.run("outputs/teste.bmp");

	std::cout << "Finished." << std::endl;
	return 0;
}

