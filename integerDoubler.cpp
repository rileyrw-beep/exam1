/*
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdint>
#include <string>

void integerDoubler(std::string inputFile, std::string outputFile) {
    std::vector<std::int32_t> integers;
    std::ifstream inFile(inputFile, std::ios::binary);
    if (!inFile.is_open()) {
        std::cerr << "Error opening file " << inputFile << std::endl;
    }

    while (true) {
        inFile.read(reinterpret_cast<char*>(integers.data()), integers.size());
        if (inFile.eof()) {
            break;
        }
    }

    inFile.close();


    for (size_t i = 0; i < integers.size(); i++) {
        integers.at(i) *= 2;
    }
    std::ofstream outFile(outputFile, std::ios::binary);
    if (!outFile.is_open()) {
        std::cerr << "Error opening file " << outputFile << std::endl;
    }

    for (size_t i = 0; i < integers.size(); i++) {
        outFile.write(reinterpret_cast<char*>(&integers.at(i)), sizeof(std::int32_t));
    }
    outFile.close();




}

*/