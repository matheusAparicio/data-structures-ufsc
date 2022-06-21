#include <iostream>
#include "xml_component_counter.h"

int main() {

    char fileName[100] = "datasets/dataset01.xml";

    // std::cin >> xmlfilename;  // entrada
    
    xmlComponentCounter(fileName);

    return 0;
}