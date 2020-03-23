#include <iostream>
#include "includes/zoom.h"
#include "includes/fractalCreator.h"

int main(){

	int const WIDTH = 1800;
	int const HEIGHT = 1200;

	FractalCreator frac(WIDTH, HEIGHT); 

	frac.addZoom(Zoom(521, HEIGHT - 499, 0.1));
	frac.addZoom(Zoom(164, HEIGHT - 222, 0.1));
	frac.addZoom(Zoom(882, HEIGHT - 483, 0.05));

	frac.calculateIterations();
	frac.calculateTotalIterations();
	frac.drawFractal();
	frac.writeBitmap("outputs/teste.bmp");

	std::cout << "Finished." << std::endl;
	return 0;
}

