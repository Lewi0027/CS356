#ifndef UTILITY_H
#define UTILITY_H

#include <string>

//Validate inputs
void ValidateAll(const int, const std::string&, const std::string&, const std::string&, const std::string&, const std::string&);
void ValidateArgumentCount(const int);
void ValidateCipherType(const std::string&);
void ValidateModeOfOperation(const std::string&);

//Read file
std::string FileToString(const std::string&, bool);

//Ciphers
void StartCipher(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&);

#endif // UTILITY_H
