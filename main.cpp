#include "includes/bitmap.h"
#include <iostream>

int main(){

	int const width = 800;
	int const height = 600;

	bmp::Bitmap bm(width, height);
	bm.setPixel(width / 2, height / 2, 255, 255, 255);
	bm.write("test.bmp");

	std::cout << "Finished." << std::endl;

	return 0;
}

