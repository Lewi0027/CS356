#include "utility.h"
#include "block.h"

#include <iomanip>
#include <iostream>

Block::Block(const std::string& inputFile, const std::string& outputFileLocation, const std::string& keyFile, const std::string& operationMode) {
    // Create strings out of input file and key file
    std::string inputContent = FileToString(inputFile, false);
    const std::string keyContent = FileToString(keyFile, true);
    // std::cout << "initial key size: " << keyContent.size() << std::endl;

    if (operationMode == "E") {
        // Determine the fixed width for all labels
        const int labelWidth = 22;

        // Print inputContent
        std::cout << std::setfill(' ');
        std::cout << std::setw(labelWidth) << std::left << "inputContent: ";
        PrintResults(inputContent);

        // Pad input file string
        inputContent = PadString(inputContent);

        // Print inputContent w/ padding
        std::cout << std::setfill(' ');
        std::cout << std::setw(labelWidth) << std::left << "inputContent w/ pad: ";
        PrintResults(inputContent);

        // Print keyContent
        std::cout << std::setfill(' ');
        std::cout << std::setw(labelWidth) << std::left << "keyContent: ";
        PrintResults(keyContent);

        // XOR strings together and trim as needed
        std::string outputString = XOR(inputContent, keyContent);

        // Print XOR results
        std::cout << std::setfill(' ');
        std::cout << std::setw(labelWidth) << std::left << "XOR results: ";
        PrintResults(outputString);

        // Create blocks out of string
        std::vector<std::vector<char>> inputBlocks = CreateBlocks(outputString);

        // Swap algorithm
        for (size_t i = 0; i < inputBlocks.size(); i++) {
            BlockSwapAlgorithm(inputBlocks[i], keyContent);
        }

        // Turn blocks back into string
        outputString = BlockToString(inputBlocks);

        // Print Block Swapped results
        std::cout << std::setfill(' ');
        std::cout << std::setw(labelWidth) << std::left << "Block Swapped: ";
        PrintResults(outputString);

        // Create output file and copy string to file
        CreateOutputFile(outputFileLocation, outputString);
    }
    else {
        // Determine the fixed width for all labels
        const int labelWidth = 22;

        // Print inputContent
        std::cout << std::setfill(' ');
        std::cout << std::setw(labelWidth) << std::left << "inputContent: ";
        PrintResults(inputContent);

        // Print keyContent
        std::cout << std::setfill(' ');
        std::cout << std::setw(labelWidth) << std::left << "keyContent: ";
        PrintResults(keyContent);

        // Create blocks out of input string
        std::vector<std::vector<char>> inputBlocks = CreateBlocks(inputContent);
        
        // Swap algorithm
        for (size_t i = 0; i < inputBlocks.size(); i++) {
            BlockSwapAlgorithm(inputBlocks[i], keyContent);
        }

        // Turn blocks back into string
        std::string outputString = BlockToString(inputBlocks);
        
        // Print Block Swapped results
        std::cout << std::setfill(' ');
        std::cout << std::setw(labelWidth) << std::left << "Block Swapped: ";
        PrintResults(outputString);

        // XOR strings together and trim as needed
        outputString = XOR(outputString, keyContent);

        // Print XOR results
        std::cout << std::setfill(' ');
        std::cout << std::setw(labelWidth) << std::left << "XOR results: ";
        PrintResults(outputString);
        
        // Remove padding from XOR results
        RemovePadding(outputString);

        // Print outputString minus padding
        std::cout << std::setfill(' ');
        std::cout << std::setw(labelWidth) << std::left << "output w/o pad: ";
        PrintResults(outputString);

        // Create output file and copy string to file
        CreateOutputFile(outputFileLocation, outputString);
    }
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
// Remove padding as needed (to original string)
void Block::RemovePadding(std::string& input) {
    // Start from the end of the string and check for padding
    while (!input.empty() && input.back() == '\x81') {
        input.pop_back();
    }
}
// Create vectors of 16 byte blocks
std::vector<std::vector<char>> Block::CreateBlocks(const std::string& inputString) {
    std::vector<std::vector<char>> returnVector;

    size_t blockSize = 16;
    size_t inputStringSize = inputString.size();
    size_t numberOfBlocks = ((inputStringSize - 1) / blockSize) + 1;

    returnVector.resize(numberOfBlocks);
    
    for (size_t i = 0; i < numberOfBlocks; i++) {
        returnVector[i].resize(blockSize);
    }

    for (size_t i = 0; i < inputStringSize; i++ ) {
        returnVector[i / blockSize][ i % blockSize] = inputString[i];
    }

    return returnVector;
};
// Convert block back to string
std::string Block::BlockToString(const std::vector<std::vector<char>>& inputBlocks) {
    std::string returnString;

    for (const auto& block : inputBlocks) {
        for (char byte : block) {
            returnString += static_cast<char>(byte);
        }
    }

    return returnString;
};

// ALGORITHM FUNCTIONS
// Encrypt swap
std::vector<char> Block::BlockSwapAlgorithm(std::vector<char>& inputBlock, const std::string& keyContent) {
    int start = 0;
    int end = static_cast<int>(inputBlock.size() - 1);

    while (start < end) {
        // Calculate modulo of ASCII
        int modulo = keyContent[start] % 2;
        if (modulo == 1) {
            SwapIndices(inputBlock, start, end);
            end--;
        }
        // Update pointer
        start++;
    }

    return inputBlock;
};
// Swaps values at indices provided
void Block::SwapIndices(std::vector<char>& inputBlock, int start, int end) {
    char newStartValue = inputBlock[end];
    inputBlock[end] = inputBlock[start];
    inputBlock[start] = newStartValue;
};

// HELPER PRINT FUNCTIONS
// Print block
void Block::PrintBlocks(const std::vector<std::vector<char>>& blocks) {
    int blockNumber = 0;
    
    for (const auto& block : blocks) {
        std::cout << "Block " << blockNumber++ << std::endl;
        if (block.size() != 16) {
            std::cout << "Block only has " << block.size() << " elements" << std::endl;
        }

        // Print each byte in the block
        for (size_t i = 0; i < block.size(); ++i) {
            
            std::cout << (block[i]);
        }
        std::cout << std::endl;
    }
}
// Print string
void Block::PrintString(const std::string& string) {
    std::cout << string << std::endl;
};