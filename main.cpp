#include <iostream>
#include "includes/fractalCreator.h"

int main(){

	int const WIDTH = 1600;
	int const HEIGHT = 800;
	FractalCreator frac(WIDTH, HEIGHT); 


	frac.addRange(0.0, RGB(  0,   0,   0));
	/* Set some additional colors in the middle 
	   of the scale range. */
	/* 
	frac.addRange(0.4, RGB(  0, 230, 255));
	frac.addRange(0.8, RGB( 72,   0, 255));
	*/
	frac.addRange(1.0, RGB(  0,   0, 255));


	frac.addZoom(Zoom( 500, 366, 0.10));
	frac.addZoom(Zoom( 522,  20, 0.05));
	frac.addZoom(Zoom(1268, 106, 0.30));

	frac.run("outputs/test.bmp");

	std::cout << "Finished." << std::endl;
	return 0;
}

