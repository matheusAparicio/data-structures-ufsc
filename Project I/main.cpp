#include <iostream>
#include "xml_validator.h"

int main() {

    char xmlfilename[100] = "datasets/dataset06.xml";

    //std::cin >> xmlfilename;  // entrada
    
    std::cout << xmlValidator(xmlfilename) << std::endl;

    std::cout << xmlfilename << std::endl;  // esta linha deve ser removida

    return 0;
}