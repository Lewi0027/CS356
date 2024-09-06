#include "utility.h"
#include "block.h"
#include <iostream>

Block::Block(const std::string& inputFile, const std::string& outputFileLocation, const std::string& keyFile, const std::string& operationMode) {
    std::string inputContent = FileToString(inputFile, false);
    std::string keyContent = FileToString(keyFile, true);

    size_t inputContentSize = inputContent.size();
    inputContent = PadString(inputContent);
    std::string outputString = XOR(inputContent, keyContent);

    // if (operationMode == "E") {
    //     outputString = ByteSwapForward(outputString);
    // }
    // else {
    //     outputString = ByteSwapReverse(outputString);
    // }

    AdjustStringLength(outputString, inputContentSize);

    CreateOutputFile(outputFileLocation, outputString);

};

std::string Block::PadString(const std::string& inputContent) {
    std::string returnString = inputContent;
    size_t blockSize = 16;
    size_t inputSize = inputContent.size();

    size_t padding = blockSize - (inputSize % blockSize);
    if (padding < blockSize) {
        returnString.append(padding, '\x81');
    }

    return returnString;
};

// void Block::RemoveEOFByte(std::string& outputString) {
//     if (!outputString.empty()) {
//         if (static_cast<unsigned char>(outputString.back()) == 0xCA) {
//             outputString.pop_back();
//         }
//     }
// }

std::string Block::ByteSwapForward(const std::string& inputContent) {
    std::string returnString = inputContent;

    return returnString;
};

std::string Block::ByteSwapReverse(const std::string& inputContent) {
    std::string returnString = inputContent;

    return returnString;
};