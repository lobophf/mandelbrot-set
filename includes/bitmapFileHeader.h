#ifndef BITMAPFILEHEADER_H
#define BITMAPFILEHEADER_H
#include <cstdint>

#pragma pack(2)

namespace bmp{
struct BitmapFileHeader{
	char header[2]{'B', 'M'};
	int32_t fileSize{0};
	int32_t reserved{0};
	int32_t dataOffset{0};
};
}

#endif
