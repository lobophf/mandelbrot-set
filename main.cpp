#include "includes/bitmap.h"
#include "includes/mandelbrot.h"
#include <iostream>
#include <cstdint>
#include <memory>
#include <math.h>

int main(){

	int const WIDTH = 800;
	int const HEIGHT = 600;

	bmp::Bitmap bm(WIDTH, HEIGHT);

	std::unique_ptr<int[]> histogram(new int[Mandelbrot::MAX_ITERATIONS]{0});
	std::unique_ptr<int[]> fractal(new int[WIDTH * HEIGHT]{0});

	for(int y = 0; y < HEIGHT; y++){
		for(int x = 0; x < WIDTH; x++){
			double xFractal = (x - WIDTH / 2.0 - 200) * 2.0 / HEIGHT;
			double yFractal = (y - HEIGHT / 2.0) * 2.0 / HEIGHT;
			int iterations = Mandelbrot::getIterations(xFractal, yFractal);
			fractal[y * WIDTH + x] = iterations;
			if(iterations != Mandelbrot::MAX_ITERATIONS){
				histogram[iterations]++;
			}
		}
	}
	
	int total = 0;
	for(int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++){
		total += histogram[i];
	}

	for(int y = 0; y < HEIGHT; y++){
		for(int x = 0; x < WIDTH; x++){

			uint8_t red = 0;
			uint8_t green = 0;
			uint8_t blue = 0;

			int iterations = fractal[y * WIDTH + x];
			double hue = 0.0;
			for(int i = 0; i <= iterations; i++){
				hue += (double)histogram[i]/total;
			}
		
			if(iterations != Mandelbrot::MAX_ITERATIONS){
				green = pow(255, hue);
			}

			bm.setPixel(x, y, red, green, blue);
		}
	}

	bm.write("outputs/test.bmp");
	std::cout << "Finished." << std::endl;

	return 0;
}

