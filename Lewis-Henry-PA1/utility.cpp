#include "utility.h"
#include "stream.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void ValidateAll(const int argumentCount, const std::string& cipherType, const std::string& inputFilePath, const std::string& outputFilePath, const std::string& keyFilePath, const std::string& operationMode) {
    ValidateArgumentCount(argumentCount);
    ValidateCipherType(cipherType);
    std::string inputFile = FileToString(inputFilePath, false);
    std::string keyFile = FileToString(keyFilePath, true);
    ValidateModeOfOperation(operationMode);
}

// Function that checks for five arguments
// Exits program with cerr if incorrect
void ValidateArgumentCount(const int argumentCount) {
    if (argumentCount != 6) {
        std::cerr << "Incorrect number of arguments\n";
        exit(1);
    }
}
// Function that checks for validity of cipher type input
// Exits program with cerr if incorrect
void ValidateCipherType(const std::string& cipherType) {
    if (cipherType != "B" && cipherType != "S") {
        std::cerr << "Invalid Function Type\n";
        exit(1);
    }
}
// Function that checks for validity of mode of operation input
// Exits program with cerr if incorrect
void ValidateModeOfOperation(const std::string& operationMode) {
    if (operationMode != "D" && operationMode != "E") {
        std::cerr << "Invalid Mode Type\n";
        exit(1);
    }
}
//Function that reads file to string and returns it
//If no file present exit(1)
std::string FileToString(const std::string& inputFilePath, bool isKey) {
    std::ifstream inputFile(inputFilePath, std::ios::binary);
    std::string content;

    if (!inputFile) {
        std::cerr << (isKey ? "Key File Does Not Exist\n" :  "Input File Does Not Exist\n");
        exit(1);
    }
    
    content.assign((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());

    std::cout << content << "\n";

    return content;
}

void StartCipher(const std::string& cipherType, const std::string& inputFile, const std::string& outputFileAddress, const std::string& keyFile, const std::string& operationMode) {

    if (cipherType == "S") Stream(inputFile, outputFileAddress, keyFile);
    // else Block(inputFile, keyFile, outputFileAddress);
}