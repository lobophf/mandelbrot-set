#include "fractalCreator.h"

FractalCreator::FractalCreator(int width, int height): _width(width),
				         _height(height),
					 _bitmap(_width, _height),
					 _histogram(new int[Mandelbrot::MAX_ITERATIONS]{0}),
					 _fractal(new int[_width * _height]{0}),
					 _zoomList(_width, _height){
					 
	_zoomList.add(Zoom(_width / 2, _height/ 2, 4.0 / _width));

}

void FractalCreator::addZoom(const Zoom& zoom){
	_zoomList.add(zoom);
}

void FractalCreator::writeBitmap(std::string fileName){
	_bitmap.write(fileName);
}

void FractalCreator::drawFractal(){
	for(int y = 0; y < _height; y++){
		for(int x = 0; x < _width; x++){

			uint8_t red = 0;
			uint8_t green = 0;
			uint8_t blue = 0;

			int iterations = _fractal[y * _width + x];
			double hue = 0.0;
			for(int i = 0; i <= iterations; i++){
				hue += (double)_histogram[i]/_total;
			}
		
			if(iterations != Mandelbrot::MAX_ITERATIONS){
				green = pow(255, hue);
			}

			_bitmap.setPixel(x, y, red, green, blue);
		}
	}
}

void FractalCreator::calculateTotalIterations(){
	_total = 0;
	for(int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++){
		_total += _histogram[i];
	}
}

void FractalCreator::calculateIterations(){

	for(int y = 0; y < _height; y++){
		for(int x = 0; x < _width; x++){

			std::pair<double, double> coordenates = _zoomList.doZoom(x, y);
			int iterations = Mandelbrot::getIterations(coordenates.first, coordenates.second);
			_fractal[y * _width + x] = iterations;
			if(iterations != Mandelbrot::MAX_ITERATIONS){
				_histogram[iterations]++;
			}
		}
	}
}
