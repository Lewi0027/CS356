#include "utility.h"
#include "block.h"
#include <iostream>

Block::Block(const std::string& inputFile, const std::string& outputFileLocation, const std::string& keyFile, const std::string& operationMode) {
    std::string inputContent = FileToString(inputFile, false);
    std::string keyContent = FileToString(keyFile, true);

    size_t inputContentSize = inputContent.size();
    inputContent = PadString(inputContent);
    std::string outputString = XOR(inputContent, keyContent);

    AdjustStringLength(outputString, inputContentSize);

    std::vector<std::vector<uint8_t>> inputBlocks = CreateBlocks(outputString);
    // PrintBlocks(inputBlocks);

    // if (operationMode == "E") {
    //     for (size_t i = 0; i < inputBlocks.size(); i++) {
    //         BlockSwapForward(inputBlocks[i]);
    //     }
    // }
    // else {
    //     for (size_t i = 0; i < inputBlocks.size(); i++) {
    //         BlockSwapReverse(inputBlocks[i]);
    //     }
    // }

    outputString = BlockToString(inputBlocks, inputContentSize);

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

std::vector<std::vector<uint8_t>> Block::CreateBlocks(const std::string& inputString) {
    std::vector<std::vector<uint8_t>> returnVector;

    size_t blockSize = 16;
    size_t inputStringSize = inputString.size();
    size_t numberOfBlocks = ((inputStringSize - 1) / blockSize) + 1;

    returnVector.resize(numberOfBlocks);
    
    for (size_t i = 0; i < numberOfBlocks; i++) {
        returnVector[i].resize(blockSize);
    }

    for (size_t i = 0; i < inputStringSize; i++ ) {
        returnVector[i / blockSize][ i % blockSize] = static_cast<uint8_t>(inputString[i]);
    }

    return returnVector;
};

std::string Block::BlockToString(const std::vector<std::vector<uint8_t>>& inputBlocks, size_t inputContentSize) {
    std::string returnString;

    for (const auto& block : inputBlocks) {
        for (uint8_t byte : block) {
            returnString += static_cast<char>(byte);
        }
    }

    size_t trimSize = returnString.size();

    if (returnString.size() > inputContentSize) {
        while (trimSize > inputContentSize && returnString[trimSize - 1] == '\x81') {
            trimSize--;
        }
        returnString = returnString.substr(0, trimSize - 1);
    }

    return returnString;
};

void Block::PrintBlocks(const std::vector<std::vector<uint8_t>>& blocks) {
    int blockNumber = 0;
    
    for (const auto& block : blocks) {
        std::cout << "Block " << blockNumber++ << std::endl;
        for (uint8_t byte : block) {
            std::cout << static_cast<char>(byte);
        }
        std::cout << std::endl;
    }
}

void Block::PrintString(const std::string& string) {
    std::cout << string;
};

std::vector<uint8_t> Block::BlockSwapForward(const std::vector<uint8_t>& inputBlock) {

    return inputBlock;
};

std::vector<uint8_t> Block::BlockSwapReverse(const std::vector<uint8_t>& inputBlock) {

    return inputBlock;
};