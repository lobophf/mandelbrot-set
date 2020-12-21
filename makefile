header_and_cpp_dir=includes
objects_dir=objects
outputs_dir=outputs

compile: create_dir fractalCreator main RBG clean
	g++ $(objects_dir)/main.o $(objects_dir)/bitmap.o $(objects_dir)/mandelbrot.o \
	$(objects_dir)/zoomList.o $(objects_dir)/fractalCreator.o $(objects_dir)/rgb.o \
	-o main.out

zoom:
	g++ -std=c++11 -c $(header_and_cpp_dir)/zoom.h -o $(objects_dir)/zoom.o

zoomList: zoom $(header_and_cpp_dir)/zoomList.h
	g++ -std=c++11 -c $(header_and_cpp_dir)/zoomList.cpp -o $(objects_dir)/zoomList.o

bitmapFileHeader:
	g++ -std=c++11 -c $(header_and_cpp_dir)/bitmapFileHeader.h -o $(objects_dir)/bitmapFileHeader.o

bitmapInfoHeader:
	g++ -std=c++11 -c $(header_and_cpp_dir)/bitmapInfoHeader.h -o $(objects_dir)/bitmapInfoHeader.o

bitmap: $(header_and_cpp_dir)/bitmap.h
	g++ -std=c++11 -c $(header_and_cpp_dir)/bitmap.cpp -o $(objects_dir)/bitmap.o

mandelbrot: $(header_and_cpp_dir)/mandelbrot.h
	g++ -std=c++11 -c $(header_and_cpp_dir)/mandelbrot.cpp -o $(objects_dir)/mandelbrot.o

main:
	g++ -c -std=c++11 main.cpp -o $(objects_dir)/main.o 

fractalCreator: bitmapFileHeader bitmapInfoHeader bitmap mandelbrot zoomList \
	$(header_and_cpp_dir)/fractalCreator.h
	g++ -c -std=c++11 $(header_and_cpp_dir)/fractalCreator.cpp -o $(objects_dir)/fractalCreator.o

RBG: $(header_and_cpp_dir)/rgb.h
	g++ -std=c++11 -c $(header_and_cpp_dir)/rgb.cpp -o $(objects_dir)/rgb.o

create_dir:
	mkdir -p $(objects_dir) 
	mkdir -p $(outputs_dir) 

run:
	./main.out

clean:
	rm -rf $(header_and_cpp_dir)/*.gch
