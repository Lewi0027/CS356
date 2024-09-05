#include "stream.h"
#include "utility.h"
#include <iostream>
#include <fstream>


Stream::Stream(const std::string& inputFile, const std::string& keyFile, const std::string& outputFileLocation) {
    std::string inputContent = FileToString(inputFile, false);
    std::string keyContent = FileToString(keyFile, true);
    
    std::string outputString = StreamXOR(inputContent, keyContent);

    CreateOutputFile(outputFileLocation, outputString);
};

std::string Stream::StreamXOR(const std::string& input, const std::string& key) {
    std::string returnString = input;  
    size_t keySize = key.size();
    size_t inputSize = input.size();

    for (unsigned int i = 0; i < inputSize; i++) {
        returnString[i] ^= (key[i % keySize]);
    };

    return returnString;
};

void Stream::CreateOutputFile(const std::string& outputFileLocation, const std::string& output) {
    std::ofstream outputFile(outputFileLocation);

    if (outputFile.is_open()) {
        outputFile << output;
        outputFile.close();
    }

};