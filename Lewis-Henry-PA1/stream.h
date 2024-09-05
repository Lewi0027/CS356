#ifndef STREAM_H
#define STREAM_H
#include <string>

class Stream {
    public:
    Stream(const std::string&, const std::string&, const std::string&);
    //Get the inputFile and keyfile
    
    std::string StreamXOR(const std::string&, const std::string&);
    //Xor them and turn the results into a new file
    
    void CreateOutputFile(const std::string&, const std::string&);
    //create output file

};

#endif // STREAM_H