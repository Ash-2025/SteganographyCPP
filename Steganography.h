//
// Created by ash_25 on 2/12/24.
//

#ifndef STEGANOGRAPHY_H
#define STEGANOGRAPHY_H
#include <string>
#include "opencv2/opencv.hpp"
class Steganography {
    public:

    Steganography();
    bool encode(const std::string& imagePath, const std::string& outputPath, const std::string& message);
    std::string decode(const std::string& imagePath);


private:
    void embeddMessage(cv::Mat& image, const std::string& message);
    std::string extractMessage(cv::Mat& image);
};

#endif //STEGANOGRAPHY_H
