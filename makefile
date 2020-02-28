header_and_cpp_dir=includes
objects_dir=objects

compile: create_dir bitmapFileHeader main clean
	g++ $(objects_dir)/main.o -o main.out

bitmapFileHeader: $(header_and_cpp_dir)/bitmapFileHeader.h
	g++ -std=c++11 -c $(header_and_cpp_dir)/bitmapFileHeader.h -o $(objects_dir)/bitmapFileHeader.o

main:	$(header_and_cpp_dir)/bitmapFileHeader.h
	g++ -c -std=c++11 main.cpp -o $(objects_dir)/main.o

create_dir:
	mkdir -p $(objects_dir) 

run:
	./main.out

clean:
	rm -rf $(header_and_cpp_dir)/*.gch
