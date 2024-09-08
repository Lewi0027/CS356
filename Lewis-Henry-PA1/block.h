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
    std::vector<std::vector<uint8_t>> CreateBlocks(const std::string&);
    std::string BlockToString(const std::vector<std::vector<uint8_t>>&, size_t);

    // ALGORITHM FUNCTIONS
    std::vector<uint8_t> BlockSwapForward(const std::vector<uint8_t>&);
    std::vector<uint8_t> BlockSwapReverse(const std::vector<uint8_t>&);

    // HELPER PRINT FUNCTIONS
    void PrintBlocks(const std::vector<std::vector<uint8_t>>&);
    void PrintString(const std::string&);
};

#endif // BLOCK_H
