//
// Created by ash_25 on 3/12/24.
//

#ifndef IMAGEINFO_H
#define IMAGEINFO_H
#include<string>
#include "opencv2/opencv.hpp"
class ImageInfo {
public:
    int width;
    int height;
    std::string format;
    std::string ColorMode;
    size_t bitDepth;
    int numChannels;

    std::string CompressionType;
    int qualityFactor;
    long imageSize;

    ImageInfo(cv::Mat Image, const std::string& path);

    void GetImageInfo();
};
#endif //IMAGEINFO_H
