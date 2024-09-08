#include "utility.h"
#include "stream.h"
#include "block.h"

#include <iostream>
#include <fstream>
#include <string>

// MASTER
void StartCipher(int argumentCount, const std::string& cipherType, const std::string& inputFile, const std::string& outputFileAddress, const std::string& keyFile, const std::string& operationMode) {
    // Validate parameters
    ValidateAll(argumentCount, cipherType, inputFile, outputFileAddress, keyFile, operationMode);

    // Start block/stream cipher
    if (cipherType == "S") Stream(inputFile, outputFileAddress, keyFile);
    else Block(inputFile, outputFileAddress, keyFile, operationMode);
}

// VALIDATORS
// Validate all
void ValidateAll(const int argumentCount, const std::string& cipherType, const std::string& inputFilePath, const std::string& outputFilePath, const std::string& keyFilePath, const std::string& operationMode) {
    ValidateArgumentCount(argumentCount);
    ValidateCipherType(cipherType);
    ValidateFileExists(inputFilePath, false);
    ValidateFileExists(keyFilePath, true);
    ValidateModeOfOperation(operationMode);
}
// Checks for five arguments
void ValidateArgumentCount(const int argumentCount) {
    if (argumentCount != 6) {
        std::cerr << "Incorrect number of arguments\n";
        exit(1);
    }
}
// Checks for validity of cipher type input
void ValidateCipherType(const std::string& cipherType) {
    if (cipherType != "B" && cipherType != "S") {
        std::cerr << "Invalid Function Type\n";
        exit(1);
    }
}
// Checks for validity of mode of operation input
void ValidateModeOfOperation(const std::string& operationMode) {
    if (operationMode != "D" && operationMode != "E") {
        std::cerr << "Invalid Mode Type\n";
        exit(1);
    }
}
// Checks that a file exists at provided location
void ValidateFileExists(const std::string& filePath, bool isKey) {
    std::ifstream file(filePath);
    if (!file) {
        std::cerr << (isKey ? "Key File Does Not Exist\n" :  "Input File Does Not Exist\n");
        std::exit(1);
    }
}

// STRING & OUTPUT FUNCTIONS
// Reads file to string and returns it
std::string FileToString(const std::string& inputFilePath, bool isKey) {
    std::ifstream inputFile(inputFilePath, std::ios::binary);
    std::string content;
    
    content.assign((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());

    // std::cout << content << "\n";

    return content;
}
// Adjusts string to provided length if longer
void AdjustStringLength(std::string& inputString, size_t length) {
    while (inputString.size() > length) {
        inputString.pop_back();
    }
} 
// XORs two files together, looping through the key repeatedly
std::string XOR(const std::string& input, const std::string& key) {
    std::string returnString = input;
    size_t keySize = key.size();
    size_t inputSize = input.size();

    // Debugging information
    std::cout << "returnString size: " << returnString.size() << std::endl;
    std::cout << "key size: " << keySize << std::endl;
    std::cout << "input size: " << inputSize << std::endl;

    for (unsigned int i = 0; i < inputSize; i++) {
        returnString[i] ^= key[i % keySize];
    }

    PrintResults(returnString);

    return returnString;
}
// Creates output file and populates it with content from provided string.
void CreateOutputFile(const std::string& outputFileLocation, const std::string& output) {
    std::ofstream outputFile(outputFileLocation, std::ios::binary);

    if (outputFile.is_open()) {
        outputFile.write(output.c_str(), output.size());
        outputFile.close();
    }
}
// Print result as hex
void PrintResults(const std::string& returnString) {
    std::cout << "returnString (hex): ";
    for (unsigned char c : returnString) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(c) << ' ';
    }
    std::cout << std::dec << std::endl;
}