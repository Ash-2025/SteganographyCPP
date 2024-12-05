//
// Created by ash_25 on 2/12/24.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include "Steganography.h"
#include "ImageInfo.h"
using namespace std;

int main()
{
  string path = "/home/ash_25/Desktop/lotr.jpg";

  cv::Mat img = cv::imread(path);

  string save = "/home/ash_25/Desktop";

  // read the file content
  std::string filepath = "/home/ash_25/Desktop/book.txt";
  std::ifstream file(filepath);

  if (!file.is_open())
    std::cerr << "File not found";

  std::stringstream buffer;
  buffer << file.rdbuf();
  std::string fileContent = buffer.str();

  file.close();

  Steganography stego;
  if (stego.encode(path, save += "/encoded_img.png", fileContent))
  {
    cv::Mat img = cv::imread("/home/ash_25/Desktop/encoded_img.png");
    cv::imshow("encoded_image",img);
  }

  std::string decodedData = stego.decode("/home/ash_25/Desktop/lotr.png");

    // Write the decoded data to a text file
    std::ofstream outFile("/home/ash_25/Desktop/decoded_text.txt");
    if (!outFile.is_open()) {
        std::cerr << "Failed to open the output file for writing!" << std::endl;
        return -1;
    }
    outFile << decodedData; // Write decoded data to the file
    outFile.close(); // Close the file
  return 0;
}
