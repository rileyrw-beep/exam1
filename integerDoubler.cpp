#include <iostream>
#include <vector>
#include <fstream>
#include <cstdint>

void integerDoubler(std::string inputFile, std::string outputFile) {
    std::vector<std::uint32_t> integers;
    std::ifstream inFile(inputFile, std::ios::binary);
    if (!inFile.is_open()) {
        std::cerr << "Error opening file " << inputFile << std::endl;
    }
    inFile.read(reinterpret_cast<char*>(integers.data()), sizeof(std::uint32_t));
    for (size_t i = 0; i < integers.size(); i++) {
        integers.at(i) *= 2;
    }
    std::ofstream outFile(outputFile, std::ios::binary);
    if (!outFile.is_open()) {
        std::cerr << "Error opening file " << outputFile << std::endl;
    }
    outFile.write(reinterpret_cast<char*>(integers.data()), sizeof(std::uint32_t));
}

