#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include "bitmap.h"
#include "mandelbrot.h"
#include "zoomList.h"
#include "zoom.h"
#include <cstdint>
#include <memory>
#include <math.h>

class FractalCreator{
private:
	int _width;
	int _height;
	int _total{0};
	bmp::Bitmap _bitmap;
	std::unique_ptr<int[]> _histogram;
	std::unique_ptr<int[]> _fractal;
	ZoomList _zoomList;

private:
	void addZoom(const Zoom& zoom);
	void writeBitmap(std::string fileName);
	void calculateIterations();
	void drawFractal();
	void calculateTotalIterations();

public:
	FractalCreator(int width, int height);
	void run(std::string fileName);
};

#endif
