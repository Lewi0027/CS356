#include <iostream>
#include <fstream>
#include <string>
#include "block.h"
#include "stream.h"
#include "utility.h"


int main(int argc, char *argv[]) {

    //Validate command line arguments
    ValidateAll(argc, argv[1], argv[2], argv[3], argv[4], argv[5]);

    StartCipher(argv[1], argv[2], argv[3], argv[4]);
    
    // std::cout << "You made it to the end!\n";

    return 0;
}
