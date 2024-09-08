#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "block.h"
#include "stream.h"
#include "utility.h"

// Print binary data
void ShowBinaryFileContent(const std::string& fileName) {
    std::ifstream file(fileName, std::ios::binary);

    if (!file) {
        std::cerr << "Failed to open the file: " << fileName << std::endl;
        return;
    }

    char byte;
    while (file.get(byte)) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << (static_cast<unsigned int>(byte) & 0xff) << " ";
    }

    file.close();
    std::cout << std::endl;
}

int main(int argc, char *argv[]) {

    StartCipher(argc, argv[1], argv[2], argv[3], argv[4], argv[5]);

    // ShowBinaryFileContent(argv[3]);
    // std::cout << "You made it to the end!\n";

    return 0;
}
