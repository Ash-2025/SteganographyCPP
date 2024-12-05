//
// Created by ash_25 on 2/12/24.
//

#include "Steganography.h"

#include <bitset>
#include<string>
Steganography::Steganography(){} ;

bool Steganography::encode(const std::string& imagePath, const std::string& outputPath, const std::string& message) {
    cv::Mat img = imread(imagePath,cv::IMREAD_COLOR);
    if (img.empty()) {
        std::cerr << "Failed to open image: " << imagePath << std::endl;
        return false;
    }
    embeddMessage(img,message);
    if (!imwrite(outputPath, img)) {
        std::cerr << "Failed to write image: " << outputPath << std::endl;
        return false;
    }
    return true;
}

std::string Steganography::decode(const std::string &imagePath) {
    cv::Mat img = cv::imread(imagePath,cv::IMREAD_COLOR);
    if (img.empty()) {
        std::cerr << "Failed to open image: " << imagePath << std::endl;
        return "";
    }
    return  extractMessage(img);
    // return "";
}

void Steganography::embeddMessage(cv::Mat &image, const std::string &message) {
    std::string binaryMessage;

    for (char c: message) {
        binaryMessage += std::bitset<8>(c).to_string();
    }
    binaryMessage += "00000000";

    int rows = image.rows;
    int cols = image.cols;
    size_t messageIndex = 0;
    unsigned long size = binaryMessage.size();

    for (int i=0; i<rows ; ++i ) {
        for (int j=0; j<cols ; ++j ) {
            cv::Vec3b& pixel = image.at<cv::Vec3b>(i,j);

            for (int channel=0; channel<3; channel++) {
                if (messageIndex < size) {
                    pixel[channel] &= ~1;
                    pixel[channel] |= (binaryMessage[messageIndex] - '0');
                    messageIndex++;
                    if (messageIndex == size) break;
                }
            }
        }
    }

}

std::string Steganography::extractMessage(cv::Mat& img) {
    std::string binaryMessage;
    int rows = img.rows;
    int cols = img.cols ;

    for (int i=0; i<rows ; ++i) {
        for (int j=0; j<cols ; ++j ) {
            cv::Vec3b& pixel = img.at<cv::Vec3b>(i,j);
            for (int channel=0; channel<3; ++channel) {
                binaryMessage += std::to_string(pixel[channel] & 1);
            }
        }
    }

    //convert binary message to extract text
    std::string message;
    for (size_t i=0; i<binaryMessage.size(); i+=8 ) {
        std::string byte = binaryMessage.substr(i,8);
        if (byte == "00000000") {
            break;
        }
        char c = std::bitset<8>(byte).to_ulong();
        message += c;
    }
    return message.length() > 0 ? message : "ye to khali hai";
    // return "no message found";
}

