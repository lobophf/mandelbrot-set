#ifndef MANDELBROT_H_
#define MANDELBROT_H_

#include <complex>

class Mandelbrot{
public:
	static const int MAX_ITERATIONS = 1000;

public:
	Mandelbrot();
	int static getIterations(double x, double y);

};
#endif
