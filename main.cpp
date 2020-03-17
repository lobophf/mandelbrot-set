#include "includes/bitmap.h"
#include "includes/mandelbrot.h"
#include <iostream>
#include <cstdint>

int main(){

	int const width = 800;
	int const height = 600;

	bmp::Bitmap bm(width, height);

	double min = 9999999;
	double max = -9999999;

	for(int y = 0; y < height; y++){
		for(int x = 0; x < width; x++){
			double xFractal = (x - width / 2.0) * 2.0 / width;
			double yFractal = (y - height/ 2.0) * 2.0 / height;
			
			int iterations = Mandelbrot::getIterations(xFractal, yFractal);
			uint8_t blue = (uint8_t)(256 * (double)iterations/Mandelbrot::MAX_ITERATIONS);
			
			if(blue < min) min = blue;
			if(blue > max) max = blue;
		}
	}

	std::cout << min << ", " << max << std::endl;

	bm.write("outputs/test.bmp");
	std::cout << "Finished." << std::endl;

	return 0;
}

