#include "utility.h"
#include "block.h"
#include <iostream>

Block::Block(const std::string& inputFile, const std::string& outputFileLocation, const std::string& keyFile, const std::string& operationMode) {
    // Create strings out of input file and key file
    std::string inputContent = FileToString(inputFile, false);
    std::string keyContent = FileToString(keyFile, true);
    size_t inputContentSize = inputContent.size();

    // Pad input file string
    inputContent = PadString(inputContent);
    
    // XOR strings together and trim as needed
    std::string outputString = XOR(inputContent, keyContent);
    AdjustStringLength(outputString, inputContentSize);

    // Create blocks out of string
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

    // Turn blocks back into string
    outputString = BlockToString(inputBlocks, inputContentSize);

    // Create output file and copy string to file
    CreateOutputFile(outputFileLocation, outputString);
};

// PAD & BLOCK FUNCTIONS
// Pad string as needed (to complete 16 bytes)
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
// Create vectors of 16 byte blocks
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
// Convert block back to string
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

// ALGORITHM FUNCTIONS
// Encrypt swap
std::vector<uint8_t> Block::BlockSwapForward(const std::vector<uint8_t>& inputBlock) {

    return inputBlock;
};
// Decrypt swap
std::vector<uint8_t> Block::BlockSwapReverse(const std::vector<uint8_t>& inputBlock) {

    return inputBlock;
};

// HELPER PRINT FUNCTIONS
// Print block
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
// Print string
void Block::PrintString(const std::string& string) {
    std::cout << string;
};