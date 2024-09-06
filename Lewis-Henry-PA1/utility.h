#ifndef UTILITY_H
#define UTILITY_H

#include <string>

//Validate inputs
void ValidateAll(const int, const std::string&, const std::string&, const std::string&, const std::string&, const std::string&);
void ValidateArgumentCount(const int);
void ValidateCipherType(const std::string&);
void ValidateModeOfOperation(const std::string&);

//Read & output file
std::string FileToString(const std::string&, bool);
void CreateOutputFile(const std::string&, const std::string&);

//XOR function & adjust string length
std::string XOR(const std::string&, const std::string&);
void AdjustStringLength(std::string&, size_t);

//Ciphers
void StartCipher(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&);

#endif // UTILITY_H
