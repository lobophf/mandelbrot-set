<h1 align="center"> Mandelbrot set </h1>

<p align="center">
  <img height="180px" alt="screenshot" src="https://dl.dropboxusercontent.com/s/g3i2o08odw4lvay/fractal1.jpg?dl=0">
  <img height="180px" alt="screenshot" src="https://dl.dropboxusercontent.com/s/atnz4s4u8ryy0o0/fractal2.jpg?dl=0">
  <br>
  <img alt="GitHub language count" src="https://img.shields.io/github/languages/count/lobophf/mandelbrotSet">	
  <img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/lobophf/mandelbrotSet">
  <img alt="License" src="https://img.shields.io/badge/license-MIT-brightgreen"> 
  <br>
  <a href="#question-about">About</a>&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
  <a href="#hammer_and_wrench-installation">Installation</a>&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
  <a href="#gear-using">Using</a>&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
  <a href="#balance_scale-license">License</a>	
<p>

## :question: About:
This library draws the Mandelbrot set and writes it out as a bitmap (BMP) file. To know more about this
subject, please see [this](https://en.wikipedia.org/wiki/Mandelbrot_set) page. You can do as I did and 
get additional information by checking [John's](https://twitter.com/caveofjohn?lang=en) course on 
[Udemy](https://www.udemy.com/course/learn-advanced-c-programming/).

## :hammer_and_wrench: Installation:
First, clone this repository and jump into the `mandelbrotSet` folder.

```sh
$ git clone git@github.com:lobophf/mandelbrotSet.git 
$ cd mandelbrotSet
```

You can easily modify the `Makefile` available in this repository, to include 
this library in your project. Once you've done it, just type:

```sh
$ make
```
If you run the program, the bitmap file will be placed wherever you have set it. See the 
`main.cpp` file for reference.

## :gear: Using:
I'm still improving this library in order to make it easier to use. For now, 
to create the images by yourself, you need to know some stuff shown below.

First off, add the *FractalCreator.h* header into your code, and put the 
*FractalCreator* object, passing the *width* and *height* as arguments.

```C
#include "includes/fractalCreator.h"

int const WIDTH = 1600;
int const HEIGHT = 800;
FractalCreator frac(WIDTH, HEIGHT); 
```
Now, you must use the *addRange* method to define the histogram colors. The first argument 
is a position in the scale, between *0* and *1* to be marked by some color. The *RGB* struct, 
as the name suggests, is the color itself in RGB format. It is necessary to provide at least 
the values at these two bounds.

```C
frac.addRange(0.0, RGB(  0,   0,   0));
/* Set some additional colors in the middle 
   of the scale range. */
/* 
frac.addRange(0.4, RGB(  0, 230, 255));
frac.addRange(0.8, RGB( 72,   0, 255));
*/
frac.addRange(1.0, RGB(  0,   0, 255));
```

Then, you must use the *Zoom* structure combined with the *addZoom* method to 
navigate over the bitmap image. The first two arguments of the *Zoom* struct are 
the pixel coordinates. By default, the start position is centered at the origin 
of the [complex plane](https://en.wikipedia.org/wiki/Complex_plane). The third 
argument is a number that represents the zoom. The lower its value, the deeper we 
go into fractals.

You can "add zooms" many times you want to plan your trip. However, keep in mind 
that at each step, you must choose a new pixel as the zoom focus, based on the 
image dimensions.

```C
frac.addZoom(Zoom( 500, 366, 0.10));
frac.addZoom(Zoom( 522,  20, 0.05));
frac.addZoom(Zoom(1268, 106, 0.30));
```

Finally, the *run* method creates the bitmap file, whose address is passed as an argument.

```C
frac.run("outputs/test.bmp");
```

## :balance_scale: License
This application is a MIT licensed, as found in the [LICENSE](./LICENSE) file.
