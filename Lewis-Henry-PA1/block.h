#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <vector>

class Block {
    public:
    Block(const std::string&, const std::string&, const std::string&, const std::string&);

    std::string PadString(const std::string&);
    std::vector<std::vector<uint8_t>> CreateBlocks(const std::string&);
    std::string BlockToString(const std::vector<std::vector<uint8_t>>&, size_t);
    
    void PrintBlocks(const std::vector<std::vector<uint8_t>>&);
    void PrintString(const std::string&);

    std::vector<uint8_t> BlockSwapForward(const std::vector<uint8_t>&);
    std::vector<uint8_t> BlockSwapReverse(const std::vector<uint8_t>&);
};

#endif // BLOCK_H
