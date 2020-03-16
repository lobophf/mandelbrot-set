#include "bitmap.h"

bmp::Bitmap::Bitmap(int width, int height): _width(width), _height(height), _pPixels(new uint8_t[width * height * 3]){

}

bool bmp::Bitmap::write(std::string fileName){
	return false;
}

void bmp::Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue){

}
