#include "stream.h"
#include "utility.h"
#include <iostream>
#include <fstream>

Stream::Stream(const std::string& inputFile, const std::string& outputFileLocation, const std::string& keyFile) {
    std::string inputContent = FileToString(inputFile, false);
    std::string keyContent = FileToString(keyFile, true);
    size_t inputContentSize = inputContent.size();

    std::string outputString = XOR(inputContent, keyContent);
    AdjustStringLength(outputString, inputContentSize);

    CreateOutputFile(outputFileLocation, outputString);
};
