OpenCV Steganography Tool
A C++ tool for hiding secret messages within images using steganography, built using OpenCV.
Table of Contents
Features
Requirements
Installation
Usage
Example Use Cases
License
Contributing
Features
Hide secret messages within images using least significant bit (LSB) substitution
Support for various image formats, including PNG, JPEG, and BMP
Command-line interface for easy usage
Optional encryption of secret messages using XOR cipher
Requirements
OpenCV 3.x or 4.x
C++11 or later compiler
PNG, JPEG, or BMP image files
Installation
Clone the repository: git clone https://github.com/your-username/opencv-steganography-tool.git
Install OpenCV: Follow the installation instructions for your operating system
Compile the tool: g++ -std=c++11 opencv_steganography_tool.cpppkg-config --cflags --libs opencv4-o opencv_steganography_tool
Usage
Hide a secret message: ./opencv_steganography_tool -e -i input_image.png -m "Hello, World!" -o output_image.png
Extract a secret message: ./opencv_steganography_tool -d -i input_image.png -o output_message.txt
Example Use Cases
Hide a secret message within an image: ./opencv_steganography_tool -e -i input_image.png -m "This is a secret message." -o output_image.png
Extract a secret message from an image: ./opencv_steganography_tool -d -i input_image.png -o output_message.txt
License
This project is licensed under the MIT License.
Contributing
Contributions are welcome! If you'd like to contribute to this project, please fork the repository and submit a pull request.
Note: Replace your-username with your actual GitHub username.