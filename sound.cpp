#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include "opencv2/opencv.hpp"
#include <string>

void wavToImg(const std::string &path)
{
    std::ifstream TextFile(path, std::ios::binary);
    if (!TextFile.is_open())
    {
        std::cerr << "Error: Could not open WAV file." << std::endl;
        return;
    }

    std::vector<unsigned char> TextData((std::istreambuf_iterator<char>(TextFile)), std::istreambuf_iterator<char>());
    TextFile.close();

    int totalbytes = TextData.size();
    int pixels = (totalbytes + 2) / 3;

    int width = static_cast<int>(std::ceil(std::sqrt(pixels)));

    int height = static_cast<int>(std::ceil(static_cast<double>(pixels) / width));

    // cv::Mat img = cv::Mat::zeros(height,width,CV_8UC1);
    cv::Mat img(height, width, CV_8UC3, cv::Scalar(0, 0, 0));

    // int index = 0;
    // for (int row = 0; row < height; ++row) {
    //     for (int col = 0; col < width; ++col) {

    //         if (index < totalbytes) img.at<cv::Vec3b>(row, col)[0] = TextData[index++]; // Red
    //         if (index < totalbytes) img.at<cv::Vec3b>(row, col)[1] = TextData[index++]; // Green
    //         if (index < totalbytes) img.at<cv::Vec3b>(row, col)[2] = TextData[index++]; // Blue
    //     }
    // }
    int index = 0;
    for (int row = 0; row < height; ++row)
    {
        for (int col = 0; col < width; ++col)
        {
            if (index < totalbytes)
            {
                // Map the ASCII value to a range of 0-255 and convert it to a color
                unsigned char val = TextData[index++];

                // Map the ASCII value to a range of colors in HSV
                int hue = val % 256;  // Use the ASCII value as hue
                int saturation = 255; // Full saturation
                int value = 255;      // Full brightness

                // Convert HSV to RGB
                // cv::Vec3b rgb = cvtColor(cv::Mat(1, 1, CV_8UC3, cv::Scalar(hue, saturation, value)), cv::COLOR_HSV2BGR).at<cv::Vec3b>(0, 0);
                // img.at<cv::Vec3b>(row, col) = rgb;

                cv::Mat hsv(1, 1, CV_8UC3, cv::Scalar(hue, saturation, value));
                cv::Mat rgb;
                cv::cvtColor(hsv, rgb, cv::COLOR_HSV2BGR);
                img.at<cv::Vec3b>(row, col) = rgb.at<cv::Vec3b>(0, 0);
            }
        }
    }
    cv::imwrite("/home/ash_25/Desktop/book2.png", img);
}

void encodeMp3ToImage(const std::string& mp3FilePath) {
    // Read MP3 file
    std::ifstream mp3File(mp3FilePath, std::ios::binary);
    if (!mp3File.is_open()) {
        std::cerr << "Error: Could not open MP3 file." << std::endl;
        return;
    }

    // Extract audio data from MP3 file
    std::vector<char> audioData;
    char buffer[4096];
    while (mp3File.read(buffer, 4096)) {
        audioData.insert(audioData.end(), buffer, buffer + 4096);
    }
    mp3File.close();

    // Pad audio data to be divisible by 3
    while (audioData.size() % 3 != 0) {
        audioData.push_back(0); // Padding with zeros
    }

    // Calculate image dimensions
    int width = std::sqrt(audioData.size() / 3);
    int height = (audioData.size() + 3 * width - 1) / (3 * width);

    // Create the image
    cv::Mat image(height, width, CV_8UC3, cv::Scalar(0));

    // Fill the image with the audio data
    int index = 0;
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            if (index < audioData.size()) image.at<cv::Vec3b>(row, col)[0] = audioData[index++]; // Blue
            if (index < audioData.size()) image.at<cv::Vec3b>(row, col)[1] = audioData[index++]; // Green
            if (index < audioData.size()) image.at<cv::Vec3b>(row, col)[2] = audioData[index++]; // Red
        }
    }

    // Save the image
    if (!cv::imwrite("/home/ash_25/Desktop/test.png", image)) {
        std::cerr << "Error: Could not save the image." << std::endl;
    }
}


int main()
{
    const std::string path = "/home/ash_25/Desktop/book.txt";
    const std::string path2 = "/home/ash_25/Music/beats.mp3";
    // wavToImg(path);
    encodeMp3ToImage(path2);
    return 0;
}