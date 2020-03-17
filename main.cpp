#include "includes/bitmap.h"
#include "includes/mandelbrot.h"
#include <iostream>
#include <cstdint>

int main(){

	int const WIDTH = 800;
	int const HEIGHT = 600;

	bmp::Bitmap bm(WIDTH, HEIGHT);

	double min = 9999999;
	double max = -9999999;

	for(int y = 0; y < HEIGHT; y++){
		for(int x = 0; x < WIDTH; x++){
			double xFractal = (x - WIDTH / 2.0) * 2.0 / WIDTH;
			double yFractal = (y - HEIGHT / 2.0) * 2.0 / HEIGHT;
			
			int iterations = Mandelbrot::getIterations(xFractal, yFractal);
			uint8_t red = (uint8_t)(256 * (double)iterations/Mandelbrot::MAX_ITERATIONS);
			
			bm.setPixel(x, y, red, 0, 0);

			if(red < min) min = red;
			if(red > max) max = red;
		}
	}

	std::cout << min << ", " << max << std::endl;

	bm.write("outputs/test.bmp");
	std::cout << "Finished." << std::endl;

	return 0;
}

