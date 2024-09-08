#include "stream.h"
#include "utility.h"
#include <iostream>
#include <fstream>

Stream::Stream(const std::string& inputFile, const std::string& outputFileLocation, const std::string& keyFile) {
    // Create strings out of input file and key file
    std::string inputContent = FileToString(inputFile, false);
    std::string keyContent = FileToString(keyFile, true);
    size_t inputContentSize = inputContent.size();

    // XOR strings together and trim as needed
    std::string outputString = XOR(inputContent, keyContent);
    AdjustStringLength(outputString, inputContentSize);

    // Create output file and copy string to file
    CreateOutputFile(outputFileLocation, outputString);
};
