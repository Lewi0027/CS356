#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <vector>

class Block {
    public:
    // CONSTRUCTOR (Does everything)
    Block(const std::string&, const std::string&, const std::string&, const std::string&);

    // PAD & BLOCK FUNCTIONS
    std::string PadString(const std::string&);
    void RemovePadding(std::string&);
    std::vector<std::vector<char>> CreateBlocks(const std::string&);
    std::string BlockToString(const std::vector<std::vector<char>>&);

    // ALGORITHM FUNCTIONS
    std::vector<char> BlockSwapAlgorithm(std::vector<char>&, const std::string&);
    void SwapIndices(std::vector<char>&, int, int);

    // HELPER PRINT FUNCTIONS
    void PrintBlocks(const std::vector<std::vector<char>>&);
    void PrintString(const std::string&);
};

#endif // BLOCK_H
