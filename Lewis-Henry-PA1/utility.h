#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include <iomanip>
#include <sstream>

// MASTER
void StartCipher(int, const std::string&, const std::string&, const std::string&, const std::string&, const std::string&);
void EndSequence();

// VALIDATORS
void ValidateAll(const int, const std::string&, const std::string&, const std::string&, const std::string&, const std::string&);
void ValidateArgumentCount(const int);
void ValidateCipherType(const std::string&);
void ValidateModeOfOperation(const std::string&);
void ValidateFileExists(const std::string&, const std::string&, bool);
void ValidateFileContents(const std::ifstream&, const std::string&);

// STRING & OUTPUT FUNCTIONS
std::string FileToString(const std::string&, bool);
void AdjustStringLength(std::string&, size_t);
std::string XOR(const std::string&, const std::string&);
void CreateOutputFile(const std::string&, const std::string&);
void CreateOutputFile(const std::string&);
void PrintResults(const std::string&);

#endif // UTILITY_H
