	#include "includes/bitmap.h"
	#include "includes/mandelbrot.h"
	#include "includes/zoomList.h"
	#include "includes/zoom.h"
	#include <iostream>
	#include <cstdint>
	#include <memory>
	#include <math.h>

	int main(){

		int const WIDTH = 1800;
		int const HEIGHT = 1200;

		bmp::Bitmap bm(WIDTH, HEIGHT);

		ZoomList z(WIDTH, HEIGHT);
		z.add(Zoom(WIDTH / 2, HEIGHT / 2, 4.0 / WIDTH));
		z.add(Zoom(521, HEIGHT - 499, 0.1));
		z.add(Zoom(164, HEIGHT - 222, 0.1));
		z.add(Zoom(882, HEIGHT - 483, 0.05));

		std::unique_ptr<int[]> histogram(new int[Mandelbrot::MAX_ITERATIONS]{0});
	std::unique_ptr<int[]> fractal(new int[WIDTH * HEIGHT]{0});
	
	for(int y = 0; y < HEIGHT; y++){
		for(int x = 0; x < WIDTH; x++){

			std::pair<double, double> coordenates = z.doZoom(x, y);
			int iterations = Mandelbrot::getIterations(coordenates.first, coordenates.second);
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

