#ifndef BLOCK_H
#define BLOCK_H

#include <string>

class Block {
    public:
    Block(const std::string&, const std::string&, const std::string&, const std::string&);

    std::string PadString(const std::string&);
    void RemoveEOFByte(std::string&);

    std::string ByteSwapForward(const std::string&);
    std::string ByteSwapReverse(const std::string&); 

};

#endif // BLOCK_H
