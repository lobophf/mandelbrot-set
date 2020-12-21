#ifndef BITMAP_H_
#define BITMAP_H_
#include <string>
#include <cstdint>
#include <fstream>
#include <memory>
#include "bitmapInfoHeader.h"
#include "bitmapFileHeader.h"

namespace bmp{
class Bitmap{
private:
	int _width{0};
	int _height{0};
	std::unique_ptr<uint8_t[]> _pPixels{nullptr};

public:
	Bitmap(int width, int height);
	void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
	bool write(std::string fileName);
};
}

#endif
