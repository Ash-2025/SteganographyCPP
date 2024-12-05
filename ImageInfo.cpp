//
// Created by ash_25 on 3/12/24.
//

#include "ImageInfo.h"
#include<string>
#include<iostream>

ImageInfo::ImageInfo(cv::Mat Image, const std::string& path) {

    this->width = Image.cols;
    this->height = Image.rows;
    this->numChannels = Image.channels();

    this->bitDepth = Image.elemSize1() * 8;
    this->imageSize = Image.elemSize() * Image.total();

    // Determine color mode
    this->ColorMode = (numChannels == 1) ? "Grayscale" : "Color";

    // Extract format (e.g., from file extension)
    this->format = path.substr(path.find_last_of(".") + 1);
    // this->format
};

void ImageInfo::GetImageInfo() {
    std::cout << "Width: " << width << "\n";
    std::cout << "Height: " << height << "\n";
    std::cout << "Format: " << format << "\n";
    std::cout << "Color Mode: " << ColorMode << "\n";
    std::cout << "Bit Depth: " << bitDepth << "\n";
    std::cout << "Number of Channels: " << numChannels << "\n";
    std::cout << "Image Size: " << imageSize << " bytes\n";
}



