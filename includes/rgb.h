#ifndef RGB_H_
#define RGB_H_

struct RGB{
	RGB(double r, double g, double b);

	double r, g, b;
};

RGB operator-(const RGB& first, const RGB second);
#endif
