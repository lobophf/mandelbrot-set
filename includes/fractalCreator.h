#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include "bitmap.h"
#include "mandelbrot.h"
#include "zoomList.h"
#include "zoom.h"
#include "rgb.h"
#include <cstdint>
#include <vector>
#include <memory>
#include <math.h>
#include <assert.h>

class FractalCreator{
private:
	int _width;
	int _height;
	int _total{0};
	bmp::Bitmap _bitmap;
	std::unique_ptr<int[]> _histogram;
	std::unique_ptr<int[]> _fractal;
	ZoomList _zoomList;
	
	std::vector<int> _ranges;
	std::vector<RGB> _colors;
	std::vector<int> _rangeTotals;

	bool _bGotFirstRange{false};

private:
	void writeBitmap(std::string fileName);
	void calculateRangeTotals();
	void calculateIterations();
	void drawFractal();
	void calculateTotalIterations();

public:
	FractalCreator(int width, int height);
	void addZoom(const Zoom& zoom);
	void run(std::string fileName);
	void addRange(double rangeEnd, const RGB& rgb);
	int getRange(int iterations) const;
};

#endif
