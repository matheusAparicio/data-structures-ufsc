#include <iostream>
#include "xml_component_counter.h"

int main() {

    char fileName[100];

    std::cin >> fileName;  // entrada
    
    xmlComponentCounter(fileName);

    return 0;
}