#include "includes/bitmap.h"
#include <iostream>

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

			if(xFractal < min) min = xFractal;
			if(xFractal > max) max = xFractal;
		}
	}

	std::cout << min << ", " << max << std::endl;

	bm.setPixel(width / 2, height / 2, 255, 255, 255);
	bm.write("outputs/test.bmp");

	std::cout << "Finished." << std::endl;

	return 0;
}

