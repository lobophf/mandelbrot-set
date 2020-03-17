header_and_cpp_dir=includes
objects_dir=objects
outputs_dir=outputs

compile: create_dir bitmapFileHeader bitmapInfoHeader bitmap mandelbrot main clean
	g++ $(objects_dir)/main.o $(objects_dir)/bitmap.o $(objects_dir)/mandelbrot.o -o main.out

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

create_dir:
	mkdir -p $(objects_dir) 
	mkdir -p $(outputs_dir) 

run:
	./main.out

clean:
	rm -rf $(header_and_cpp_dir)/*.gch
