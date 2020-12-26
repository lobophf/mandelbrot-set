<h1 align="center"> Mandelbrot set </h1>

<p align="center">
  <img height="180px" alt="screenshot" src="https://dl.dropboxusercontent.com/s/86zpogykuljeds9/test.bmp?dl=0">
  <img height="180px" alt="screenshot" src="https://dl.dropboxusercontent.com/s/4v1usq5w8732sx3/test1.bmp?dl=0">
  <br>
  <a href="#question-about">About</a>&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
	<a href="#hammer_and_wrench-installation">Installation</a>&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
	<a href="#balance_scale-license">License</a>	
  <br>
  <img alt="GitHub language count" src="https://img.shields.io/github/languages/count/lobophf/mandelbrotSet">	
  <img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/lobophf/mandelbrotSet">
  <img alt="License" src="https://img.shields.io/badge/license-MIT-brightgreen"> 
<p>

## :question: About:
This program draws the Mandelbrot set and writes it out as a Bitmap (BMP) file. To know more about the Mandelbrot Set please see [this](https://en.wikipedia.org/wiki/Mandelbrot_set) page.

## :hammer_and_wrench: Installation:
To draw the Mandelbroat, first clone this repository and jump into the `mandelbroatSet`folder.

```sh
$ git clone git@github.com:lobophf/mandelbrotSet.git 
$ cd mandelbrotSet
```

Then compile this project using the GNU make:

```sh
$ make
```
And then, run this. A Bitmap file will be created in the `outputs` folder.

```sh
$ make run
```
## :balance_scale: License
This application is a MIT licensed, as found in the [LICENSE](https://github.com/lobophf/happy/blob/master/LICENSE) file.
