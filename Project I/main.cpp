#include <iostream>
#include "xml_validator.h"

int main() {

    char xmlfilename[100] = "datasets/dataset02.xml";

    //std::cin >> xmlfilename;  // entrada
    
    std::cout << xmlValidator(xmlfilename) << std::endl;

    return 0;
}