#ifndef BITMAP_H_
#define BITMAP_H_
#include<string>
#include<cstdint>

namespace bmp{
class Bitmap{
private:
	int _width{0};
	int _height{0};


public:
	Bitmap(int width, int height);
	void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
	bool write(std::string fileName);
};
}

#endif
