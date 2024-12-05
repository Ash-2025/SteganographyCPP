#include <iostream>
#include <fstream>
#include <sstream>

int main()
{
    std::ifstream file("/home/ash_25/Desktop/book.txt");
    if (!file.is_open())
        std::cerr << "File not found";

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string fileContent = buffer.str();

    std::cout<<"File size in byte or number of chars - " <<fileContent.length()<<std::endl;
    std::cout<< "File size in bits - " <<fileContent.length()*8;
    return 0;
}